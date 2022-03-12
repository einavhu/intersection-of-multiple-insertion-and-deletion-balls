#ifndef INTERSECTION_HELPER_H
#define INTERSECTION_HELPER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "CommonSequences.h"

using namespace std;

// Return a pair (one from supersequences and one from subsequences) with the minimal absolute value of the
// difference between the max length alternating sequence in each word.
vector<vector<string>::iterator> heuristic_min_max_alternating_diff_strings(vector<string>& supers, vector<string>& subs);

// Return a pair (one from supersequences and one from subsequences) with the maximal absolute value of the
// difference between the max length alternating sequence in each word.
vector<vector<string>::iterator> heuristic_max_max_alternating_diff_strings(vector<string>& supers,
                                                                            vector<string>& subs);
// Return a pair of supersequence string and a subseqeunce string when the supersequence has the smallest number of
// runs over all the supersequences and the subsequence has the largest number of runs over all the subsequences.
vector<vector<string>::iterator> heuristic_min_num_of_runs_diff_strings(vector<string>& supers, vector<string>& subs);

// Calculates for each sequence its run-vector (vector of length of runs in their order in the sequence). The
// function then returns the pair whose run-vector distance is minimal. If the vectors are of different sizes the
// run-vector of the subsequence is padded with zeros at its end and aligned with an additional zero at the
// beginning if its first letter is different from that of the supersequence.
vector<vector<string>::iterator> heuristic_min_dist_run_vectors(vector<string>& supersequences, vector<string>& subsequences);

// Returns a random pair of strings when the first is from supers and the second is from subs.
vector<vector<string>::iterator> heuristic_random_pair(vector<string>& supers, vector<string>& subs);

// Return iterator to the string in vector strings with the maximal number of runs
vector<string>::iterator max_runs(vector<string>& strings, int* n_p);

// Return iterator to the string in vector strings with the minimal number of runs
vector<string>::iterator min_runs(vector<string>& strings, int* n_p);

// Return the number of runs in the string s.
int num_runs(string s);

// Creates a vector of ID groups. In index i there is the ID group of supersequence[i],subsequence[i].
vector<set<string>> create_ID_groups(int k, vector<string>& supersequence, vector<string>& subsequence);

// Returns True if sub is a subsequence of super. otherwise, False.
bool is_subsequence(string sub, string super);

// Finds a pair with a minimal ID size
pair<pair<int,int>,int> find_pair_with_min_intersection_size(vector<string>& super, vector<string>& sub);

// Output all the strings in common which are a supersequence of all the strings in subsequences and a sequence of all
// the strings in supersequences.
set<string> calculate_intersection_set_from_common(set<string>& common, vector<string>& supersequences, vector<string>& subsequences);

// Get a line of numbers and insert the into a vector.
vector<int> split_int(string& line);

// Get a line and split it by spaces.
vector<string> split(string& line);

#endif //INTERSECTION_HELPER_H
