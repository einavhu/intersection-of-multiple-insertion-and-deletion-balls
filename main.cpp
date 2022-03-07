#include <iostream>
#include "CommonSequences.h"
#include "Algorithms.h"
#include <fstream>
#include <time.h>
#include <sstream>
#include <iterator>
#include <chrono>


#define OPTION_1 1
#define OPTION_2 2

using namespace std;

// algorithm 1: input: k supersequences, k subsequences. The algorithm pairs each supersequence to a subsequence and
// creates
// their common sequence intersection set. The algorithm returns the intersection of the k common sets.
// algorithm 2: input: k supersequences, k subsequences. chooses a supersequence and a subsequence and creates their
// common intersection set. The algorithm returns all strings in the set that are a supersequence of all
// subsequences and a subsequence of all supersequences.
//version 1 - chooses a random pair
//version 2 - choose the supersequence with the least number of runs and the subsequence with the highest number of
// runs.
// algorithm 3: input: k supersequences, k subsequences and a number 1<=t<=k. Run algorithm 1 on the first t pairs
// of strings. Use the output for algorithm 2 for the remaining sequences. Returns the output of algorithm 2.
// argv: value, k ,input file name for tests, t (use only for algorithm 3)
// value: 1-algorithm1, 21-algorithm 2 with version 1, 22-algorithm 2 with version 2, 3-algorithm3,

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
    vector<double> test_times;
    double total_time = 0;

    vector<string> supersequences, subsequences;
    int k = atoi(argv[2]);
    int option = atoi(argv[1]);

    string sequences_string;
    string num_of_tests_string;
    getline(input, num_of_tests_string);
    int num_of_tests = atoi(num_of_tests_string.c_str());
    for (int j=0; j<num_of_tests; j++){
        getline(input, sequences_string);
        istringstream iss(sequences_string);
        vector<string> sequences = {istream_iterator<string>{iss},
                istream_iterator<string>{}};
        supersequences = vector<string>(sequences.begin(), sequences.begin()+k);
        subsequences = vector<string>(sequences.begin()+k, sequences.end());

        set<string> res;
        if(option == 1){ // algorithm 1
            clock_t begin_time = clock();
            res = algorithm_1(k,supersequences,subsequences);
            clock_t end_time = clock();
            total_time += (double)(end_time-begin_time)/CLOCKS_PER_SEC;
            test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
        }
        else if(option == 21){ // algorithm 2, version 1
            clock_t begin_time = clock();
            res = algorithm_2(OPTION_1,supersequences,subsequences);
            clock_t end_time = clock();
            total_time += (double)((end_time-begin_time)/CLOCKS_PER_SEC);
            test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
        }
        else if(option == 22){ // algorithm 2, version 2
            clock_t begin_time = clock();
            res = algorithm_2(OPTION_2,supersequences,subsequences);
            clock_t end_time = clock();
            total_time += (double)(end_time-begin_time) / CLOCKS_PER_SEC;
            test_times.push_back((double)(end_time-begin_time) / CLOCKS_PER_SEC);
        }
        else if(option == 3){ // algorithm 3
            int t = atoi(argv[argc-1]);
            clock_t begin_time = clock();
            res = algorithm_3(t,supersequences,subsequences);
            clock_t end_time = clock();
            total_time += (double)(end_time-begin_time)/CLOCKS_PER_SEC;
            test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
        }
        else{
            cout << "invalid input to main" << endl;
            return 0;
        }
    }

    double avg_time = total_time/num_of_tests;
    cout << argv[3] << "," << avg_time << endl;
    ofstream alg("../algorithm_times1.csv", ios::app);
    alg << option << "," << argv[3] << "," << avg_time << endl;
    alg.close();
    return 0;
}