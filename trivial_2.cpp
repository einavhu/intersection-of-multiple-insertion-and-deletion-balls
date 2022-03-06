//
// Created by User on 03/03/2022.
//

#include "trivial_2.h"
#include "CommonSequences.hpp"

bool is_subsequence(string sub, string super){
    int i=0, j=0;
    while(i < sub.length() && j < super.length()){
        if (sub[i] == super[j]){
            i++;
        }
        j++;
    }
    return i == sub.length();
}

set<string> algorithm2(set<string> common, vector<string> supersequences, vector<string> subsequences){
    set<string> result = set<string>();
    for (auto i=common.begin(); i!= common.end(); ++i){
        bool flag = true;
        for(auto j=supersequences.begin(); j!=supersequences.end(); ++j){
            if (!is_subsequence(*i, *j)){
                flag = false;
                break;
            }
        }
        if (!flag){
            continue;
        }
        for(auto j=subsequences.begin(); j!=subsequences.end(); ++j){
            if (!is_subsequence(*j, *i)){
                flag = false;
                break;
            }
        }
        if(flag){
            result.insert(*i);
        }
    }
    return result;
}