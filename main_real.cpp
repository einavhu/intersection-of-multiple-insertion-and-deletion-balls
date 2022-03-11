#include <iostream>
#include "CommonSequences.h"
#include "Algorithms.h"
#include <fstream>
#include <time.h>
#include <sstream>
#include <iterator>
#include <chrono>
#include "runs_vs_alternate.h"


#define OPTION_1 1
#define OPTION_2 2

using namespace std;

vector<string> split(string line){
istringstream iss(line);
return {istream_iterator<string>{iss},
istream_iterator<string>{}};

}

int main(int argc, char *argv[]) {

    ifstream input;
    input.open(argv[3]);
    if (!input.is_open()) {
        cerr << "Failed opening input file!" << endl;
        return 0;
    }

    vector<string> supersequences, subsequences;
    int k = atoi(argv[2]);
    string sequences_string;
    string num_of_tests_string;
    getline(input, num_of_tests_string);
    int num_of_tests = atoi(num_of_tests_string.c_str());
    ofstream out("../optimal3.csv", ios::app);

    for (int j = 0; j < num_of_tests; j++) {
        getline(input, sequences_string);
        istringstream iss(sequences_string);
        vector<string> sequences = {istream_iterator<string>{iss},
                                    istream_iterator<string>{}};
        supersequences = vector<string>(sequences.begin(), sequences.begin() + k);
        subsequences = vector<string>(sequences.begin() + k, sequences.end());
        compare_to_optimal(supersequences, subsequences, out);
    }
    out.close();
    return 0;
}