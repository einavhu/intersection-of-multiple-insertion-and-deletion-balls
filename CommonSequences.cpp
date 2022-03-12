#include "CommonSequences.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//internal function
// TODO: what is it?
void generate_strings_tweight(int t, vector<bool> curr, int i, int weight, vector<vector<bool>>& strings);

//internal function
// TODO: what is it?
vector<bool> get_option(vector<bool> U, vector<bool> small);


CommonSequences::CommonSequences(string supersequence, string subsequence)
{
    this->supersequence = supersequence;
    this->subsequence = subsequence;
    this->lcs = vector<vector<int>>();
    this->match = vector<vector<bool>>();
    this->uRight = vector<vector<bool>>();
    this->sequence_set = set<string>();

}

vector<bool> get_option(vector<bool> U, vector<bool> small){ // U length=n+t and has n-t 1's, small length = 2t and
    // has t 1's
    vector<bool> union_U(U.size(),false);
    int i=0;
    int U_it=0;
    int small_it = 0;
    while(i!=(int)U.size()){
        while(U[U_it] == true && U_it!=(int)U.size()){
            union_U[i]=true;
            U_it++;
            i++;
        }
        if((int)U_it == (int)U.size()){
            return union_U;
        }
        union_U[i]=small[small_it];
        i++;
        small_it++;
        U_it++;
    }
    return union_U;
}

void generate_strings_tweight(int t, vector<bool> curr, int i, int weight, vector<vector<bool>>& strings)
{
    if (i == 2*t + 1){
        return;
    }

    if (weight < t){

        // First assign "0" at ith position
        // and try for all other permutations
        // for remaining positions
        curr[i] = false;
        generate_strings_tweight(t, curr, i + 1, weight, strings);

        // And then assign "1" at ith position
        // and try for all other permutations
        // for remaining positions

        curr[i] = true;
        weight++;
        generate_strings_tweight(t, curr, i + 1, weight, strings);
    }

    else{
        strings.push_back(curr);
        return;
    }
}


void CommonSequences::create_ID()
{
    int t = (supersequence.length()-subsequence.length())/2;
    uright_wrapper();
    vector<vector<bool>> strings;
    vector<bool> curr(2*t, false);
    generate_strings_tweight(t, curr, 0, 0, strings);
    for(auto U=uRight.begin(); U != uRight.end(); U++){
        for(auto small=strings.begin();small!=strings.end();small++){
            sequence_set.insert(vector_to_string(get_option( *U, *small)));
        }
    }
}

void CommonSequences::uright_wrapper() {
    lcs_table();
    match_table();
    vector<bool> curr = vector<bool>(supersequence.length(), false);
    create_uRight(subsequence.length(), supersequence.length(), curr);
}

void CommonSequences::create_uRight(int i, int j, vector<bool> curr) {
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
        create_uRight(i - 1, j - 1, curr);
        curr[j-1] = false;
    }
    if (lcs[i][j-1] == i){
        create_uRight(i, j - 1, curr);
    }
}

void CommonSequences::match_table() {
    int m = subsequence.length()+1;
    int n = supersequence.length()+1;
    for (int i = 0; i <= m; i++) {
        this->match.push_back(vector<bool>(n+1, false));
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

void CommonSequences::lcs_table() {
    int m = subsequence.length();
    int n = supersequence.length();
    for (int i = 0; i <= m; i++){
        this->lcs.push_back(vector<int>(n+1, 0));
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

std::string CommonSequences::vector_to_string(vector<bool> indices){
    string str;
    for(int i=0;i<(int)indices.size();i++){
        if(indices[i]==true){
            str+=supersequence[i];
        }
    }
    return str;
}