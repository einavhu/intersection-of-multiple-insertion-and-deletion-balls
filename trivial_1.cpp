#include <algorithm>
#include "trivial_1.h"



vector<set<string>> create_intersection_groups(vector<string> supersequence, vector<string> subsequence){
   vector<set<string>> S;
   for(int i=0; i<supersequence.size();i++){
       CommonSequences cs = CommonSequences(supersequence[i],subsequence[i]);
       cs.createIntersect();
       S.push_back(cs.sequence_set);
   }
   return S;
}


set<string> algorithm1(vector<string> supersequence, vector<string> subsequence){
    vector<set<string>> intersection_groups = create_intersection_groups(supersequence,subsequence);
    map<string,int> strings_counter;
    set<string> return_set;
    for(int group=0;group<intersection_groups.size();group++){
        for(auto str=intersection_groups[group].begin(); str != intersection_groups[group].end(); str++){
           auto iter = strings_counter.find(*str);
           if(iter == strings_counter.end()){
               strings_counter.insert({*str,1});

           }
           else{ // str already in map
               (*iter).second++;
           }
            if((*iter).second == intersection_groups.size()){
                return_set.insert((*iter).first);
            }
        }
    }
    return return_set;
//    std::sort(intersection_groups.begin(), intersection_groups.end(), [](const set<string> & a, const set<string> & b)
//    { return a.size() < b.size();});
}


