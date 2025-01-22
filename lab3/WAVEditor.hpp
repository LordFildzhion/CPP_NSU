#ifndef WAV_EDITOR_HPP
#define WAV_EDITOR_HPP

#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace WAV {
    struct WAVHeader {
        int32_t chunkId;
        size_t chunkSize;
        int32_t format;
        int32_t subchunk1Id;
        size_t subchunk1Size;
        uint16_t audioFormat;
        uint16_t countChannels;
        size_t sampleRate;
        uint64_t byteRate;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
        int32_t subchunk2Id;
        size_t subchunk2Size;
    };

    namespace Constants {
        const int8_t CHANNELS_COUNT = 1;
        const int8_t AUDIO_FORMAT = 1;
        const int8_t BITS_PER_SAMPLE = 16;
        const int8_t BYTES_PER_SAMPLE = BITS_PER_SAMPLE / 8;
        const uint16_t SAMPLE_RATE = 44100;
        const char RIFF[5] = "RIFF";
        const char FMT[5] = "fmt ";
        const char WAVE[5] = "WAVE";
        const int32_t RIFF_POINTER = *((int*)RIFF);
        const int32_t FMT_POINTER = *((int*)FMT);
        const int32_t WAVE_POINTER = *((int*)WAVE);

        const uint32_t HEADER_SIZE = sizeof(WAVHeader);
    }

    enum class FileOptions {
        input,
        output,
        empty
    };
}

class WAVEditor {
 private:
    void checkFileFormat();
    void calculateLength();

    std::string filename;
    std::fstream file;
    WAV::WAVHeader header;
    WAV::FileOptions option;
    size_t length;

 public:
    WAVEditor(const std::string& filename, WAV::FileOptions option = WAV::FileOptions::empty);
    WAVEditor() = delete;
    WAVEditor(const WAVEditor&) = delete;
    WAVEditor& operator=(const WAVEditor&);
    ~WAVEditor();

    void openFile(WAV::FileOptions option = WAV::FileOptions::empty);
    void closeFile();

    void printHeader(const WAV::WAVHeader* head);

    void readHeader();

    void writeHeader();

    void readData(std::vector<int16_t>& data);

    void writeData(const std::vector<int16_t>& data);

    size_t getLength();

    void goToSecond(size_t second);

    void readNextSecond(int16_t* second, size_t secondPosition);
};

WAVEditor::WAVEditor(const std::string& filename, WAV::FileOptions option) : filename(filename), option(option) {
    if (option == WAV::FileOptions::empty) {
        length = 0;
        return;
    }
    openFile(option);
    std::string str;
    std::getline(file, str);
    file.close();

    if (str.size() < sizeof(WAV::WAVHeader)) {
        throw std::runtime_error("File is too small");
    }

    header = *(WAV::WAVHeader*)str.c_str();
    checkFileFormat();
    calculateLength();
}

WAVEditor::~WAVEditor() {
    closeFile();
}

void WAVEditor::calculateLength() {
    int firstEightBytes = 8;
    int bytes = (header.chunkSize + firstEightBytes) - WAV::Constants::HEADER_SIZE;
    length = bytes / header.sampleRate / 2;
}

size_t WAVEditor::getLength() {
    calculateLength();
    return length;
}

void WAVEditor::readHeader() {
    file.read(reinterpret_cast<char*>(&header), sizeof(WAV::WAVHeader));
}

void WAVEditor::readNextSecond(int16_t* second, size_t secondPosition) {
    openFile(WAV::FileOptions::input);
    goToSecond(secondPosition);
    file.read(reinterpret_cast<char*>(second), header.byteRate);
    closeFile();
}

void WAVEditor::readData(std::vector<int16_t>& data) {
    openFile(WAV::FileOptions::input);
    file.seekg(WAV::Constants::HEADER_SIZE);
    size_t size = header.subchunk2Size / WAV::Constants::BYTES_PER_SAMPLE;
    data.resize(size);
    file.read(reinterpret_cast<char*>(data.data()), header.subchunk2Size);
    closeFile();
}

void WAVEditor::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

void WAVEditor::printHeader(const WAV::WAVHeader* head) {
    file.write((char*)head, sizeof(WAV::WAVHeader));
}

void WAVEditor::openFile(WAV::FileOptions option) {
    if (option == WAV::FileOptions::empty) {
        return;
    }
    file.open(filename, std::ios::binary | (option == WAV::FileOptions::input ? std::ios::in : std::ios::out));
    if (!file.is_open()) {
        throw std::runtime_error("Can't open file");
    }
}

void WAVEditor::checkFileFormat() {
    if (header.bitsPerSample != WAV::Constants::BITS_PER_SAMPLE
    || header.audioFormat    != WAV::Constants::AUDIO_FORMAT
    || header.countChannels  != WAV::Constants::CHANNELS_COUNT
    || header.sampleRate     != WAV::Constants::SAMPLE_RATE
    || header.chunkId        != WAV::Constants::RIFF_POINTER
    || header.format         != WAV::Constants::WAVE_POINTER
    || header.subchunk1Id    != WAV::Constants::FMT_POINTER) {
        throw std::runtime_error("Unsupported file format");
    }
}

void WAVEditor::writeHeader() {
    file.write(reinterpret_cast<char*>(&header), sizeof(WAV::WAVHeader));
}

void WAVEditor::goToSecond(size_t second) {
    if (option == WAV::FileOptions::input) {
        file.seekp(header.byteRate * second + WAV::Constants::HEADER_SIZE + header.subchunk2Size);
    }
    else {
        file.seekg(header.byteRate * second + WAV::Constants::HEADER_SIZE + header.subchunk2Size);
    }

    if (file.fail()) {
        throw std::runtime_error("Can't move to the second");
    }
}

#endif  // WAV_EDITOR_HPP
