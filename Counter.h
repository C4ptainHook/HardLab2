#pragma once
#include "Students.h"
#include <vector>

class Counter {
    int accesable_subj;
    std::vector<Student> data;
    void Count_averSubj();
    void Count_averScore();
    void Sort_data();
public:
    void Process_parsedData(const std::vector<Student>&);
};


