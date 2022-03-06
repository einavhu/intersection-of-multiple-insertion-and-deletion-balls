#include "Helper.h"
#include "CommonSequences.h"



int num_runs(string s){
    int counter = 1;
    char current = s[0];
    for (int i = 1; i < s.length(); i++){
        if (s[i] == current){
            continue;
        }
        counter++;
        current = s[i];
    }
    return counter;
}

vector<string>::iterator max_runs(vector<string>& strings, int* n_p){
    int current_max = 0;
    int n = 0;
    auto max_str = strings.begin();
    for (auto s_p = strings.begin(); s_p != strings.end(); s_p++){
        n = num_runs(*s_p);
        if (n > current_max){
            max_str = s_p;
            current_max = n;
        }
    }
    if (n_p != nullptr){
        *n_p = current_max;
    }
    return max_str;
}

vector<string>::iterator min_runs(vector<string>& strings, int* n_p){
    int current_min = (strings.begin())->length()+1;
    int n = 0;
    auto min_str = strings.begin();
    for (auto s_p = strings.begin(); s_p != strings.end(); s_p++){
        n = num_runs(*s_p);
        if (n < current_min){
            min_str = s_p;
            current_min = n;
        }
    }
    if (n_p != nullptr){
        *n_p = current_min;
    }
    return min_str;
}

vector<vector<string>::iterator> best_strings(vector<string>& supers, vector<string>& subs){
    int min, max;
    int* max_p = &max;
    int* min_p = &min;

    auto it1 = min_runs(supers, min_p);
    auto it2 = max_runs(subs, max_p);
    vector<vector<string>::iterator> best = {it1, it2};
    return best;
}

vector<vector<string>::iterator> string_pair(bool best, vector<string>& supers, vector<string>& subs){
    if (best){
        return best_strings(supers, subs);
    }
    else{
        srand((unsigned int)time(NULL));
        int idx1 = rand() % supers.size();
        int idx2 = rand() % subs.size();
        auto it1 = supers.begin();
        for (int i = 0; i < idx1; i++)
        {
            it1++;
        }
        auto it2 = subs.begin();
        for (int i = 0; i < idx2; i++)
        {
            it2++;
        }
        vector<vector<string>::iterator> pair = {it1, it2};
        return pair;
    }
}
