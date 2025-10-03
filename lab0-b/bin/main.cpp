/*

Данная программа реализует подсчёт слов в файле "input.txt"
Подсчитанная информация выводится в файл "output.csv" в порядке возрастания количества слов.
Формат итоговой таблицы:

Слово | Количество | Процентное соотношение
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
******|************|***********************
*/


#include <iostream>
#include <vector>


#include "StringHelper.hpp"
#include "WordCounter.hpp"
#include "Reader.hpp"
#include "Writer.hpp"

static const size_t REQUIRED_NUMBER_OF_ARGUMENTS = 3;

class MainCountArgumentsException : public std::exception {
 private:
    std::string error_message;

 public:
    explicit MainCountArgumentsException(const std::string &message) : error_message(message) {}
    const char* what() const noexcept;
};


int main(int argc, char* argv[]) {
    if (argc != REQUIRED_NUMBER_OF_ARGUMENTS) {
        throw MainCountArgumentsException("ERROR: main.cpp: check on count arguments");
    }
    StringHelper::StringHelper *helper = StringHelper::StringHelper::getInstance();

    Reader<std::string> reader(argv[1]);
    reader.ReadElements();
    std::vector<std::string> words = reader.GetElements();

    std::cout << "Words in text: " << words.size() << std::endl;

    WordCounter counter(words);
    counter.Calculate();
    std::vector <StringHelper::WordInformation> calculated_words = counter.GetCalculatedWords();
    
    std::cout << "Different words: " << calculated_words.size() << std::endl;

    Writer <StringHelper::WordInformation> writer(argv[2]);
    writer.Write(calculated_words);

    return 0;
}


const char* MainCountArgumentsException::what() const noexcept {
    return error_message.c_str();
}
