#include <stdio.h>
#include <math.h>

int main(){
    double t = 0.0, dt, tt, m, k, d;
    double ax1 =0.0, ax2 = 0.0, ax3 = 0.0, ax4 = 0.0;
    double ay1 = 0.0, ay2 = 0.0, ay3 = 0.0, ay4 = 0.0;
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;
    double vx1, vx2, vx3, vx4;
    double vy1, vy2, vy3, vy4;
    double Fx1, Fx2, Fx3, Fx4;
    double Fy1, Fy2, Fy3, Fy4;
    double Ux1, Ux2, Ux3, Ux4;
    double Uy1, Uy2, Uy3, Uy4;

    while(t <= tt){
    x1 = x1 + (vx1 * dt) + (0.5 * ax1 * pow(dt, 2.0));
    vx1 = vx1 + (ax1 * dt);
    x2 = x2 + (vx2 * dt) + (0.5 * ax2 * pow(dt, 2.0));
    vx2 = vx2 + (ax2 * dt);
    x3 = x3 + (vx3 * dt) + (0.5 * ax3 * pow(dt, 2.0));
    vx3 = vx3 + (ax3 * dt);
    x4 = x4 + (vx4 * dt) + (0.5 * ax4 * pow(dt, 2.0));
    vx4 = vx4 + (ax4 * dt);
    Fx1 = (-k * (x1 - d)) + (-k * (x1 - x2 + d));
    Fx2 = (-k * (x2 - x1 - d)) + (-k * (x2 - x3 + d));
    Fx3 = (-k * (x3 - x2 - d)) + (-k * (x3 - x4 + d));
    Fx4 = (-k * (x4 - x3 - d)) + (-k * (x4 - (4 * d)));
    ax1 = Fx1 / m;
    ax2 = Fx2 / m;
    ax3 = Fx3 / m;
    ax4 = Fx4 / m;
    Ux1 = (k * ((pow(x1, 2.0) / 2) - (d * x1))) + (k * ((x1 * (- x2 + d)) + ((pow(x1, 2.0) / 2))));
    Ux2 = (k * ((x2 * (- x1 - d)) + ((pow(x2, 2.0) / 2)))) + (k * ((x2 * (- x3 + d)) + ((pow(x2, 2.0)) / 2)));
    Ux3 = (k * ((x3 * (- x2 - d)) + ((pow(x3, 2.0) / 2)))) + (k * ((x3 * (- x4 + d)) + ((pow(x3, 2.0)) / 2)));
    Ux4 = (k * ((x4 * (- x3 - d)) + ((pow(x4, 2.0) / 2)))) + (k * ((pow(x4, 2.0) / 2) - (4 * d * x4)));
    y1 = y1 + (vy1 * dt) + (0.5 * ay1 * pow(dt, 2.0));
    vy1 = vy1 + (ay1 * dt);
    y2 = y2 + (vy2 * dt) + (0.5 * ay2 * pow(dt, 2.0));
    vy2 = vy2 + (ay2 * dt);
    y3 = y3 + (vy3 * dt) + (0.5 * ay3 * pow(dt, 2.0));
    vy3 = vy3 + (ay3 * dt);
    y4 = y4 + (vy4 * dt) + (0.5 * ay4 * pow(dt, 2.0));
    vy4 = vy4 + (ay4 * dt);
    Fy1 = (-k * (y1 - d)) + (-k * (y1 - y2 + d));
    Fy2 = (-k * (y2 - y1 - d)) + (-k * (y2 - y3 + d));
    Fy3 = (-k * (y3 - y2 - d)) + (-k * (y3 - y4 + d));
    Fy4 = (-k * (y4 - y3 - d)) + (-k * (y4 - (4 * d)));
    ay1 = Fy1 / m;
    ay2 = Fy2 / m;
    ay3 = Fy3 / m;
    ay4 = Fy4 / m;
    Uy1 = (k * ((pow(y1, 2.0) / 2) - (d * y1))) + (k * ((y1 * (- y2 + d)) + ((pow(y1, 2.0) / 2))));
    Uy2 = (k * ((y2 * (- y1 - d)) + ((pow(y2, 2.0) / 2)))) + (k * ((y2 * (- y3 + d)) + ((pow(y2, 2.0)) / 2)));
    Uy3 = (k * ((y3 * (- y2 - d)) + ((pow(y3, 2.0) / 2)))) + (k * ((y3 * (- y4 + d)) + ((pow(y3, 2.0)) / 2)));
    Uy4 = (k * ((y4 * (- y3 - d)) + ((pow(y4, 2.0) / 2)))) + (k * ((pow(y4, 2.0) / 2) - (4 * d * y4)));
    printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", t, x1, x2, x3, x4, y1, y2, y3, y4);
    t += dt;
    }

return 0;
}

