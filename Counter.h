#include "Students.h"
#include <vector>

class Counter {
    int accesable_subj;
    std::vector<Student> data;
    Counter(const std::vector<Student>&);
    void Count_averSubj();
};


