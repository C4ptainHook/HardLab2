#ifndef INC_2_PARSER__CSVEXCEPT_H
#define INC_2_PARSER__CSVEXCEPT_H
#include <string>
#include <stdexcept>

struct FileErr{
    std::string filename, message;
    int row_num;
};

class FileContentException: public std::exception{
    FileErr err;
public:
    FileContentException(const std::string& _fName, int _r, const std::string& _mes=" ")
    {
        err.filename=_fName;
        err.row_num=_r;
        err.message = _mes;
    }
    const std::string whatHappened () const{
        std::string subj = "\n---Error in "+err.filename;
        subj+=" "+std::to_string(err.row_num)+"-row\n";
        if(err.message!=" "){subj+=err.message+'\n';}
        return subj;
    }
};

#endif //INC_2_PARSER__CSVEXCEPT_H
