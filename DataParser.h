#pragma once
#include "Directory.h"
#include "Students.h"
#include <sstream>

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ';';
    std::string filename;
    std::vector<Student> data;
    void LineSecluder();
    void OperateLine(const std::string&);
public:
    std::vector<Student> GetData() const;
    DataParser(const std::string&);
    void ParseData();
};

