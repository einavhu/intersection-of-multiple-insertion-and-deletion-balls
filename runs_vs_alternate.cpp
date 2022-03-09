//
// Created by User on 3/8/2022.
//

#include "runs_vs_alternate.h"


void alternating_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> pair = max_maxAlternatingDiff_strings(supers, subs);
    CommonSequences cs = {*pair[0], *pair[1]};
    //cout << *pair[0] << "  " <<  *pair[1] << endl;
    cs.createIntersect();
    doc << abs(max_alternating_sequence(*pair[0])-max_alternating_sequence(*pair[1])) << ", " << cs.sequence_set.size() << ", ";

    vector<vector<string>::iterator> pair2 = min_maxAlternatingDiff_strings(supers, subs);
    CommonSequences cs2 = {*pair2[0], *pair2[1]};
    cs2.createIntersect();
    doc << abs(max_alternating_sequence(*pair2[0])-max_alternating_sequence(*pair2[1])) << ", " << cs2.sequence_set.size() << endl;
}

void runs_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> pair = best_strings(supers, subs);
    CommonSequences cs = {*pair[0], *pair[1]};
    cs.createIntersect();
    //cout << *pair[0] << "  " <<  *pair[1] << endl;
    doc << num_runs(*pair[0])-num_runs(*pair[1]) << ", " << cs.sequence_set.size() << ",";
}

void optimal_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    pair<pair<int,int>,int> best_pair = best_size(supers, subs);
    CommonSequences cs = {supers[(best_pair.first).first], subs[(best_pair.first).second]};
    cs.createIntersect();
    //cout << *pair[0] << "  " <<  *pair[1] << endl;
    doc  << cs.sequence_set.size() << endl;
}

void random_intersection(vector<string>& supers, vector<string>& subs, ofstream& doc){
    vector<vector<string>::iterator> random_pair =  string_pair(0, supers, subs);
    CommonSequences cs = {*(random_pair[0]), *(random_pair[1])};
    cs.createIntersect();
    doc << cs.sequence_set.size() << ",";
}

//writes to doc the following: n, t, alternating_diff, alternating_intersect_size, runs_diff, runs_intersect_size;
/*void compare(vector<string>& supers, vector<string>& subs, ofstream& doc){
    int t = (supers[0].length()-subs[0].length())/2;
    int n = supers[0].length()-t;
    doc << n << ", " << t << ", ";
    alternating_intersection(supers, subs, doc);
    runs_intersection(supers, subs, doc);
}
 */

//writes to doc the following: n, t, alternating_diff, alternating_intersect_size, runs_diff, runs_intersect_size;
void compare_to_optimal(vector<string>& supers, vector<string>& subs, ofstream& doc){
    int t = (supers[0].length()-subs[0].length())/2;
    int n = supers[0].length()-t;
    doc << n << ", " << t << ", ";
    optimal_intersection(supers, subs, doc);
//    runs_intersection(supers, subs, doc);
//    random_intersection(supers, subs, doc);
//    alternating_intersection(supers, subs, doc);
}