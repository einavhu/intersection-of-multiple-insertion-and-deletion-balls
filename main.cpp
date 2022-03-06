//
// Created by Ben on 02/03/2022.
//
#include "CommonSequences.hpp"
#include <iostream>
#include "trivial_2.h"

using namespace std;

void print(){

}


int main() {
    CommonSequences cs = CommonSequences("00111010", "0010");
    cs.createIntersect();
    cout << "first group" << endl;
    for(auto i=cs.sequence_set.begin();i!=cs.sequence_set.end();i++){
        cout<< *i <<endl;
    }

    vector<string> super = vector<string>();
    super.push_back("00111010");
    super.push_back("00111011");
    vector<string> sub = vector<string>();
    sub.push_back("0010");
    sub.push_back("0011");
    set<string> res = algorithm2(cs.sequence_set, super, sub);
    cout << "result" << endl;
    for (auto i = res.begin(); i!= res.end(); i++){
        cout << *i << endl;
    }
    //print lcs table
//    for(int i=0; i<=(int)cs.subsequence.length(); i++){
//        for(int j = 0; j<=(int)cs.supersequence.length(); j++){
//            cout << cs.lcs[i][j] << ",";
//        }
//        cout << endl;
//    }
//    cout << endl << endl;
//
//    //print match table
//    for(int i=0; i<=cs.subsequence.length(); i++){
//        for(int j = 0; j<=cs.supersequence.length(); j++){
//            cout << cs.match[i][j] << ",";
//        }
//        cout << endl;
//    }
//    cout << endl << endl;
//
//    for(auto i = cs.uRight.begin(); i != cs.uRight.end(); ++i){
//        for(int j=0; j<cs.supersequence.length(); j++){
//            if ((*i)[j]){
//                cout << j << ",";
//            }
//        }
//        cout << endl;
//    }


    return 0;
}