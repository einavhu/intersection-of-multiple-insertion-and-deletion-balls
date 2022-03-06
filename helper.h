#ifndef INTERSECTION_HELPER_H
#define INTERSECTION_HELPER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

int num_runs(string s);
vector<string>::iterator max_runs(vector<string>& strings, int* n_p);
vector<string>::iterator min_runs(vector<string>& strings, int* n_p);
vector<vector<string>::iterator> best_strings(vector<string>& supers, vector<string>& subs);
vector<vector<string>::iterator> string_pair(bool best, vector<string>& supers, vector<string>& subs);
#endif //INTERSECTION_HELPER_H
