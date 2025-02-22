#include <iomanip>

#include "word_counter.hpp"


const char* wc_error::what() const noexcept{
    return error_message.c_str();
}

word_counter::word_counter (std::string input_filename, std::string output_filename) {

    in.open(input_filename);
    if (!in.is_open()) {
        throw std::string{"ERROR: word_counter.cpp: Input file " + input_filename + " can't be open\n"};
    }

    out.open(output_filename);
    if (!out.is_open()) {
        throw std::string{"ERROR: word_counter.cpp: Output file " + output_filename + " can't be open\n"};
    }
}

void word_counter::parser(std::string &word) {
    for (size_t i = 0; i < word.size(); i++) {
            if (isalnum(static_cast<unsigned char>(word[i]))){
                word[i] = std::tolower(word[i]);
                continue;
            }

            word.erase(i, 1);
    }
}

void word_counter::read() {
    std::string str;

    while (in >> str) {
        parser(str);
        words.push_back(str);
    }
}

void word_counter::calculate() {
    size_t largest_word_size = 0;

    for (const auto &word : words) {
        largest_word_size = std::max(word.size(), largest_word_size);
        counter_of_words[word]++;
    }

    for (const auto &x : counter_of_words) {
        std::string word = x.first;
        word[0] = toupper(static_cast<unsigned char>(word[0]));
        word += std::string(largest_word_size - word.size(), ' ');
        word_list.push_back({word, x.second, x.second / (double)words.size()});
    }

    sort(word_list.begin(), word_list.end(),
    [](const word_information &a, const word_information &b) {
        return a.count > b.count;
    });
}

void word_counter::write() {
    for (const auto x : word_list) {
        out << x.word << " " << x.count << " "
        << std::setprecision(PRESICTION_VALUE) << x.percents * 100 << "%"
        << std::endl;
    }
}

word_counter::~word_counter() {
    in.close();
    out.close();
}


// Добавить exception под каждую ошибку
// Добавить multiset
// Добавить класс strings_helper (Capitalize, Align)
// Переделать на кэмэл кейс
// Переместить largest_word_size в writer
// HUNDRED_PERCENTS
