#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, a1 = 0.0, a2 = 0.0, r1 = 0.1, r2 = 0.2, v1 = -0.1, v2 = 0.1, F1, F2, dt = 0.0001, tt = 10.0, m = 0.2, k = 800.0;

    while(t <= tt){
    r1 = r1 + (v1 * dt) + (0.5 * a1 * pow(dt, 2.0));
    v1 = v1 + (a1 * dt);
    r2 = r2 + (v2 * dt) + (0.5 * a2 * pow(dt, 2.0));
    v2 = v2 + (a2 * dt);
    F1 = (-k * r1) + (-k * (r1 - r2));
    F2 = (-k * (r2 - r1)) + (-k * r2);
    a1 = F1 / m;
    a2 = F2 / m;
    t += dt;
    printf("%lf, %lf, %lf\n", t, r1, r2);
    }

return 0;
}
