import numpy as np
from math import sqrt
import parameters as pm

f = open("data.csv","w+")
print_ctrl = pm.STEP
t = 0.0
rm = pm.S * 1.2222222
part = 0.0
Num_tot = pm.Num_x * pm.Num_y
data = np.zeros((4,2,Num_tot))

for i in range(Num_tot):
    for n in range(2):
        data[0,n,i] = 0.0
    
c = input('Define initial positions? [y/n] ')

while c != 'y' and c != 'n':
    c = input('Invalid. [y/n] ')
    
while c == 'y':
    p = input('Particle: ')
    p = int(p)
    axis = input('Axis: ')
    
    if axis == 'x':
        data[0,0,p] = input('x[%s]: ' % p)
        
    if axis == 'y':
        data[0,1,p] = input('y[%s]: ' % p)
        
    c = input('Add another initial position? [y/n] ')
    
    while c != 'y' and c != 'n':
        c = input('Invalid. [y/n] ')
        
for i in range(Num_tot):
    data[0,0,i] += (((i) % pm.Num_x) * rm) + rm
    data[0,1,i] += (((i / pm.Num_x) + 1) * rm)
    
    for n in range(1, 4):
        for m in range(1):
            data[n,m,i] = 0.0
            
f.write("Time, ")

for i in range(Num_tot):
    f.write("x%d, " % i)
    f.write("y%d, " % i)
    
f.write("\n")

while t <= pm.TT:
    for i in range(Num_tot):
        for n in range(Num_tot):
            if n != i:
                delt_x = data[0,0,i] - data[0,0,n]
                delt_y = data[0,1,i] - data[0,1,n]
                dist = sqrt((delt_x ** 2.0) + (delt_y ** 2.0))
                if dist <= pm.R and dist >= -pm.R:
                    part = 24 * pm.E * (2 * ((pm.S ** 12.0) / (dist ** 14.0)) - ((pm.S ** 6.0) / (dist ** 8.0)))
                    data[3,0,i] += delt_x * part
                    data[3,1,i] += delt_y * part
    
    for i in range(Num_tot):
        for n in range(2):
            data[2,n,i] = data[3,n,i] / pm.M
            data[1,n,i] += data[2,n,i] * pm.DT
            data[0,n,i] += (data[1,n,i] * pm.DT) + ((pm.DT ** 2.0) * data[2,n,i] / 2)
            data[3,n,i] = 0.0
            
    if (print_ctrl % pm.STEP) == 0:
        f.write("%lf, " % t)
        
        for i in range(Num_tot):
            f.write("%lf, " % data[0,0,i])
            f.write("%lf, " % data[0,1,i])
            
        f.write("\n")
        
    t += pm.DT
    print_ctrl += 1
    
f.close()
