#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, a1 = 0.0, a2 = 0.0, r1, r2, v1, v2, F1, F2, dt, tt, m, k;
    printf("Initial distance from equilibrium position 1(m): ");
    scanf("%lf", &r1);
    printf("Initial velocity 1(m/s): ");
    scanf("%lf", &v1);
    printf("Initial distance from equilibrium position 2(m): ");
    scanf("%lf", &r2);
    printf("Initial velocity 2(m/s): ");
    scanf("%lf", &v2);
    printf("Mass (kg): ");
    scanf("%lf", &m);
    printf("Spring constant: ");
    scanf("%lf", &k);
    printf("Test time (s): ");
    scanf("%lf", &tt);
    printf("Time steps (s): ");
    scanf("%lf", &dt);

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
