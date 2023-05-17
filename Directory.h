
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

   void DirProcess(const char* path)
    {
        std::string converter = path;
        converter+="\\Parser_Folder";
        if(!std::filesystem::is_directory(converter)) {
        std::filesystem::create_directory(converter);
        }
    }
}

#endif //INC_2_PARSER__DIRECTORY_H