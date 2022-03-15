//
// Created by Ben on 15/03/2022.
//

#include "Algorithms.h"
#include "helper.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector<string> supersequences = {"100","101"};
    vector<string> subsequences = {"1","0"};

    set<string> res = algorithm_2(&heuristic_min_num_of_runs_diff_strings, supersequences, subsequences);
    cout << "intersection:" << endl;
    for (auto s: res){
        cout << s << endl;
    }
}