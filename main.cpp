//
// Created by Ben on 02/03/2022.
//
#include "CommonSequences.hpp"
#include <iostream>

using namespace std;

vector<vector<bool>> strings;

void printString(vector<bool> to_print){
    for (int i = 0; i < to_print.size(); i++){
        cout << to_print[i] << ",";
    }
    cout << endl;
}

int main() {
    /*CommonSequences cs = CommonSequences("000111010", "0010");
    cs.createURight();

    //print lcs table
    for(int i=0; i<=(int)cs.subsequence.length(); i++){
        for(int j = 0; j<=(int)cs.supersequence.length(); j++){
            cout << cs.lcs[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl << endl;

    //print match table
    for(int i=0; i<=cs.subsequence.length(); i++){
        for(int j = 0; j<=cs.supersequence.length(); j++){
            cout << cs.match[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl << endl;

    for(auto i = cs.uRight.begin(); i != cs.uRight.end(); ++i){
        for(int j=0; j<cs.supersequence.length(); j++){
            if ((*i)[j]){
                cout << j << ",";
            }
        }
        cout << endl;
    }*/

    int t = 3;

    vector<vector<bool>> strings;
    vector<bool> curr(2*t, 0);
    generateStrings_tweight(t, curr, 0, 0, strings);
    for (int i = 0; i < strings.size(); i++){
        printString(strings[i]);
    }
    cout << strings.size() << endl;
    return 0;
}