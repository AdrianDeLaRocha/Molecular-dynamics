#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, a = 0.0, dt, r, v, F, m, k, tt;
    printf("Initial position (m): ");
    scanf("%lf", &r);
    printf("Initial velocity (m/s): ");
    scanf("%lf", &v);
    printf("Mass (kg): ");
    scanf("%lf", &m);
    printf("Spring constant: ");
    scanf("%lf", &k);
    printf("Test time (s): ");
    scanf("%lf", &tt);
    printf("Time steps (s): ");
    scanf("%lf", &dt);

    while(t < tt){
    r = r + (v * dt) + (0.5 * a * pow(dt, 2.0));
    v = v + (a * dt);
    F = -k * r;
    a = F / m;
    printf("%lf, %lf \n", t, r);
    t += dt;
    }

return 0;
}
