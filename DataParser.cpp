#include <fstream>
#include "DataParser.h"
#include "EmptyFileexept.h"


bool DataParser::isErrors() const{
    if(is_errors) return true;
    else return false;
}

void DataParser::LineSecluder(const std::vector<std::string> &_path_bundle) {
    for(const auto& elem : _path_bundle) {
            std::string curr_file_name = elem.substr(elem.find_last_of('\\')+1, std::string::npos);
            int row_counter=1;
            std::string line;
            std::string range_line;
            std::ifstream read_file;
            read_file.open(elem, std::ios::in);
            std::getline(read_file, range_line);
            if(range_line.empty())
            {
                read_file.close();
                throw EmptyFileException("File "+curr_file_name+" in given directory is empty");
            }
            int range = std::stoi(range_line);
            for (int i = 0; i < range; ++i) {
                std::getline(read_file,line);
//                if(line.empty()) {
//                    read_file.close();
//                    throw EmptyFileException("File "+curr_file_name+" has less rows than specified");
//                }
                line.insert(0,fnameseparator);
                line.insert(0, std::to_string(row_counter));
                line.insert(0,fnameseparator);
                line.insert(0,curr_file_name);
                row_counter++;
                        try { OperateLine(line); }
                        catch (const FileContentException& ex) {
                            std::cerr << ex.whatHappened();
                        }
                        catch (const EmptyFileException& ex) {
                            std::cerr << ex.what();
                        }
                    line.clear();
            }
            std::getline(read_file, line);
            if(!line.empty()) {
                read_file.close();
                throw EmptyFileException("File "+elem.substr(elem.find_last_of('\\')+1, std::string::npos)+" has more rows than specified");
            }
            read_file.close();
    }

}

void DataParser::OperateLine(std::string& line){
    int pos;
    std::string curr_file = line.substr(0, line.find_first_of(fnameseparator));
    line.erase(0,line.find_first_of(fnameseparator)+1);
    std::string row = line.substr(0, line.find_first_of(fnameseparator));
    line.erase(0,line.find_first_of(fnameseparator)+1);
    pos = line.find_last_of(separator);
    if(pos==std::string::npos){
        is_errors=true;
        throw EmptyFileException("File "+curr_file+" has empty "+row+" line");
    }
    else {
        if (line.substr(pos + 1, std::string::npos) == budjet_identifier) {
            line.erase(pos + 1, std::string::npos);
            Student one;
            std::string piece;
            std::stringstream s(line);
            std::getline(s, piece, ',');
            if (piece.empty()) {
                piece = '-';
                line.insert(0, piece);
                is_errors = true;
                throw FileContentException(curr_file, std::stoi(row));
            }
            one.name = piece;
            piece.clear();
            while (std::getline(s, piece, ',')) {
                one.study_score += std::stod(piece);
                one.subj_numb++;
            }
            data.push_back(one);
        } else if(line.substr(pos + 1, std::string::npos) != contract_identifier)
        {
            is_errors=true;
            throw FileContentException(curr_file,std::stoi(row),"Unspecified Контрактник or specified wrong");
        }
    }
}

std::vector<Student> DataParser::GetData() const{
    return data;
}