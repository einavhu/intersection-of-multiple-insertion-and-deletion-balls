//
// Created by User on 06/03/2022.
//

#include "helper.h"
#include "CommonSequences.hpp"



int num_runs(string s){
    int counter = 1;
    char current = s[0];
    for (int i = 1; i < s.length(); i++){
        if (s[i] == current){
            continue;
        }
        counter++;
        current = s[i];
    }
    return counter;
}

string max_runs(set<string>& strings, int* n_p){
    int current_max = 0;
    string max_str = "";
    int n = 0;
    for (auto s_p = strings.begin(); s_p != strings.end(); s_p++){
        n = num_runs(*s_p);
        if (n > current_max){
            max_str = *s_p;
            current_max = n;
        }
    }
    if (n_p != nullptr){
        *n_p = current_max;
    }
    return max_str;
}

string min_runs(set<string>& strings, int* n_p){
    int current_min = (strings.begin())->length()+1;
    string min_str = "";
    int n = 0;
    for (auto s_p = strings.begin(); s_p != strings.end(); s_p++){
        n = num_runs(*s_p);
        if (n < current_min){
            min_str = *s_p;
            current_min = n;
        }
    }
    if (n_p != nullptr){
        *n_p = current_min;
    }
    return min_str;
}

set<string> best_intersection(set<string>& supers, set<string>& subs){
    int min, max;
    int* min_p = &min;
    int* max_p = &max;
    string sub = max_runs(subs, max_p);
    string sup = min_runs(supers, min_p);
    CommonSequences cs = CommonSequences(sup, sub);
    cs.createIntersect();
    return cs.sequence_set;
}
