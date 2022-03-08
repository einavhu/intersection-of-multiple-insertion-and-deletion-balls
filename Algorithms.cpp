#include "helper.h"
#include "CommonSequences.h"
#include <map>
#include <set>
#include <algorithm>


using namespace std;

//move to utils
vector<set<string>> create_intersection_groups(int k, vector<string>& supersequence, vector<string>& subsequence){
    vector<set<string>> S;
    for(int i=0; i<k;i++){
        CommonSequences cs = CommonSequences(supersequence[i],subsequence[i]);
        cs.createIntersect();
        S.push_back(cs.sequence_set);
    }
    return S;
}


set<string> algorithm_1(int k, vector<string>& supersequence, vector<string>& subsequence) {
    vector<set<string>> intersection_groups = create_intersection_groups(k, supersequence, subsequence);
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
set<string> algorithm_2_helper(set<string>& common, vector<string>& supersequences, vector<string>& subsequences){
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

set<string> algorithm_2(int version, vector<string>& supersequences, vector<string>& subsequences){
    vector<vector<string>::iterator> intersection_strings;
    if (version == 1){
        intersection_strings = string_pair(false, supersequences, subsequences);
    }
    else if (version == 2){
        intersection_strings = string_pair(true, supersequences, subsequences);
    }
    CommonSequences cs = CommonSequences(*(intersection_strings[0]),*(intersection_strings[1]));
    cs.createIntersect();
    supersequences.erase(intersection_strings[0]);
    subsequences.erase(intersection_strings[1]);
    return algorithm_2_helper(cs.sequence_set, supersequences, subsequences);
}

struct less_func
{
    inline bool operator() (const string& str1, const string& str2)
    {
        return (num_runs(str1) < num_runs(str2));
    }
};


set<string> algorithm_3(int m, vector<string>& supersequences, vector<string>& subsequences){
    if(m<1){
        cout << "invalid input to algorithm 3" << endl;
        set<string> not_good = {};
        return not_good;
    }
    std::sort(subsequences.begin(),subsequences.end(),less_func());
    std::sort(supersequences.begin(),supersequences.end(),less_func());
    std::reverse(subsequences.begin(), subsequences.end());
    set<string> common = algorithm_1(m, supersequences, subsequences);
    if (m == supersequences.size()){
        return common;
    }
    vector<string> supersequences_cut = vector<string>(supersequences.begin() + m, supersequences.end());
    vector<string> subsequences_cut = vector<string>(subsequences.begin() + m, subsequences.end());
    return algorithm_2_helper(common, supersequences_cut, subsequences_cut);
}

pair<pair<int,int>,int> best_size(vector<string>& super, vector<string>& sub){
    int min_size = 0;
    pair<pair<int,int>,int> result;
    for(int i=0; i<super.size(); i++){
        for(int j=0; j<sub.size(); j++){
            CommonSequences cs = CommonSequences(super[i], sub[j]);
            cs.createIntersect();
            if ((i == 0 && j == 0) || cs.sequence_set.size() < min_size){
                result = {{i,j},cs.sequence_set.size()};
                min_size = cs.sequence_set.size();
            }
        }
    }
    return result;
}