
#ifndef INC_2_PARSER__DATAPARSER_H
#define INC_2_PARSER__DATAPARSER_H

#pragma once
#include "Students.h"
#include "CSVexcept.h"
#include <sstream>
#include <vector>
#include <cctype>

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ',';
    std::string filename;
    std::vector<Student> data;
    void LineSecluder();
    void OperateLine(std::string&);
public:
    std::vector<Student> GetData() const;
    DataParser(const std::string&);
    void ParseData();
};

#endif //INC_2_PARSER__DATAPARSER_H