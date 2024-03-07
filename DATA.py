import numpy as np

dau = "DATA" 
cuoi = ".TXT"
for i in range(1,11):
    giua = str(i)
    file = dau + giua + cuoi;
    a = []
    for j in range(1000000):
        a.append(np.around(np.random.uniform(-1000000, 1000000),decimals=2))
    if (i==1):
        a = sorted(a)
    elif (i==2):
        a = sorted(a, reverse=True)
    with open(file, "w") as f:
        for so in a:
            f.write(f"{so} ")