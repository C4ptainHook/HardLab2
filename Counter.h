#ifndef INC_2_PARSER__COUNTER_H
#define INC_2_PARSER__COUNTER_H

#pragma once
#include "Students.h"
#include <vector>
#include <map>

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


#endif //INC_2_PARSER__COUNTER_H