#ifndef INC_2_PARSER__EMPTYFILEEXEPT_H
#define INC_2_PARSER__EMPTYFILEEXEPT_H

#include <stdexcept>
#include <string>

class EmptyFileException: public std::exception {
    std::string message;
public:
    explicit EmptyFileException(const std::string& caution) {
        message=caution;
    }
        const char* what() const noexcept override {
            return message.c_str();}
};

#endif //INC_2_PARSER__EMPTYFILEEXEPT_H
