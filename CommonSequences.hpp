//
// Created by Ben on 01/03/2022.
//

#ifndef INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
#define INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CommonSequences {
public:
    string supersequence;
    string subsequence;
    vector<vector<int>> lcs; // dynamic programming table of computing the lcs of subsequence and supersequence
    vector<vector<bool>> match; // match table as defined in paper of subsequence and supersequence
    vector<vector<bool>> uRight; // the U_rigth set as defined in paper - built using algorithm 2 in paper
    vector<string> sequence_set; // the result set of algorithm 1 in paper

    CommonSequences(string supersequence, string subsequence);
    void lcsTable();
    void matchTable();
    void uRightHelper(int i, int j, vector<bool> curr); //algorithm 2
    void createURight(); //call algorithm 2
};

void generateStrings_tweight(int t, vector<bool> curr, int i, int weight, vector<vector<bool>>& strings);


#endif //INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
