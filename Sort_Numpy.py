import numpy as np
import time

dau = "DATA" 
cuoi = ".TXT"
print("[Sort in Numpy]")
for i in range(1,11):
    giua = str(i)
    file = dau + giua + cuoi
    with open(file, "r") as f:
        a = [float(x) for x in f.readline().split()]
    start_time = time.time()
    a = np.sort(a)
    end_time = time.time()
    running_time = (end_time - start_time)*1000
    #print("DATA ",i,": ",running_time:.0f," ms \n")
    print(f"DATA {i}: {running_time:.0f} ms")