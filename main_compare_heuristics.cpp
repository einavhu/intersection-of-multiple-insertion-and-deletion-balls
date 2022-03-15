#include <iostream>
#include "CommonSequences.h"
#include <iterator>
#include "test_heuristics.h"

using namespace std;

// This file read the input file and call the compare() function to get the ID result sizes of different heuristics
// for algorithm 2.

// Input: k (number of supersequences/subsequences), test file path.
// the first line in the test file is the number of tests
// each subsequent line contains k supersequences and k subsequences in that order.
// Output: csv file. Each line contains the following fields:
// n - the target length of words in the intersection
// t - number of insertions/deletions in the input words
// result ID sizes of the different heuristics on the input

int main(int argc, char *argv[]) {

    ifstream input;
    input.open(argv[2]);
    if (!input.is_open()) {
        cerr << "Failed opening input file!" << endl;
        return 0;
    }

    vector<string> supersequences, subsequences;
    int k = atoi(argv[1]);
    string sequences_string;
    string num_of_tests_string;
    getline(input, num_of_tests_string);
    int num_of_tests = atoi(num_of_tests_string.c_str());
    ofstream out("./compare_heuristics.csv");

    for (int j = 0; j < num_of_tests; j++) {
        if(j%50 == 0){
            cout << j << endl;
        }
        getline(input, sequences_string);
        istringstream iss(sequences_string);
        vector<string> sequences = {istream_iterator<string>{iss},
                                    istream_iterator<string>{}};
        supersequences = vector<string>(sequences.begin(), sequences.begin() + k);
        subsequences = vector<string>(sequences.begin() + k, sequences.end());

        compare(supersequences, subsequences, out);
    }
    out.close();
    return 0;
}