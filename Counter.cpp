#include "Counter.h"
#include <map>

Counter::Counter(const std::vector<Student>& _parsed_data) {
        data=_parsed_data;
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
