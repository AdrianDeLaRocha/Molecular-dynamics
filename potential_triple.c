#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, a1 = 0.0, a2 = 0.0, a3 = 0.0, r1, r2, r3, v1, v2, v3, F1, F2, F3, dt, tt, m, k, U1, U2, U3, d;
    printf("Spring length at equilibrium: ");
    scanf("%lf", &d);
    printf("Initial distance from equilibrium position 1: ");
    scanf("%lf", &r1);
    r1 = r1 + d;
    printf("Initial velocity 1: ");
    scanf("%lf", &v1);
    printf("Initial distance from equilibrium position 2: ");
    scanf("%lf", &r2);
    r2 = r2 + (2 * d);
     printf("Initial velocity 2: ");
    scanf("%lf", &v2);
    printf("Initial distance from equilibrium position 3: ");
    scanf("%lf", &r3);
    r3 = r3 + (3 * d);
    printf("Initial velocity 3: ");
    scanf("%lf", &v3);
    printf("Mass: ");
    scanf("%lf", &m);
    printf("Spring constant: ");
    scanf("%lf", &k);
    printf("Test time: ");
    scanf("%lf", &tt);
    printf("Time steps: ");
    scanf("%lf", &dt);

    while(t <= tt){
    r1 = r1 + (v1 * dt) + (0.5 * a1 * pow(dt, 2.0));
    v1 = v1 + (a1 * dt);
    r2 = r2 + (v2 * dt) + (0.5 * a2 * pow(dt, 2.0));
    v2 = v2 + (a2 * dt);
    r3 = r3 + (v3 * dt) + (0.5 * a3 * pow(dt, 2.0));
    v3 = v3 + (a3 * dt);
    F1 = (-k * (r1 - d)) + (-k * (r1 - r2 + d));
    F2 = (-k * (r2 - r1 - d)) + (-k * (r2 - r3 + d));
    F3 = (-k * (r3 - r2 - d)) + (-k * (r3 - (3 * d)));
    a1 = F1 / m;
    a2 = F2 / m;
    a3 = F3 / m;
    U1 = (k * ((pow(r1, 2.0) / 2) - (d * r1))) + (k * ((r1 * (- r2 + d)) + ((pow(r1, 2.0) / 2))));
    U2 = (k * ((r2 * (- r1 - d)) + ((pow(r2, 2.0) / 2)))) + (k * ((r2 * (- r3 + d)) + ((pow(r2, 2.0)) / 2)));
    U3 = (k * ((r3 * (- r2 - d)) + ((pow(r3, 2.0) / 2)))) + (k * ((pow(r3, 2.0) / 2) - (3 * d * r3)));
    printf("%lf, %lf, %lf, %lf, %lf\n", t, r1, r2, U1, U2);
    t += dt;
    }

return 0;
}
