#ifndef INTERSECTION_HELPER_H
#define INTERSECTION_HELPER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int num_runs(string s);
string max_runs(set<string>& strings, int* n_p);
string min_runs(set<string>& strings, int* n_p);
set<string> best_intersection(set<string>& supers, set<string>& subs);
#endif //INTERSECTION_HELPER_H
