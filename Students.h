#ifndef INC_2_PARSER__STUDENTS_H
#define INC_2_PARSER__STUDENTS_H

#pragma once
#include <iostream>

struct Student {
    std::string name;
    double study_score;
    int subj_numb;
    Student():study_score(0),subj_numb(0){}
};


#endif //INC_2_PARSER__STUDENTS_H