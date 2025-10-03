#ifndef WORDCOUNTER_HPP
#define WORDCOUNTER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "StringHelper.hpp"

class wc_error : public std::exception {
 private:
    std::string error_message;
 public:
    wc_error(const std::string &message): error_message(message) {}
    const char* what() const noexcept;
};

class WordCounter {
 public:
    explicit WordCounter(std::vector<std::string> words);

    void Calculate();

    std::vector <StringHelper::WordInformation> GetCalculatedWords();

    ~WordCounter() = default;

 private:

    std::vector <std::string> _words;
    std::map <std::string, size_t> counter_of_words;
    std::vector <StringHelper::WordInformation> calculated_words;
};

WordCounter::WordCounter(std::vector<std::string> words) {
    _words = words;
}

const char* wc_error::what() const noexcept{
    return error_message.c_str();
}

void WordCounter::Calculate() {
    StringHelper::StringHelper *helper = StringHelper::StringHelper::getInstance();

    for (const auto &word : _words) {
        helper->UpdateLargestWordSize(std::max(word.size(), helper->GetLargestWordSize()));
        counter_of_words[word]++;
    }

    for (const auto &x : counter_of_words) {
        std::string word = x.first;
        word.front() = toupper(static_cast<unsigned char>(word.front()));
        calculated_words.push_back({word, x.second, x.second / (double)_words.size()});
    }

    sort(calculated_words.begin(), calculated_words.end(),
    [](const StringHelper::WordInformation &a, const StringHelper::WordInformation &b) {
        return a.count > b.count;
    });
}

std::vector <StringHelper::WordInformation> WordCounter::GetCalculatedWords() {
    return calculated_words;
}


#endif //WORDCOUNTER_HPP
