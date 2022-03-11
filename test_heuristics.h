#ifndef INTERSECTION_TEST_HEURISTICS_H
#define INTERSECTION_TEST_HEURISTICS_H

#include "helper.h"
#include "CommonSequences.h"
#include <fstream>
#include <time.h>
#include <sstream>
#include "Algorithms.h"

// This file is used for testing the intersection sizes of the various heuristics

//writes to doc the following: n, t, alternating_diff, alternating_intersect_size, runs_diff, runs_intersect_size
void compare(vector<string>& supers, vector<string>& subs, ofstream& doc);

//All of the following functions write to doc the result size of the heuristic
void alternating_intersection_max(vector<string>& supers, vector<string>& subs, ofstream& doc);
void alternating_intersection_min(vector<string>& supers, vector<string>& subs, ofstream& doc);
void runs_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc);
void optimal_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc);
void random_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc);
void runs_vec_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc);

#endif //INTERSECTION_TEST_HEURISTICS_H
