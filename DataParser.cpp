#include <fstream>
#include "DataParser.h"

 DataParser::DataParser(const std::string& _external_path) {
    filename=_external_path;
}

void DataParser::LineSecluder() {
    std::string line;
    std::ifstream read_file;
    int pos;
    read_file.open(filename, std::ios::in);
    while (std::getline(read_file, line))
    {
      pos = line.find_last_of(separator);
      if(line.substr(pos+1, std::string::npos)==identifier)
      {
          line.erase(pos+1, std::string::npos);
          try{OperateLine(line);}
          catch(const FileContentException& ex) {
              std::cerr<<ex.whatHappened();
          }
      }
      line.clear();
    }
    read_file.close();
    std::remove(filename.c_str());
}

void DataParser::OperateLine(std::string& line){
    std::string curr_file = line.substr(0, line.find_first_of(fnameseparator));
    line.erase(0,line.find_first_of(fnameseparator)+1);
    std::string row = line.substr(0, line.find_first_of(fnameseparator));
    line.erase(0,line.find_first_of(fnameseparator)+1);
    Student one;
    std::string piece;
    std::stringstream s(line);
    std::getline(s, piece, ',');
    if (piece.empty()) {
        piece = '-';
        line.insert(0,piece);
        throw FileContentException(curr_file, 1, std::stoi(row));
    }
    one.name = piece;
    piece.clear();
    while (std::getline(s, piece, ',')) {
        one.study_score += std::stod(piece);
        one.subj_numb++;
    }
    data.push_back(one);
}

void DataParser::ParseData() {
    LineSecluder();
}

std::vector<Student> DataParser::GetData() const{
    return data;
}