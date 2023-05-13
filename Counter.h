#pragma once
#include "Students.h"
#include "Printer.h"
#include <vector>

class Counter {
    int accesable_subj;
    std::vector<Student> data;
    void Count_averSubj();
    void Count_averScore();
    void Sort_data();
public:
    friend std::ostream& operator<<(std::ostream& os, const Counter& obj);
    void Process_parsedData(const std::vector<Student>&);
};


