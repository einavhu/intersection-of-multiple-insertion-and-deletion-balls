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
    std::sort(intersection_groups.begin(), intersection_groups.end(), [](const set<string> & a, const set<string> & b)
    { return a.size() < b.size();});

}


