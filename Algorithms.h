#ifndef INTERSECTION_ALGORITHMS_H
#define INTERSECTION_ALGORITHMS_H

#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "helper.h"
#include "CommonSequences.h"

using namespace std;

// naive solution.
// Input: k supersequences, k subsequences.
// The algorithm pairs each supersequence to a subsequence and creates their common sequence intersection set. The
// algorithm returns the intersection of the k common sets.
set<string> algorithm_1(int k, vector<string>& supersequence, vector<string>& subsequence);

// better solution.
// Input: k supersequences, k subsequences.
// The algorithm chooses a pair of supersequence and a subsequence and creates their common intersection set.
// The algorithm returns all strings in the set that are a supersequence of all subsequences and a subsequence of
// all supersequences.
// The algorithm has 2 versions to choose the pair of strings at the begining of the algorithm:
//version 1 - chooses a random pair
//version 2 - choose the supersequence with the least number of runs and the subsequence with the highest number of
// runs.
set<string> algorithm_2(vector<vector<string>::iterator> (*heuristic)(vector<string>&,vector<string>&),
                        vector<string>& supersequences, vector<string>& subsequences);


#endif //INTERSECTION_ALGORITHMS_H
