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
          LineProcessing(line);
      }
    }
}

void DataParser::LineProcessing(std::string line){
    std::string word;
    std::stringstream s(line);
    std::getline(s,word,',');

}

void DataParser::AddToData() {

}