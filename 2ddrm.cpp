#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define STEP 100
#define Num_x 2
#define Num_y 2
#define TT 5.0
#define DT 0.0001
#define E 1.65e-6
#define S 340000
#define M 6.6422e-11
#define R 10.0

struct particle{
    double x;
    double y;
    double vel_x;
    double vel_y;
    double acc_x;
    double acc_y;
    double For_x;
    double For_y;
    int id;
};

int main(){
    ofstream myfile;
    myfile.open ("data.csv");
    char c, axis;
    int Num_tot = Num_x * Num_y;
    int i, n, print_ctrl = STEP;
    double t, rm, part, Fx, Fy, dist, delt_x, delt_y;
    struct particle data[Num_tot];
    std::cout << std::fixed << std::setprecision(5);
    rm = S * 1.2222222;
    for(i = 0; i < Num_tot; i++){
        data[i].x = 0.0;
        data[i].y = 0.0;
    }

    printf("Define initial positions? [y/n] ");
    scanf(" %c", &c);
    while(c != 'y' && c != 'n'){
        printf("Invalid. [y/n] ");
        scanf(" %c", &c);
    }

    while(c == 'y'){
        printf("Axis: ");
        scanf(" %c", &axis);
        printf("i: ");
        scanf(" %d", &i);
        printf("%c[%d]: ", axis, i);
        if(axis == 'x'){
            scanf(" %lf", &data[i].x);
        }
        if(axis == 'y'){
            scanf(" %lf", &data[i].y);
        }
        printf("Add another initial position? [y/n] ");
        scanf(" %c", &c);
        while(c != 'y' && c != 'n'){
            printf("Invalid. [y/n] ");
            scanf(" %c", &c);
        }
    }

    for(i = 0; i < Num_tot; i++){
        data[i].x += (((i) % Num_x) * rm) + rm;
        data[i].y += (((i / Num_x) + 1) * rm);
        data[i].vel_x = 0.0;
        data[i].vel_y = 0.0;
        data[i].acc_x = 0.0;
        data[i].acc_y = 0.0;
        data[i].For_x = 0.0;
        data[i].For_y = 0.0;
        data[i].id = i;
    }

    myfile << "Time" << ", ";
    for(i = 0; i < Num_tot; i++){
        myfile << "x" << i << ", " << "y" << i << ", ";
    }
    myfile << "\n";

    for(t = 0.0; t <= TT; t += DT){
        for(i = 0; i < Num_tot; i++){
            for(n = 0; n < Num_tot; n++){
                if(n != i){
                    delt_x = data[i].x - data[n].x;
                    delt_y = data[i].y - data[n].y;
                    dist = sqrt(pow(delt_x, 2.0) + pow(delt_y, 2.0));
                    if(dist <= R && dist >= -R){
                        part =  24 * E * ((2 * pow(S, 12.0) / (pow(dist, 14.0))) - (pow(S, 6.0) / (pow(dist, 8.0))));
                        data[i].For_x += delt_x * part;
                        data[i].For_y += delt_y * part;
                    }
                }
            }
        }
        for(i = 0; i < Num_tot; i++){
            data[i].acc_x = data[i].For_x / M;
            data[i].vel_x = data[i].vel_x + (data[i].acc_x * DT);
            data[i].x = data[i].x + (data[i].vel_x * DT) + (data[i].acc_x * 0.5 * pow(DT, 2.0));

            data[i].acc_y = data[i].For_y / M;
            data[i].vel_y = data[i].vel_y + (data[i].acc_y * DT);
            data[i].y = data[i].y + (data[i].vel_y * DT) + (data[i].acc_y * 0.5 * pow(DT, 2.0));
        }
        if((print_ctrl % STEP) == 0){
            myfile << t << ", ";
            for(i = 0; i < Num_tot; i++){
                myfile << data[i].x << ", " << data[i].y << ", ";
            }
            myfile << "\n";
        }
        print_ctrl++;
    }
    myfile.close();
}
