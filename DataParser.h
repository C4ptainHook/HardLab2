#include "Directory.h"
#include "Students.h"
#include <sstream>

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ';';
    std::string filename;
    std::vector<Student> data;
    void LineSecluder();
    void OperateLine(std::string);
protected:
    std::vector<Student> GetData() const;
public:
    DataParser(const std::string&);
    void ParseData();
};

