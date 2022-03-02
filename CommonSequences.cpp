//
// Created by Ben on 01/03/2022.
//

#include "CommonSequences.hpp"
#include <iostream>
#include <vector>

using namespace std;

CommonSequences::CommonSequences(string supersequence, string subsequence)
{
    this->supersequence = supersequence;
    this->subsequence = subsequence;
    this->lcs = vector<vector<int>>();
    this->match = vector<vector<bool>>();
    this->uRight = vector<vector<bool>>();
    this->sequence_set = vector<string>();

}

void CommonSequences::lcsTable() {
    int m = subsequence.length();
    int n = supersequence.length();
    for (int i = 0; i <= m; i++){
        this->lcs.push_back(vector<int>(n, 0));
        if (i != 0){
            for (int j = 0; j <= n; j++) {
                if (j == 0)
                    continue;
                else if (this->subsequence[i - 1] == this->supersequence[j - 1])
                    this->lcs[i][j] = this->lcs[i - 1][j - 1] + 1;
                else
                    this->lcs[i][j] = max(this->lcs[i - 1][j], this->lcs[i][j - 1]);
            }
        }
    }
}

void CommonSequences::matchTable() {
    int m = subsequence.length()+1;
    int n = supersequence.length()+1;
    for (int i = 0; i <= m; i++) {
        this->match.push_back(vector<bool>(n, false));
        if (i != 0) {
            for (int j = 0; j <= n; j++) {
                if (j == 0)
                    continue;
                else{
                    this->match[i][j] = subsequence[i-1] == supersequence[j-1];
                }
            }
        }
    }
}

void CommonSequences::uRightHelper(int i, int j, vector<bool> curr) {
    // Implementation of algorithm 2 in paper
    if (i == 0 || j == 0){
        uRight.push_back(vector<bool>(curr));
        return;
    }
    if (lcs[i][j] < i){
        return;
    }
    if (match[i][j] == 1 && (j == (int)supersequence.length() || supersequence[j] != supersequence[j-1] || curr[j])){
        curr[j-1] = true;
        uRightHelper(i-1, j-1, curr);
        curr[j-1] = false;
    }
    if (lcs[i][j-1] == i){
        uRightHelper(i, j-1, curr);
    }
}

void CommonSequences::createURight() {
    lcsTable();
    matchTable();
    vector<bool> curr = vector<bool>(supersequence.length(), false);
    uRightHelper(subsequence.length(), supersequence.length(),curr);
}



