#ifndef INC_2_PARSER__PRINTER_H
#define INC_2_PARSER__PRINTER_H


#pragma once
#include <ostream>
#include <fstream>
#include <cmath>
#include "Counter.h"

namespace Printer {
void Write_Result_toFile(const Counter& parsed, const char* path) {
    std::string converter = path;
    converter+="\\Parser_Folder";
    converter+="\\Parsed.csv";
    std::ofstream write_file(converter);
    write_file<<parsed;
    write_file.close();
}
}

#endif //INC_2_PARSER__PRINTER_H