#include "Directory.h"
#include <sstream>
struct Student {
    std::string name;
    double study_score;
    int subj_numb;
    Student():study_score(0),subj_numb(0){}
};

class DataParser {
    const std::string identifier = "FALSE";
    const char separator = ';';
    std::string filename;
    std::vector<Student> data;
    void LineSecluder();
    void OperateLine(std::string);
public:
    DataParser(const std::string&);
    void ParseData();
};

