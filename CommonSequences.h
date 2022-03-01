//
// Created by Ben on 01/03/2022.
//

#ifndef INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
#define INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H

#include "CommonSequences.h"
#include <string>
#include <iostream>

using std::string, std::set, std::vector

class CommonSequences {
    string supersequence;
    string subsequence;
    vector<vector<int>*>* lcs; // dynamic programming table of computing the lcs of subsequence and supersequence
    vector<vector<int>*>* match; // match table as defined in paper of subsequence and supersequence
    set<vector<int>*>* uRight; // the U_rigth set as defined in paper - built using algorithm 2 in paper
    set<string>* sequence_set; // the result set of algorithm 1 in paper

public:
    CommonSequences(string supersequence, string subsequence);
    vector<vector<int>*>* lcsTable();
    vector<vector<int>*>* matchTable();
    set<string>& uRightHelper(int i, int j, vector<bool>& curr)
    void createURight();
};


#endif //INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
