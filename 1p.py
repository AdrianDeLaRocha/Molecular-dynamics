import parameters1 as pm
import random

f = open("data.csv","w+")
print_ctrl = pm.STEP
t = 0.0
rm = pm.S * 1.2222222
part = 0.0
r = random.randint(-10, 10) * rm / 11.0
v = 0.0


f.write("Time, r, v, a, F, U\n")

while t < pm.TT:
    U = 8 * pm.E * (((pm.S / r) ** 12) - ((pm.S / r) ** 6))
    F = 2 * r * (24 * pm.E * (2 * ((pm.S ** 12.0) / (r ** 14.0)) - ((pm.S ** 6.0) / (r ** 8.0))))
    a = F / pm.M
    v += a * pm.DT
    r += (v * pm.DT) + ((pm.DT ** 2.0) * a / 2)
    
    if (print_ctrl % pm.STEP) == 0:
        f.write("%lf, " % t)
        f.write("%lf, " % r)
        f.write("%lf, " % v)
        f.write("%lf, " % a)
        f.write("%lf, " % F)
        f.write("%lf, \n" % U)
        
    F = 0.0
    U = 0.0
    t += pm.DT
    print_ctrl += 1
    
f.close()