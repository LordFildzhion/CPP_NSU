#ifndef WRITER_HPP
#define WRITER_HPP


#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "StringHelper.hpp"

class WriterCantOpenFileException : std::exception {
 private:
    std::string error_message;

 public:
    explicit WriterCantOpenFileException(const std::string &message) : error_message(message) {}
    const char* what() const noexcept;
};

class WriterCantCloseFileException : std::exception {
 private:
    std::string error_message;

 public:
    explicit WriterCantCloseFileException(const std::string &message) : error_message(message) {}
    const char* what() const noexcept;
};

template <typename T>
class Writer {
 private:
    std::ofstream out;

    std::string OutputFileName_;

 public:
    Writer(std::string OutputFileName = "out.csv");
    Writer(char *OutputFileName = "out.csv");

    void Write(std::vector<T> writed_vector);

    ~Writer();
 private:
    void Align(std::string str, size_t required_width=0);
};

template <typename T>
Writer<T>::Writer(std::string OutputFileName) {
    OutputFileName_ = OutputFileName;

    out.open(OutputFileName);
    if (!out.is_open()) {
        throw WriterCantOpenFileException("ERROR: WordCounter.cpp: Output file " + OutputFileName_ + " can't be open\n");
    }
}

template <typename T>
Writer<T>::Writer(char *OutputFileName) {
    OutputFileName_ = OutputFileName;

    out.open(OutputFileName);
    if (!out.is_open()) {
        throw WriterCantOpenFileException("ERROR: WordCounter.cpp: Output file " + OutputFileName_ + " can't be open\n");
    }
}

template<>
void Writer <StringHelper::WordInformation>::Write(std::vector<StringHelper::WordInformation> writed_vector) {
    StringHelper::StringHelper *helper = StringHelper::StringHelper::getInstance();
    for (const auto &x : writed_vector) {
        out << x.word << " ";
        Align(x.word, helper->GetLargestWordSize());
        out << x.count << " ";
        out <<  std::setprecision(StringHelper::PRESICTION_VALUE) << x.percents * StringHelper::HUNDRED_PERCENTS << "%" << std::endl;
    }
}

template <typename T>
void Writer<T>::Write(std::vector<T> writed_vector) {
    for (const auto &x : writed_vector) {
        out << x << std::endl;
    }
}

template <typename T>
Writer<T>::~Writer() {
    out.close();
    if (out.is_open()) {
        throw WriterCantCloseFileException("ERROR: WordCounter.cpp: Output file " + OutputFileName_ + " can't be close\n");
    }
}

template <typename T>
void Writer<T>::Align(std::string str, size_t required_width) {
    for (int i = 0; i < required_width - str.size(); i++) {
        out << " ";
    }
}

const char* WriterCantOpenFileException::what() const noexcept {
    return error_message.c_str();
}

const char* WriterCantCloseFileException::what() const noexcept {
    return error_message.c_str();
}

#endif //WRITER_HPP
