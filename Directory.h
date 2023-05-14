
#ifndef INC_2_PARSER__DIRECTORY_H
#define INC_2_PARSER__DIRECTORY_H


#pragma once
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <sys/stat.h>


namespace Directory {

    std::vector<std::string> GetPath(const char* path)
    { std::vector<std::string> path_bundle;
        for(const auto& entry : std::filesystem::directory_iterator(path)){
            path_bundle.push_back(entry.path().string());
        }
        return path_bundle;
    }

    std::string DirProcess(const std::vector<std::string> &_path_bundle, const char* path)
    {
        std::string converter = path;
        converter+="\\Parser_Folder";
        if(!std::filesystem::is_directory(converter)) {
        std::filesystem::create_directory(converter);
        }
        converter+="\\Newfile.csv";
        std::string curr_line;
        std::string range_line;
        for(const auto& elem : _path_bundle)
        {if(elem.substr(elem.length()-4)==".csv") {
                std::ifstream read_file(elem);
                std::ofstream write_file;
                write_file.open(converter, std::ios::out | std::ios::app);
                std::getline(read_file, range_line);
                int range = std::stoi(range_line);
                for (int i = 0; i < range; ++i) {
                    std::getline(read_file, curr_line);
                    write_file << curr_line << std::endl;
                }
                read_file.close();
                write_file.close();
            }
        }
        return converter;
    }
}

#endif //INC_2_PARSER__DIRECTORY_H