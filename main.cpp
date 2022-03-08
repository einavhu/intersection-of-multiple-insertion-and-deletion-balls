#include <iostream>
#include "CommonSequences.h"
#include "Algorithms.h"
#include <fstream>
#include <time.h>
#include <sstream>
#include <iterator>
#include <chrono>
#include "runs_vs_alternate.h"


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
    ofstream out("../compare.csv", ios::app);

    for (int j = 0; j < num_of_tests; j++) {
        getline(input, sequences_string);
        istringstream iss(sequences_string);
        vector<string> sequences = {istream_iterator<string>{iss},
                                    istream_iterator<string>{}};
        supersequences = vector<string>(sequences.begin(), sequences.begin() + k);
        subsequences = vector<string>(sequences.begin() + k, sequences.end());

<<<<<<< Updated upstream
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
            res = algorithm_3(supersequences,subsequences);
            clock_t end_time = clock();
            total_time += (double)(end_time-begin_time)/CLOCKS_PER_SEC;
            test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
        }
        else{
            cout << "invalid input to main" << endl;
            return 0;
        }
=======
        compare(supersequences, subsequences, out);
>>>>>>> Stashed changes
    }
    out.close();
    return 0;
}