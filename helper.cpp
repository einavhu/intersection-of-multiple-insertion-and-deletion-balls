#include "helper.h"
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

int max_alternating_sequence(string s){
    if (s == "") return 0;
    int max_len = 1;
    int current_len = 1;
    char current = s[0];
    for (int i = 1; i < s.length(); i++){
        if (s[i] == current){
            if (current_len > max_len){
                max_len = current_len;
            }
            current_len = 1;
        }
        else{
            current_len++;
        }
        current = s[i];
    }
    if (current_len > max_len){
        max_len = current_len;
    }
    return max_len;
}

struct less_func
{
    inline bool operator() (const tuple<vector<string>::iterator, int>& str1, const tuple<vector<string>::iterator, int>& str2)
    {
        return get<1>(str1) < get<1>(str2);
    }
};

vector<tuple<vector<string>::iterator, int>> expand_vec(vector<string>& strings){
    vector<tuple<vector<string>::iterator, int>> A;
    auto it = strings.begin();
    for (int i = 0; i < strings.size(); i++) {
        tuple<vector<string>::iterator, int> sup(it+i, max_alternating_sequence(strings[i]));
        A.push_back(sup);
    }
    std::sort(A.begin(),A.end(),less_func());
    return A;
}

vector<vector<string>::iterator> min_maxAlternatingDiff_strings(vector<string>& supers, vector<string>& subs){
    vector<tuple<vector<string>::iterator, int>> A = expand_vec(supers);
    vector<tuple<vector<string>::iterator, int>> B = expand_vec(subs);

    int a = 0, b = 0;

    // Initialize result as max value
    int result = supers[0].length();

    tuple<vector<string>::iterator, int>* a_p = &A[0];
    tuple<vector<string>::iterator, int>* b_p = &B[0];

    // Scan Both Arrays upto sizeof of the arrays
    while (a < A.size() && b < B.size())
    {
        if (abs(get<1>(A[a]) - get<1>(B[b])) < result) {
            result = abs(get<1>(A[a]) - get<1>(B[b]));
            a_p = &A[a];
            b_p = &B[b];
        }

        // Move Smaller Value
        if (get<1>(A[a]) < get<1>(B[b]))
            a++;

        else
            b++;
    }

    return {get<0>(*a_p), get<0>(*b_p)};
}

vector<vector<string>::iterator> max_maxAlternatingDiff_strings(vector<string>& supers, vector<string>& subs){
    vector<tuple<vector<string>::iterator, int>> A = expand_vec(supers);
    vector<tuple<vector<string>::iterator, int>> B = expand_vec(subs);

    int min_sup = get<1>(A[0]);
    int max_sup = get<1>(A[A.size()-1]);
    int min_sub = get<1>(B[0]);
    int max_sub = get<1>(B[B.size()-1]);

    if ((max_sup-min_sub) > (max_sub-min_sup)){
        return {get<0>(A[A.size()-1]), get<0>(B[0])};
    }
    else{
        return {get<0>(A[0]), get<0>(B[B.size()-1])};
    }

}



vector<vector<string>::iterator> best_strings(vector<string>& supers, vector<string>& subs){
    int min, max;
    int* max_p = &max;
    int* min_p = &min;

    auto it1 = min_runs(supers, min_p);
    auto it2 = max_runs(subs, max_p);
    return {it1, it2};
}

vector<vector<string>::iterator> string_pair(bool best, vector<string>& supers, vector<string>& subs){
    if (best){ // version 2
        return best_strings(supers, subs);
    }
    else{ // version 1
        srand((unsigned int)time(NULL));
        int idx1 = rand() % supers.size();
        int idx2 = rand() % subs.size();
        auto it1 = supers.begin()+idx1;
        auto it2 = subs.begin()+idx2;
        return {it1, it2};
    }
}

vector<int> get_runs_vector(string str){
    vector<int> ret_vector;
    int ret_index=0, str_index = 0,counter = 0;
    char current = str[str_index];
    while(str_index != str.length()){
        while((str[str_index] == current) && (str_index!= str.length())){
            counter++;
            str_index++;
        }
        ret_vector.push_back(counter);
        current = str[str_index];
        counter = 0;
        ret_index++;
    }
    return ret_vector;
}

pair<vector<int>,vector<int>> complete_vectors(vector<int> super_vector, vector<int> sub_vector, ){

}

int get_diff_norm(vector<int> super_vector, vector<int> sub_vector){

}



vector<vector<string>::iterator> version_23(vector<string>& supersequences, vector<string>& subsequences){
    int k = supersequences.size();
    vector<vector<int>> vec_super,vec_sub;
    for(int i=0;i<k;i++){
        vec_super.push_back(get_runs_vector(supersequences[k]));
        vec_sub.push_back(get_runs_vector(subsequences[k]));
    }
    pair<int,int> min_pair;
    int min,current; // TODO: initialize
    pair<vector<int>,vector<int>> complete_sup_sub;
    for(int i_sup = 0;i_sup<supersequences.size();i_sup++){
        for(int j_sub = 0;j_sub<subsequences.size();j_sub++){
            complete_sup_sub = complete_vectors(vec_super[i_sup],vec_sub[j_sub]);
            current = get_diff_norm(complete_sup_sub.first,complete_sup_sub.second);
            if(current < min){
                min = current;
                min_pair = {i_sup,j_sub};
            }
        }
    }
    return min_pair; // TODO: ben fix
}

