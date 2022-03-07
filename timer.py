import subprocess
import time

# input_path = ""
# exe_path = ""
# for input_file in input_path:
#     start_time = time.time()
#     bash_cmd = exe_path+" < "+input_file
#     subprocess.run(bash_cmd, shell=True)
#     delta_time = time.time()-start_time
#     # do something with delta

input_file = "test1.txt"
exe_path = r"C:\technion\semester4\atam\hw4\intersection-of-multiple-insertion-and-deletion-balls\cmake-build-debug\intersection.exe"
bash_cmd = exe_path+" < "+input_file
start_time = time.time()
r = subprocess.run(bash_cmd, text=True, capture_output=True)
delta_time = time.time()-start_time
print(r.stdout)
print(delta_time)
