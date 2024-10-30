#include "./word_counter.hpp"
#include <iomanip>

void word_counter::parser(std::string &word) {
    for (size_t i = 0; i < word.size(); i++) {
            if (isalnum(word[i]))
                word[i] = std::tolower(word[i]);
            else
                word.erase(i, 1);
        }
}

void word_counter::reader() {
    std::string str;

    while (in >> str) {
        parser(str);
        words.push_back(str);
    }
}

void word_counter::calculate() {
    size_t largest_word_size = 0;
    size_t words_count = 0;

    for (auto &word : words) {
        largest_word_size = std::max(word.size(), largest_word_size);
        counter[word]++;
        words_count++;
    }

    for (auto &x : counter) {
        std::string word = x.first;
        word[0] = toupper(word[0]);
        word += std::string(largest_word_size - word.size(), ' ');
        word_list.push_back({word, x.second, x.second / (double)words_count});
    }

    sort(word_list.begin(), word_list.end(),
    [](word_information &a, word_information &b) {
        return a.count > b.count;
    });
}

void word_counter::writer() {
    for (auto x : word_list) {
        out << x.word << " " << x.count << " "
        << std::setprecision(6) << x.percents * 100 << "%"
        << std::endl;
    }
}