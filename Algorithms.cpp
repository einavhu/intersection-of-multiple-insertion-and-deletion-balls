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
        if(cs.sequence_set.empty()){
            vector<set<string>> empty={};
            return empty;
        }
        S.push_back(cs.sequence_set);
    }
    return S;
}


set<string> algorithm_1(int k, vector<string>& supersequence, vector<string>& subsequence) {
    vector<set<string>> intersection_groups = create_intersection_groups(k, supersequence, subsequence);
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

pair<int,int> choose_pair(vector<string>& supersequences, vector<string>& subsequences){
    pair<int,int> ret_value;

    return ret_value;
}

set<string> merge_intersection(set<string> &intersection,  CommonSequences &cs,map<string,int>&counter, int m){
    set<string> ret_set;
    for(auto str=intersection.begin();str!=intersection.end();str++){
        auto iter = counter.find(*str);
        if (iter != counter.end()) {
            (*iter).second++;
            if ((*iter).second == (m+1)) {
                ret_set.insert((*iter).first);
            }
        }
    }
    return ret_set;
}

set<string> algorithm_3(vector<string>& supersequences, vector<string>& subsequences){
    //std::sort(subsequences.begin(),subsequences.end(),less_func());
    //std::sort(supersequences.begin(),supersequences.end(),less_func());
    //std::reverse(subsequences.begin(), subsequences.end());
    set<string> intersection = {};
    int m = 1;
    pair<int,int> next = choose_pair(supersequences,subsequences); // TODO: remove from list
    CommonSequences cs0 = CommonSequences(supersequences[next.first],subsequences[next.second]);
    cs0.createIntersect();
    supersequences.erase(supersequences.begin()+next.first);
    subsequences.erase(subsequences.begin()+next.second);
    map<string,int> counter;
    for(const auto & i : cs0.sequence_set){
        counter.insert({i,1});
    }
    while((intersection.size()*2*(supersequences.size()-m)) >= supersequences.size()){
        next = choose_pair(supersequences,subsequences);
        CommonSequences cs = CommonSequences(supersequences[next.first],subsequences[next.second]);
        cs.createIntersect();
        intersection = merge_intersection(intersection, cs,counter, m);
        supersequences.erase(supersequences.begin()+next.first);
        subsequences.erase(subsequences.begin()+next.second);
        m++;
    }

    if (2*m == supersequences.size()){
        return intersection;
    }
    return algorithm_2_helper(intersection, supersequences, subsequences);
}
