#ifndef INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
#define INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class CommonSequences {

    // Entry point for the recursive function create_uRight()
    void uright_wrapper(); // algorithm 2

    // Create the group of the right most indsices of the supersequence that agree with the subsequence
    void create_uRight(int i, int j, vector<bool> curr); //algorithm 2

    // If y_j = x_i than in the match_Table at location i,j there is 1. otherwise, 0.
    // Used in create_uRight
    void match_table();

    // Creates the dynamic programming table for supersequences and subsequences
    void lcs_table();

    // Get a boolean vector (length = supersequence.length()) that contains True value in indices that we chose
    // for the output string and False for those who we didn't choose.
    // The function go over the supersequence word and return a string which is made up of the supersequence word at
    // those indices.
    std::string vector_to_string(vector<bool> indices);

public:
    string supersequence;
    string subsequence;
    vector<vector<int>> lcs; // dynamic programming table of computing the lcs of subsequence and supersequence
    vector<vector<bool>> match; // match table as defined in paper of subsequence and supersequence
    vector<vector<bool>> uRight; // the U_rigth set as defined in paper - built using algorithm 2 in paper
    set<string> sequence_set; // the result set of algorithm 1 in paper

    //constructor
    CommonSequences(string supersequence, string subsequence);

    //create the intersection of the insertion ball of the subsequence and the deletion ball of the supersequence
    void create_ID();
};

#endif //INTERSECTION_OF_MULTIPLE_INSERTION_AND_DELETION_BALLS_COMMONSEQUENCES_H
