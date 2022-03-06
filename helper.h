#ifndef INTERSECTION_HELPER_H
#define INTERSECTION_HELPER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

int num_runs(string s);
set<string>::iterator max_runs(set<string>& strings, int* n_p);
set<string>::iterator min_runs(set<string>& strings, int* n_p);
vector<set<string>::iterator> best_strings(set<string>& supers, set<string>& subs);
vector<set<string>::iterator> string_pair(bool best, set<string>& supers, set<string>& subs);
#endif //INTERSECTION_HELPER_H
