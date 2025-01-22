#ifndef READER_CONFIGURATION_HPP
#define READER_CONFIGURATION_HPP

#include <string>
#include <vector>

class ReaderConfiguration {
 private:
    std::string inputPath;
    std::vector<std::string> configuration;
 public:
    ReaderConfiguration();
    ReaderConfiguration(const std::string& inputPath);
    std::string getInputPath() const;
    std::vector<std::string> getConfiguration() const;
    
    void setInputPath(const std::string& inputPath);

};

ReaderConfiguration::ReaderConfiguration() {
    inputPath = "";
    configuration = {};
}

ReaderConfiguration::ReaderConfiguration(const std::string& inputPath) {
    this->inputPath = inputPath;
    configuration = {};
}

#endif  // READER_CONFIGURATION_HPP
