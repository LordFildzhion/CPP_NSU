#ifndef LAB3_CONFIGREADER_H
#define LAB3_CONFIGREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include "Exceptions.h"
#include "Consts.h"

namespace Config {

    class CnfReader {
    public:
        CnfReader() = delete;

        CnfReader(std::string path);

        ~CnfReader();

        std::string getNewComand();

    private:
        std::fstream config;
    };
}


namespace Config {

    CnfReader::CnfReader(std::string path) {
        config.open(path, std::ios::in | std::ios::binary);
        if (config.fail()) {
            throw Exceptions::CanNotOpenFile();
        }
    }

    std::string CnfReader::getNewComand() {
        std::string newLine = { Consts::commentDelim };
        while (newLine[Consts::fitstElInd] == Consts::commentDelim || newLine.empty()) {
            if (config.eof()) {
                return Consts::endOfFileLine;
            }
            std::getline(config, newLine);
        }
        return newLine;
    }

    CnfReader::~CnfReader() {
        config.close();
    }

}

#endif //LAB3_CONFIGREADER_H
