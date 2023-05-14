#include "Counter.h"

void Counter::Process_parsedData(const std::vector<Student>& parsed_data) {
    data=parsed_data;
    Count_averSubj();
    Count_averScore();
    Sort_data();
}

void Counter::Count_averSubj() {

    std::map<int, int> frequency_map;

    for (const auto& el : data) {
        frequency_map[el.subj_numb]++;
    }

    int max_frequency=0;
    int key_value=0;
    for(auto pair : frequency_map) {
        if(pair.second>max_frequency) {
            max_frequency=pair.second;
            key_value=pair.first;
        }
    }
    accesable_subj=key_value;
}

void Counter::Count_averScore() {
    for (auto& el : data) {
    el.study_score=el.study_score/accesable_subj;
    }
}

void Counter::Sort_data() {
    for (int i = 1; i < data.size(); ++i) {
        int j = i-1;
        double key = data[i].study_score;
        while(j>=0 && key>data[j].study_score)
        {
            data[j+1].study_score=data[j].study_score;
            j--;
        }
        data[j+1].study_score=key;
    }
}

std::ostream& operator<<(std::ostream& os, const Counter& obj) {

    for (int i = 0; i < static_cast<int>(obj.data.size()/10*4); ++i) {
     os<<obj.data[i].name<<","<<obj.data[i].study_score<<std::endl;
    }
    return os;
}