import numpy as np
import time

HEAD = "DATA" 
TAIL = ".TXT"
print("Numpy Sort: ")
for i in range(1, 11):
    BODY = str(i)
    file = HEAD + BODY + TAIL
    with open(file, "r") as f:
        arr = [float(x) for x in f.readline().split()]
    start_time = time.time()
    arr = np.sort(arr)
    end_time = time.time()
    running_time = (end_time - start_time)*1000
    #print("DATA ",i,": ",running_time:.0f," ms \n")
    print(f"Numpy {i} : {running_time:.0f} ms")
