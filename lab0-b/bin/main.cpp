#include <iostream>

#include "lib/word_counter/word_counter.hpp"


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "ERROR: main.cpp: check on count arguments: "
                  << (argc < 3 ? "More arguments are needed"
                               : "Fewer arguments are needed");
        return 0;
    }

    word_counter wc(argv[1], argv[2]);

    try
    {
        wc.read();
        wc.write();
    }
    catch(const std::string& error)
    {
        std::cerr << error << '\n';
    }

    return 0;
}