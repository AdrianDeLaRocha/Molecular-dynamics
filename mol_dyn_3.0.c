#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, a1 = 0.0, a2 = 0.0, a3 = 0.0, r1, r2, r3, v1, v2, v3, F1, F2, F3, dt, tt, m, k;
    printf("Initial distance from equilibrium position No.1(m): ");
    scanf("%lf", &r1);
    printf("Initial velocity No.1(m/s): ");
    scanf("%lf", &v1);
    printf("Initial distance from equilibrium position No.2(m): ");
    scanf("%lf", &r2);
    printf("Initial velocity No.2(m/s): ");
    scanf("%lf", &v2);
    printf("Initial distance from equilibrium position No.3(m): ");
    scanf("%lf", &r3);
    printf("Initial velocity No.3(m/s): ");
    scanf("%lf", &v3);
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
    r3 = r3 + (v3 * dt) + (0.5 * a3 * pow(dt, 2.0));
    v3 = v3 + (a3 * dt);
    F1 = (-k * r1) + (-k * (r1 - r2));
    F2 = (-k * (r2 - r1)) + (-k * (r2 - r3));
    F3 = (-k * r3) + (-k * (r3 - r2));
    a1 = F1 / m;
    a2 = F2 / m;
    a3 = F3 / m;
    t += dt;
    printf("%lf, %lf, %lf, %lf\n", t, r1, r2, r3);
    }

return 0;
}
