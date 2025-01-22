#ifndef LAB3_CONSTS_H
#define LAB3_CONSTS_H

#include<string>
#include<vector>
#include<set>

namespace WAV {
    struct WAVHeader {
        int RIFFId;
        int chunkDataSize;
        int WAVEId;
        int FMTId;
        int subChunkDataSize;
        short compresionCode;
        short numberOfChanels;
        int sampleRate;
        int avBytesPerSec;
        short blockAlign;
        short bitsPerSample;
        char LISTId[4];
        int subChunk2DataSize;
        char INFOId[4];
        int INFOVal;
    };

    namespace Consts {
        static const short bitsPerSample = 16;
        static const int sampleRate = 44100;
        static const short chanels = 1;
        static const short PCM = 1;
        static const char RIFF[5] = "RIFF";
        static const char FMT[5] = "fmt ";
        static const char WAVE[5] = "WAVE";
        static const int RIFFId = *((int*)RIFF);
        static const int FMTId = *((int*)FMT);
        static const int WAVEId = *((int*)WAVE);
        static const int headerSize = sizeof(WAVHeader);
        enum class FileOptions {
            in,
            out,
            empty,
        };
    }
}

namespace Converters {
    namespace Consts {
        static const int samplesInSec = WAV::Consts::sampleRate;
        static const short int zeroValue = 0;
        static const std::set< std::string> comandsNames =
        {
            "mute", "mix", "overlap"
        };
    }
    using Times = std::vector<int>;
    using samples = std::vector<short*>;
}

namespace Config {
    namespace Consts {
        static const int fitstElInd = 0;
        static const char commentDelim = '#';
        static const std::string endOfFileLine = "";
    }
}

namespace ProcessManager {
    using fileNames = std::vector<std::string>;
    namespace Consts {
        static const int outputInd = 0;
        static const int inputInd = 1;
        static const char filePointer = '$';
        static const int indPosInPtr = 1;
        static const int firstFileInd = 0;
        static const int firstSmplInd = 0;
        static const int zeroSecond = 0;
        static const int secondFileInd = 1;
        static const int secondSmplInd = 1;
    }
}

#endif //LAB3_CONSTS_H
