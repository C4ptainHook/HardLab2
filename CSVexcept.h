#ifndef INC_2_PARSER__CSVEXCEPT_H
#define INC_2_PARSER__CSVEXCEPT_H
#include <string>
#include <stdexcept>

struct FileErr{
    std::string filename;
    int col_num=0;
};

class FileContentException: public std::exception{
    FileErr err;
public:
    FileContentException(const std::string& _fName, int _c)
    {
        err.filename=_fName;
        err.col_num=_c;;
    }
    const std::string whatHappened () const{
        std::string subj = "Error in "+err.filename;
        subj+= " in coloumn:"+std::to_string(err.col_num)+'\n';
        return subj;
    }
};

#endif //INC_2_PARSER__CSVEXCEPT_H
