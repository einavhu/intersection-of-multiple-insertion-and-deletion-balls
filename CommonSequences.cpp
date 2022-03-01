//
// Created by Ben on 01/03/2022.
//

#include "CommonSequences.h"

CommonSequences::CommonSequences(
        string supersequence,
        string subsequence
        ) :
        supersequence(supersequence),
        subsequence(subsequence),
        lcs(new vector<vector<int>*>()),
        match(new vector<vector<int>*>()),
        uRight(new set<vector<int>*>()),
        sequence_set(new set<string>())
        {}

vector<vector<int>*>& CommonSequences::lcsTable() {
    int m = subsequence.length+1;
    int n = supersequence.length+1;
    vector<vector<int>*>* lcs_table = new vector<vector<int>*>();
    for (int i = 0; i <= m; i++) {
        if (i==0){
            lcs_table.push_back(new vector<int>(n, 0));
        }
        else {
            lcs_table.push_back(new vector<int>(n, 0));
            for (int j = 0; j <= n; j++) {
                if (j == 0)
                    continue;
                else if (this->subsequence[i - 1] == this->supersequence[j - 1])
                    table[i][j] = this->table[i - 1][j - 1] + 1;
                else
                    [i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
            }
        }
    }
    return lcs_table;
}

vector<vector<bool>*>& CommonSequences::matchTable() {
    int m = subsequence.length+1;
    int n = supersequence.length+1;
    vector<vector<bool>*>* match_table = new vector<vector<bool>*>();
    for (int i = 0; i <= m; i++) {
        if (i==0){
            match_table.push_back(new vector<int>(n, false));
        }
        else {
            match_table.push_back(new vector<int>(n, false));
            for (int j = 0; j <= n; j++) {
                if (j == 0)
                    continue;
                else{
                    match_table[i][j] = subsequence[i] == supersequence[j];
                }
            }
        }
    }
}

set<vector<bool>*>& & CommonSequences::uRightHelper(int i, int j, vector<bool>& curr) {
    // Implementation of algorithm 2 in paper
    set<vector<bool>*>& helperURightSet = new set<vector<int>*>();
    if (i == 0 || j == 0){
        helperURightSet.insert(new vector<bool>(curr));
        return helperURightSet;
    }
    if (lcs[i][j] < i){
        return helperURightSet;
    }
    // TODO in the paper instead of ? there is 'n', but what is 'n'?
    if (match[i][j] == 1 && (j == ? || supersequence[j] == supersequence[j-1] || curr[j])){
        curr[j-1] = true;
        set<vector<int>*>& result = uRightHelper(i-1, j-1, curr);
        helperURightSet.insert(result.begin(), result.end());
        curr[j-1] = false;
    }
    if (lcs[i][j-1] == i){
        set<vector<int>*>& result = uRightHelper(i, j-1, curr);
        helperURightSet.insert(result.begin(), result.end());
    }
    return helperURightSet;
}

void CommonSequences::createURight() {
    lcs = lcsTable();
    match = matchTable();
    vector<bool>& curr = new vector<bool>(supersequence.length, false)
    uRight = uRightHelper(subsequence.length, supersequence.length, curr)
}



