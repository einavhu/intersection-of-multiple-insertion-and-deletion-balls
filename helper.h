#ifndef INTERSECTION_HELPER_H
#define INTERSECTION_HELPER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <algorithm>

using namespace std;

int num_runs(string s);
vector<string>::iterator max_runs(vector<string>& strings, int* n_p);
vector<string>::iterator min_runs(vector<string>& strings, int* n_p);
//int max_alternating_sequence(string s);
vector<vector<string>::iterator> min_maxAlternatingDiff_strings(vector<string>& supers,vector<string>& subs);
vector<vector<string>::iterator> max_maxAlternatingDiff_strings(vector<string>& supers,
                                                                vector<string>& subs);
vector<vector<string>::iterator> best_strings(vector<string>& supers, vector<string>& subs);
vector<vector<string>::iterator> string_pair(bool best, vector<string>& supers, vector<string>& subs);
#endif //INTERSECTION_HELPER_H
