#ifndef STRINGHELPER_HPP
#define STRINGHELPER_HPP


#include <string>
#include <vector>
#include <algorithm>

namespace StringHelper
{
    static const size_t PRESICTION_VALUE = 6;
    static const size_t HUNDRED_PERCENTS = 100;

    struct WordInformation {
        std::string word;
        size_t count;
        double percents;
    };

    class StringHelper {
     public:
        static StringHelper* getInstance();

        void Parser(std::string &word);

        size_t GetLargestWordSize();
        void UpdateLargestWordSize(size_t new_size);

     private:

        static size_t largest_word_size;

        static StringHelper* instance;

     private:
        StringHelper() = default;
        ~StringHelper();
    };

}

StringHelper::StringHelper* StringHelper::StringHelper::getInstance() {
    if (instance == nullptr) {
        instance = new StringHelper();
    }

    return instance;
}

size_t StringHelper::StringHelper::GetLargestWordSize() {
    return largest_word_size;
}

void StringHelper::StringHelper::UpdateLargestWordSize(size_t new_size) {
    largest_word_size = new_size;
}

void StringHelper::StringHelper::Parser(std::string &word) {
    for (size_t i = 0; i < word.size(); i++) {
        if (isalnum(static_cast <unsigned char> (word.at(i)))) {
            word.at(i) = std::tolower(word.at(i));
            continue;
        }

        word.erase(i, 1);
    }
}

StringHelper::StringHelper::~StringHelper() {
    delete instance;
}

StringHelper::StringHelper* StringHelper::StringHelper::instance = nullptr;

size_t StringHelper::StringHelper::largest_word_size = 0;

#endif  // STRINGHELPER_HPP
