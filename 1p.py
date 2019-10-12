import numpy as np
import pandas as pd
import seaborn as sns
import parameters1 as pm
from random import randint, choice
from math import inf

f = open("data.csv","w+")
print_ctrl = pm.STEP
t = 0.0
rm = pm.S * (2 ** (1.0 / 6.0))
part = 0.0
n = 1
data = np.zeros((6,n+2))

sign = choice(['n','p'])
if sign == 'n':
    s = -1.0
else:
    s = 1.0

for i in range(n+2):
    if i != 0 and i != n+1:
        data[0,i] = (float(i) + (s / float(randint(5,21)))) * rm
        print(data[0,i])
        data[5,i] = pm.M
    else:
        data[0,i] = (float(i)) * rm
        data[5,i] = inf
        
    for m in range(1, 5):
        data[m,i] = 0.0

while t < pm.TT:
    for i in range(n+2):
        for m in range(n+2):
            if m != i:
                r = data[0,i] - data[0,m]
                data[4,i] += 4.0 * pm.E * (((pm.S / r) ** 12.0) - ((pm.S / r) ** 6.0))
                data[3,i] += r * (24.0 * pm.E * (2.0 * ((pm.S ** 12.0) / (r ** 14.0)) - ((pm.S ** 6.0) / (r ** 8.0))))
                
    for i in range(n+2):
        data[2,i] = data[3,i] / data[5,i]
        data[1,i] += data[2,i] * pm.DT
        data[0,i] += (data[1,i] * pm.DT) + ((pm.DT ** 2.0) * data[2,i] / 2)
    
    if (print_ctrl % pm.STEP) == 0:
        f.write("%lf, " % t)
        
        data[4,i] = data[4,i] * 1.0e18
        
        for i in range(1,n+1):
            f.write("%lf, " % data[0,i])
            f.write("%lf, " % data[3,i])
            f.write("%lf, " % data[4,i])
            
        f.write("\n")
        
    t += pm.DT
    print_ctrl += 1

    for i in range(n+2):
        data[3,i] = 0.0
        data[4,i] = 0.0
        
f.close()