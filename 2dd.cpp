#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define STEP 100
#define Num_x 10
#define Num_y 10
#define TT 5.0
#define DT 0.0001
#define E 1.0
#define S 1.0
#define M 1.0

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

double* pos_arr(int Num, struct particle array[]){
    char c, axis;
    int i;

    for(i = 0; i < Num; i++){
        array[i].x = 0.0;
        array[i].y = 0.0;
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
            scanf(" %lf", &array[i].x);
        }
        if(axis == 'y'){
            scanf(" %lf", &array[i].y);
        }
        printf("Add another initial position? [y/n] ");
        scanf(" %c", &c);
        while(c != 'y' && c != 'n'){
            printf("Invalid. [y/n] ");
            scanf(" %c", &c);
        }
    }
}

int main(){
    ofstream myfile;
    myfile.open ("data.csv");
    int Num_tot = Num_x * Num_y;
    int i, n, Num, print_ctrl = STEP;
    double t, rm, rad, part, Fx, Fy;
    struct particle data[Num_tot];
    std::cout << std::fixed << std::setprecision(5);
    rm = S * pow(2.0, 1 / 6);
    rad = 8 * rm;
    pos_arr(Num_tot, data);

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
                if((pow(data[n].x - data[i].x, 2.0) + pow(data[n].y - data[i].y, 2.0), 0.5) <= rad || (pow(data[n].x - data[i].x, 2.0) + pow(data[n].y - data[i].y, 2.0), 0.5) >= -rad){
                    part =  -24 * E * ((pow(S, 6.0) / (pow(pow(data[n].x - data[i].x, 2.0) + pow(data[n].y - data[i].y, 2.0), 4.0))) + ((6 * pow(S, 12.0)) / (pow(pow(data[n].x - data[i].x, 2.0) + pow(data[n].y - data[i].y, 2.0), 7.0))));
                    data[i].For_x += (data[n].x - data[i].x) * part;
                    data[i].For_y += (data[n].y - data[i].y) * part;
                }
            }
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
