#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <sys/stat.h>


namespace DirSearch {

    std::vector<std::string> GetPath(const char* path)
    { std::vector<std::string> path_bundle;
        for(const auto& entry : std::filesystem::directory_iterator(path)){
            path_bundle.push_back(entry.path().string());
        }
        return path_bundle;
    }
}
