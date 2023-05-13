#include "Directory.h"

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ';';
    std::string filename;
    std::vector<std::vector<std::string>> data;
    void LineSecluder();
    void LineProcessing(std::string);
    void AddToData();
public:
    DataParser(const std::string&);
    void ParseData();

};

