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
#define OUTPUT_FILE_NAME1 "../algorithm1.csv"
#define OUTPUT_FILE_NAME21 "../algorithm21.csv"
#define OUTPUT_FILE_NAME22 "../algorithm22.csv"
#define OUTPUT_FILE_NAME3 "../algorithm3.csv"

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

vector<string> split(string& line){
    istringstream iss(line);
    return {istream_iterator<string>{iss},
                          istream_iterator<string>{}};

}

vector<int> split_int(string& line){
    vector<string> v = split(line);
    vector<int> res;
    for (auto s: v){
        res.push_back(atoi(s.c_str()));
    }
    return res;
}

int main(int argc, char *argv[]) {
    int option = atoi(argv[1]);
    ifstream input;
    input.open(argv[2]);
    if (!input.is_open()) {
        cerr << "Failed opening input file!" << endl;
        return 0;
    }
    ofstream alg;
    if (option == 1){
        alg = ofstream(OUTPUT_FILE_NAME1);
    }
    else if (option == 21){
        alg = ofstream(OUTPUT_FILE_NAME1);
    }
    else if (option == 22){
        alg = ofstream(OUTPUT_FILE_NAME1);
    }
    else if (option == 3){
        alg= ofstream(OUTPUT_FILE_NAME1);
    }
    else {
        cerr << "Wrong algorithm!" << endl;
        return 0;
    }

    string test_num_s, ns, ks, ts;
    vector<int> nv, kv, tv;
    getline(input, test_num_s);
    int num_of_tests = atoi(test_num_s.c_str());
    getline(input, ns);
    nv = split_int(ns);
    getline(input, ks);
    kv = split_int(ks);
    getline(input, ts);
    tv = split_int(ts);


    vector<string> supersequences, subsequences;

    string sequences_string;
    for (int n : nv){
        cout << n << endl;
        for (int k : kv){
            for (int t: tv){
                vector<double> test_times;
                double total_time = 0;
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
                        clock_t begin_time = clock();
                        res = algorithm_3(supersequences,subsequences);
                        clock_t end_time = clock();
                        total_time += (double)(end_time-begin_time)/CLOCKS_PER_SEC;
                        test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
                    }
                }
                double avg_time = total_time/num_of_tests;
                alg << n << "," << k << "," << t << "," << avg_time << endl;
            }
        }
    }
    alg.close();
    return 0;
}