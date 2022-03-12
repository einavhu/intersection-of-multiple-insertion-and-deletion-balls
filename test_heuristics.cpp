#include "test_heuristics.h"


void alternating_intersection_max(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> pair = heuristic_max_max_alternating_diff_strings(supers, subs);
    CommonSequences cs = {*pair[0], *pair[1]};
    cs.create_ID();
    doc << cs.sequence_set.size() << ", ";
}

void alternating_intersection_min(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> pair = heuristic_min_max_alternating_diff_strings(supers, subs);
    CommonSequences cs = {*pair[0], *pair[1]};
    cs.create_ID();
    doc << cs.sequence_set.size() << ", ";
}

void runs_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> pair = heuristic_min_num_of_runs_diff_strings(supers, subs);
    CommonSequences cs = {*pair[0], *pair[1]};
    cs.create_ID();
    doc << cs.sequence_set.size() << endl;
}

void optimal_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    pair<pair<int,int>,int> best_pair = find_pair_with_min_intersection_size(supers, subs);
    CommonSequences cs = {supers[(best_pair.first).first], subs[(best_pair.first).second]};
    cs.create_ID();
    doc << cs.sequence_set.size() << ", ";
}

void random_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> random_pair_i = heuristic_random_pair(supers, subs);
    CommonSequences cs = {*(random_pair_i[0]), *(random_pair_i[1])};
    cs.create_ID();
    doc << cs.sequence_set.size() << ", ";
}

void runs_vec_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> random_pair = heuristic_min_dist_run_vectors(supers, subs);
    CommonSequences cs = {*(random_pair[0]), *(random_pair[1])};
    cs.create_ID();
    doc << cs.sequence_set.size() << ", ";
}

void compare(vector<string>& supers, vector<string>& subs, ofstream& doc){
    int t = (supers[0].length()-subs[0].length())/2;
    int n = supers[0].length()-t;
    doc << n << ", " << t << ", ";
    optimal_intersection(supers, subs, doc);
    alternating_intersection_max(supers, subs, doc);
    alternating_intersection_min(supers, subs, doc);
    random_intersection(supers, subs, doc);
    runs_vec_intersection(supers, subs, doc);
    runs_intersection(supers, subs, doc);
}
