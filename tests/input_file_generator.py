import random
import subprocess
import os

def generate_random_string(n):
    s = ""
    for i in range (0,n):
        s = s + (str)(random.randint(0,1))
    return s

def generate_super(num_extra, s):
    original = list(s)
    random.seed()
    for i in range (0,num_extra):
        idx = random.randint(0, len(original))
        original = original[0:idx] + [random.randint(0,1)] + original[idx:]

    return ''.join(str(e) for e in original)

def generate_sub(num_extra, s):
    original = list(s)
    random.seed()
    for i in range (0,num_extra):
        idx = random.randint(0, len(original)-1)
        original.pop(idx)

    return ''.join(str(e) for e in original)

def generate_k(super, k, num_extra, s):
    strings = []
    for i in range (0,k):
        if super:
            strings.append(generate_super(num_extra, s))
        else:
            strings.append(generate_sub(num_extra, s))
    return strings

# n: length of strings in intersect
# k: number of superstrings and substrings
# t: number of insertions/ deletions
def create_test(num_tests, n, k, t, f):
    for i in range (0, num_tests):
        s = generate_random_string(n)
        supers = generate_k(1, k, t, s)
        subs = generate_k(0, k, t, s)
        for super in supers:
            f.write(super)
            f.write(" ")
        for sub in subs:
            f.write(sub)
            f.write(" ")
        f.write("\n")

def create_heuristic_tests(num_tests_per_file, n_list, k_list, t_list, input_file_name):
    for n in n_list:
        for k in k_list:
            f = open("n"+str(n)+"k"+str(k)+input_file_name, "w")
            f.write(str(num_tests_per_file*len(t_list))+"\n")
            for t in t_list:
                create_test(num_tests_per_file, n, k, t, f)
            f.close()

def create_run_time_tests(num_tests_per_params, n_list, k_list, t_list, input_file_name):
    f = open(input_file_name, "w")
    f.write(str(num_tests_per_params)+'\n')
    f.write(" ".join([str(n) for n in n_list]))
    f.write("\n")
    f.write(" ".join([str(k) for k in k_list]))
    f.write("\n")
    f.write(" ".join([str(t) for t in t_list]))
    f.write("\n")
    for n in n_list:
        for k in k_list:
            for t in t_list:
                create_test(num_tests_per_params, n, k, t, f)
    f.close()

def main():
    n = [5,10]
    ks = [1,3]
    ts = [1,3]
    create_heuristic_tests(2, n, ks, ts, "testing_test")

if __name__ == "__main__":
    main()
