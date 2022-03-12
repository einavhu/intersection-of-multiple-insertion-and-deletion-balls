#include "Algorithms.h"

using namespace std;



set<string> algorithm_1(int k, vector<string>& supersequence, vector<string>& subsequence) {
    vector<set<string>> intersection_groups = create_ID_groups(k, supersequence, subsequence);
    if(intersection_groups.empty()){
        set<string> empty={};
        return empty;
    }
    map<string, int> strings_counter;
    set<string> return_set;
    for (int group = 0; group < k; group++) {
        for (auto str = intersection_groups[group].begin();str != intersection_groups[group].end(); str++) {
            auto iter = strings_counter.find(*str);
            if (iter == strings_counter.end()) {
                iter = strings_counter.insert({*str, 1}).first;

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

set<string> algorithm_2(vector<vector<string>::iterator> (*heuristic)(vector<string>&,vector<string>&),
        vector<string>& supersequences, vector<string>& subsequences){
    vector<vector<string>::iterator> intersection_strings = heuristic(supersequences,subsequences);
    CommonSequences cs = CommonSequences(*(intersection_strings[0]),*(intersection_strings[1]));
    cs.create_ID();
    supersequences.erase(intersection_strings[0]);
    subsequences.erase(intersection_strings[1]);
    return calculate_intersection_set_from_common(cs.sequence_set, supersequences, subsequences);
}
