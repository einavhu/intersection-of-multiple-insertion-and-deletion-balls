#include <iostream>
#include "CommonSequences.h"
#include "Algorithms.h"
#include <fstream>
#include <time.h>
#include <iterator>


#define HEURISTIC_1 1
#define HEURISTIC_2 2
#define OUTPUT_FILE_NAME1 "../algorithm1.csv"
#define OUTPUT_FILE_NAME21 "../algorithm21.csv"
#define OUTPUT_FILE_NAME22 "../algorithm22.csv"

using namespace std;

// Input to main:
// Algorithm to use in tests, Input test file path

//Algorithm options:
// 1 - run algorithm 1
// 21 - run algorithm 2 with heuristic of random pair choosing
// 22 - run algorithm 2 with heuristic of min difference of num of runs in word

// This file read the input file and calculate for average runtime for each set of parameters.
// Input file structure:
// first line - num_of_tests, the number of tests per set of parameters
// second line - list of n values (target string length) separated by spaces listed in the order they appear in the
// file
// third line - lis of k values (number of supersequences/subsequences in each test) separated by spaces in the
// order they appear in the file
// fourth line - list of t values (number of deletions/insertions made to create the input) separated by spaces in
// the order they appear in the file
// from the fifth line onward:
// a batch of num_of_tests lines per set of parameters (n,k,t) where each line contains k words of length n+t
// followed by k words of length n-t

// Output:
// A csv file with the average run time on each set of parameters (n,k,t)

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
        alg = ofstream(OUTPUT_FILE_NAME21);
    }
    else if (option == 22){
        alg = ofstream(OUTPUT_FILE_NAME22);
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
                        res = algorithm_2(&heuristic_random_pair, supersequences, subsequences);
                        clock_t end_time = clock();
                        total_time += (double)(end_time-begin_time)/CLOCKS_PER_SEC;
                        test_times.push_back((double)(end_time-begin_time)/CLOCKS_PER_SEC);
                    }
                    else if(option == 22){ // algorithm 2, version 2
                        clock_t begin_time = clock();
                        res = algorithm_2(&heuristic_min_num_of_runs_diff_strings, supersequences, subsequences);
                        clock_t end_time = clock();
                        total_time += (double)(end_time-begin_time) / CLOCKS_PER_SEC;
                        test_times.push_back((double)(end_time-begin_time) / CLOCKS_PER_SEC);
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