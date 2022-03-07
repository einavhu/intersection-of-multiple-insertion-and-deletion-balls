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
def create_test(num_tests, n, k, t, file_name):
    f = open(file_name, "w")
    f.write(str(num_tests)+"\n")
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
    f.close()

def test_batch(num_tests_in_each, n_for_each, k_for_each, t_for_each):
    counter = 0
    for i in range (0, len(num_tests_in_each)):
        name_extension = "k = " + str(k_for_each[i]) + ", t = " + str(t_for_each[i])
        create_test(num_tests_in_each[i], n_for_each[i], k_for_each[i], t_for_each[i], "test" + str(counter) + "." + name_extension + ".txt")
        counter = counter + 1

def run_tests(num_tests_per_file, n, k_list, t_list):
    for k in k_list:
        for t in t_list:
            input_file_name = "tests/"+"k" + str(k) + "t" + str(t) + ".txt"
            create_test(num_tests_per_file, n, k, t, input_file_name)

# call from command line with arguments string_length, num_super/sub_strings, num_insertions/deletions
def main():
    n = 100
    ks = range(1,11)
    ts = [2,6,10,14,18,22]
    run_tests(100,n,ks,ts)

if __name__ == "__main__":
    main()
