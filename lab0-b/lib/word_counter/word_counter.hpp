#ifndef WORD_COUNTER_HPP
#define WORD_COUNTER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <tuple>


class wc_error : public std::exception {
 private:
    std::string error_message;
 public:
    wc_error(const std::string &message): error_message(message) {}
    const char* what() const noexcept;
};

class word_counter {

 private:
    void parser(std::string &word);

 public:
    explicit word_counter(std::string input_filename = "in.txt",
                          std::string output_filename = "out.csv");

    virtual void read();

    void calculate();

    virtual void write();

    ~word_counter();

 private:
    struct word_information {
        std::string word;
        size_t count;
        double percents;
    };

    // Add comments
    static const size_t PRESICTION_VALUE = 6;

    std::ifstream in;
    std::ofstream out;
    std::vector <std::string> words;
    std::map <std::string, size_t> counter_of_words;
    std::vector<word_information> word_list;
};

#endif //WORD_COUNTER_HPP