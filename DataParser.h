
#ifndef INC_2_PARSER__DATAPARSER_H
#define INC_2_PARSER__DATAPARSER_H

#pragma once
#include "Students.h"
#include "CSVexcept.h"
#include <sstream>
#include <vector>
#include <cctype>

class DataParser {
    const std::string budjet_identifier = "FALSE";
    const std::string contract_identifier = "TRUE";
    const char separator = ',';
    const char* fnameseparator = "|";
    const int coloumn_limit = 5;
    bool is_errors=false;
    std::vector<Student> data;
    void OperateLine(std::string&);
    bool hasSymbols(std::string&);
public:
    void LineSecluder(const std::vector<std::string> &_path_bundle);
    std::vector<Student> GetData() const;
    bool isErrors() const;
};

#endif //INC_2_PARSER__DATAPARSER_H