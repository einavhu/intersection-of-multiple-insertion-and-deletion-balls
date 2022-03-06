#include "Helper.h"
#include "CommonSequences.h"

//move to utils
vector<set<string>> create_intersection_groups(int k, vector<string> supersequence, vector<string> subsequence){
    vector<set<string>> S;
    for(int i=0; i<k;i++){
        CommonSequences cs = CommonSequences(supersequence[i],subsequence[i]);
        cs.createIntersect();
        S.push_back(cs.sequence_set);
    }
    return S;
}


set<string> algorithm_1(int k, vector<string> supersequence, vector<string> subsequence) {
    vector<set<string>> intersection_groups = create_intersection_groups(k, supersequence, subsequence);
    map<string, int> strings_counter;
    set<string> return_set;
    for (int group = 0; group < k; group++) {
        for (auto str = intersection_groups[group].begin();
             str != intersection_groups[group].end(); str++) {
            auto iter = strings_counter.find(*str);
            if (iter == strings_counter.end()) {
                strings_counter.insert({*str, 1});

            } else { // str already in map
                (*iter).second++;
            }
            if ((*iter).second == k) {
                return_set.insert((*iter).first);
            }
        }
    }
    return return_set;
}

//move to utils
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

//rename
set<string> algorithm_2_helper(set<string> common, vector<string> supersequences, vector<string> subsequences){
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

set<string> algorithm_2(int version, vector<string> supersequences, vector<string> subsequences){
    vector<set::iterator> intersection_strings;
    if (version == 1){
        //set<string> common_set = ??;
    }
    else if (version == 2){
        intersection_strings = best_intersection(supersequences, subsequences);
    }
    CommonSequences cs = CommonSequences(*intersection_strings[0],*intersection_strings[1]);
    supersequences.erase(intersection_strings[0]);
    subsequences.erase(intersection_strings[1]);
    algorithm2_helper(cs.sequence_set, supersequences, subsequences);
}

set<string> algorithm_3(int t, vector<string> supersequences, vector<string> subsequences){
    set<string> common = algorithm_1(t, supersequences, subsequences);
    supersequences_cut = vector<string>(supersequences.begin() + t, supersequences.end());
    subsequences_cut = vector<string>(subsequences.begin() + t, subsequences.end());
    return algorithm_2_helper(common, supersequences_cut, subsequences_cut);
}