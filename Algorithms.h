//
// Created by Ben on 06/03/2022.
//

#ifndef INTERSECTION_ALGORITHMS_H
#define INTERSECTION_ALGORITHMS_H

#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "Helper.h"

using namespace std;

set<string> algorithm_1(int k, vector<string>& supersequence, vector<string>& subsequence);
set<string> algorithm_2(int version, vector<string>& supersequences, vector<string>& subsequences);
set<string> algorithm_3(int m, vector<string>& supersequences, vector<string>& subsequences);

#endif //INTERSECTION_ALGORITHMS_H
