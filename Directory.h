
#ifndef INC_2_PARSER__DIRECTORY_H
#define INC_2_PARSER__DIRECTORY_H


#pragma once
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <sys/stat.h>
#include "EmptyFileexept.h"


namespace Directory {

    std::vector<std::string> GetPath(const char* path)
    { if(!std::filesystem::exists(path)){
        throw std::filesystem::filesystem_error("Path to files does not exist!",  path, std::error_code());
    }
        std::vector<std::string> path_bundle;
        for(const auto& entry : std::filesystem::directory_iterator(path)){
            path_bundle.push_back(entry.path().string());
        }
        if(path_bundle.empty()) {
            throw std::runtime_error("Given directory is empty!");
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
                std::getline(read_file, range_line);
                if(range_line.empty())
                {
                    read_file.close();
                    remove(converter.c_str());
                    throw EmptyFileException("File "+elem.substr(elem.find_last_of('\\')+1, std::string::npos)+" in given directory is empty");
                }
                int range = std::stoi(range_line);
                write_file.open(converter, std::ios::out | std::ios::app);
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