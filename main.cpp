#include <iostream>
#include "CommonSequences.h"
#include "Algorithms.h"

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
// argv: value,k ,supersequences followed by subsequences, t (use only for algorithm 3)
// value: 1-algorithm1, 21-algorithm 2 with version 1, 22-algorithm 2 with version 2, 3-algorithm3,

int main(int argc, char *argv[]) {
    // get input
    vector<string> supersequences, subsequences;
    int k = atoi(argv[1]);
    for(int i=0; i<k ;i++){
        supersequences.insert(subsequences.end(),argv[2+i]);
    }
    for(int i=0; i<k ;i++){
        subsequences.insert(subsequences.end(),argv[2+k+i]);
    }

    int option = atoi(argv[0]);
    set<string> res;
    if(option == 1){ // algorithm 1
        res = algorithm_1(supersequences,subsequences);
    }
    else if(option == 21){ // algorithm 2, version 1
        res = algorithm_2(OPTION_1,supersequences,subsequences);
    }
    else if(option == 22){ // algorithm 2, version 2
        res = algorithm_2(OPTION_2,supersequences,subsequences);
    }
    else if(option == 3){ // algorithm 3
        res = algorithm_3(supersequences,subsequences);
    }
    else{
        cout << "invalid input to main" << endl;
        return 0;
    }

    cout << "result:" << endl;
    for (auto i = res.begin(); i!= res.end(); i++){
        cout << *i << endl;
    }

    return 0;
}