#include "Directory.h"
#include <sstream>
struct Student {
    std::string name;
    double global_score;
    int subj_numb;
};

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ';';
    std::string filename;
    std::vector<Student> data;
    void LineSecluder();
    void LineProcessing(std::string);
    void AddToData();
public:
    DataParser(const std::string&);
    void ParseData();

};

