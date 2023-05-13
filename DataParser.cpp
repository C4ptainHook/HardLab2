#include "DataParser.h"

 DataParser::DataParser(const std::string& _external_path) {
    filename=_external_path;
}

void DataParser::LineSecluder() {
    std::string line;
    std::ifstream read_file;
    size_t pos;
    read_file.open(filename, std::ios::in);
    while (std::getline(read_file, line))
    {
      pos = line.find_last_of(separator);
      if(line.substr(pos+1, std::string::npos)==identifier)
      {
          line.erase(pos+1, std::string::npos);
          OperateLine(line);
      }
    }
}

void DataParser::OperateLine(std::string line){
    Student one;
    std::string piece;
    std::stringstream s(line);
    std::getline(s,piece,',');
    one.name=piece;
    piece.clear();
    while(std::getline(s,piece,',')){
    one.global_score += std::stod(piece);
    one.subj_numb++;
    }
}