#include <iostream>

#include "lib/word_counter/word_counter.hpp"


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "ERROR: main.cpp: check on count arguments: "
                  << (argc < 3 ? "More arguments are needed (3)"
                               : "Fewer arguments are needed (3)")
                  << std::endl << "program.exe input_file.txt output_file.csv";
        return 0;
    }

    word_counter wc(argv[1], argv[2]);

    try
    {
        wc.read();
        wc.calculate();
        wc.write();
    }
    catch(const wc_error error)
    {
        std::cerr << error.what() << '\n';
    }

    return 0;
}

// Добавить классы reader/writer
// Изменить функцию calculate_and_write
