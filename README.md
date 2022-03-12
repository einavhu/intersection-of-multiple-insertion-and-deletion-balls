intersection-of-multiple-insertion-and-deletion-balls

This project provides algorithms for producing the intersection of multiple deletion and insertion balls.
Given k words of length n+t and k words of length n-t, the results are all words of length n that are subsequences of all long words and supersequences of all short words.
There are two algorithms:
Algorithm 1:
A naive approach for calculating the intersection.
Each word of length n+t is paired with a word of length n-t and the intersection of their t-deletion and t-insersion balls respectively is calculated. We then intersect the k sets and return the intersection as the result.

Algorithm 2:
A pair of words, one of length n+t and one of length n-t, are chosen according to some heuristic.
The intersection of their t-deletion and t-insertion balls respectively is calculated. The algorithm then proceeds with checking for every word in the intersection if it is a subsequence of all of the reamining long sequences and a supersequence of all remaining subsequences. only words that satisfy all of these conditions is outputed as part of the final reseult.
Different heuristics can be found in the helper.h file (functions whose name begins with "heuristic_") and can be provided by the user as well. We reccomend using heuristic_min_num_of_runs_diff_strings which outperforms the rest.
It works as follows: the word of length n+t that is chosen is the one with the smallest number of runs. The word of length n-t that is chosen is the one with the largest number of runs. Ties are broken by the choosing the first word that satisfies the condition.

Both algorithms rely on the ability to calculate the intersection of a t-deletion ball of a word of length n+t and a t-insertion ball of a word of length n-t. This is done using the class CommonSequences whose algorithm is based on those presented in the paper.....



How to use the project:
In order to run either algorithms 1 or algorithm 2 (can be found in Algorithms.h file) you need to provide them with a vector of words of length n+t (supersequences) and vector of words of length n-t (subsequences).
For algorithm 1 you need to provide also the number of sets of pairs to create and use.
For algorithm 2 you need to provide also a pointer to a function which will act a the heuristic. This function will choose a pair of string, one from supersequences and one from subsequences. Examples can be found in the helper.cpp file (functions whose name begins with "heuristic_").
The result of both algorithms is a set<string> object which is the set of all words in the intersection of the relevant deletion and insertion balls.



How to run our tests:
There are two separate main files depending on the tests you would like to run:
To test the run-time of an algorithm use main_compare_algorithm_runtime.cpp.
To test the result intersection size of different heuristics for algorithm 2 use main_compare_heuristics.


run-time testing:
The testing file should be in the following structure:
first line - num_of_tests, the number of tests per set of parameters
second line - list of n values (target string length) separated by spaces listed in the order they appear in the file
third line - lis of k values (number of supersequences/subsequences in each test) separated by spaces in the order they appear in the file
fourth line - list of t values (number of deletions/insertions made to create the input) separated by spaces in the order they appear in the file
from the fifth line onward -
a batch of num_of_tests lines per set of parameters (n,k,t) where each line contains k words of length n+t followed by k words of length n-t

Output file:
A csv file with the average run time on each set of parameters (n,k,t)

In order to run the test you need to provide the two following parameters:
1. choice of algorithm
2. path to input file

choice of algorithm can take one of the following options:
1 - to test algorithm 1
21 - to test algorithm 2 with the heuristic function heuristic_random_pair
22 - to test algorithm 2 with the heuristic function heuristic_min_num_of_runs_diff_strings


If you are running the test on a linux machine, copy the exe file and input file to the server and run the following command:
./[exe file] < algorithm_choice [path to input file]

If you are running the test through CLion...
[Add picture]

A python file for generating tests is provided. Its name is ...

Small example test file in the project...



heuristic-testing:
The run time of algorithm 2 is very much dependant on the size of the initial intersection.
Therefore, we want a heuristic that provides a pair of strings with the smallest intersection possible.
This test is used to compare the intersection sizes of different heuristics.

Input parameters:
1. k - the number of supersequences/subsequences in each test in the test file
2. path to test file

The testing file should be in the following structure:
the first line in the test file is the number of tests
each subsequent line contains k supersequences and k subsequences in that order (k is provided as a prarameter to the test outside of the input file)

Output file:
A csv file. Each line contains the following fields:
n - the target length of words in the intersection
t - number of insertions/deletions in the input words
result ID sizes of the different heuristics on the input

The heuristics comapred in this test are as follows (more information on the heuristics can be found in the helper.h file)
1. optimal intersection size (heuristic_optimal_interction) - although this can be passed as a heuristic function to algorithm 2, this is used as a performance base line to see how far from optimal the rest of the heurostics perform. Using this as an actual heuristic is redundant and takes far more time to compute than the others.
2. max absolute value of different of values of the max-length alternating subsequences of the provided sequences (heuristic_max_max_alternating_diff_strings)
3. min absolute value of different of values of the max-length alternating subsequences of the provided sequences (heuristic_max_max_alternating_diff_strings)
4. random choice (heuristic_random_pair)
5. min distance of run-vectors of the sequences (heuristic_min_dist_run_vectors) - A run-vector of a string is a vector of integers who correspond to the lengths of the runs in the string in the order they appear
6. min difference of number of runs in a sequence (min_num_of_runs_diff_strings)


If you are running the test on a linux machine, copy the exe file and input file to the server and run the following command:
./[exe file] < k [path to input file]

If you are running the test through CLion...
[Add picture]

A python file for generating tests is provided. Its name is ...

Existing test file in the project...



Getting Started and Using the Code
There are no special libraries needed to use any of the classes and files, Only standard cpp 11.
1. Create a local copy on your computer.
2.
If you are using our tests:
If you are testing the algorithms' run-times update the add_exectuable line in the cmakelists as follows:
add_executable(intersection main_compare_algorithms_runtime.cpp CommonSequences.cpp Algorithms.cpp helper.cpp test_heuristics.cpp)
If you are testing the heurstics update the add_exectuable line in the cmakelists as follows:
add_executable(intersection main_compare_heuristics.cpp CommonSequences.cpp Algorithms.cpp helper.cpp test_heuristics.cpp)

If you already have a list of supersequences and subsequences and you wish to run one of our algorithms do as follows:
1. For algorithm 1 call the function algorithm_1 in the Algorithms.h file.
2. For algorthms 2 call the function algorithm_2 in the Algorithms.h file.
If you want to use any of our heuristics they can be found in the helper.h file.
If you wish to provide your own heurstic in needs to be with the following signature:
vector<vector<string>::iterator> (*heuristic)(vector<string>&,vector<string>&)
The function recieves two vectors of strings - supersequences and subsequences
The function returns a vector of two iterators - the first is an iterator to chosen string in supersequences and the second is an iterator to the chosen string in subsequences
