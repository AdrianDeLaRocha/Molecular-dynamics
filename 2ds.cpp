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
#define M 1.0
#define K 500.0
#define D 5.0
#define DT 0.0001

struct particle{
    double x;
    double y;
    double vel_x;
    double vel_y;
    double acc_x;
    double acc_y;
    double For_x;
    double For_y;
    double Pot_x;
    double Pot_y;
    int id;
};

double* pos_arr(int Num_tot, struct particle data[]){
    char c, axis;
    int i;

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
}

double* vel_arr(int Num_tot, struct particle data[]){
    char c, axis;
    int i;

    for(i = 0; i < Num_tot; i++){
        data[i].vel_x = 0.0;
        data[i].vel_y = 0.0;
    }

    printf("Define initial velocities? [y/n] ");
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
        printf("v%c[%d]: ", axis, i);
        if(axis == 'x'){
            scanf(" %lf", &data[i].vel_x);
        }
        if(axis == 'y'){
            scanf(" %lf", &data[i].vel_y);
        }
        printf("Add another initial velocity? [y/n] ");
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
    int i, n, Num, id[Num_tot], print_ctrl = STEP;
    double t;
    struct particle data[Num_tot];
    std::cout << std::fixed << std::setprecision(5);
    vel_arr(Num_tot, data);
    pos_arr(Num_tot, data);

    for(i = 0; i < Num_tot; i++){
        data[i].x += ((i % Num_x) + 1) * D;
        data[i].y += ((i / Num_x) + 1) * D;
        data[i].acc_x = 0.0;
        data[i].acc_y = 0.0;
        data[i].For_x = 0.0;
        data[i].For_y = 0.0;
    }

    myfile << "Time" << ", ";
    for(i = 0; i < Num_tot; i++){
        myfile << "x" << i << ", ";
    }
    for(i = 0; i < Num_tot; i++){
        myfile << "y" << i << ", ";
    }
    myfile << "\n";

    for(t = 0.0; t <= TT; t += DT){
    // Getting updates for the x-axis.
    for(i = 0; i < (Num_tot); i++){
        if((i + Num_x) % Num_x == 0){
            data[i].For_x = (-K * (data[i].x - D)) + (-K * (data[i].x - data[i+1].x + D));
        }
        else if((i + Num_x) % Num_x == (Num_x - 1)){
            data[i].For_x = (-K * (data[i].x - data[i-1].x - D)) + (-K * (data[i].x - (Num_x * D)));
        }
        else{
            data[i].For_x = (-K * (data[i].x - data[i-1].x - D)) + (-K * (data[i].x - data[i+1].x + D));
        }
        data[i].acc_x = data[i].For_x / M;
        data[i].vel_x = data[i].vel_x + (data[i].acc_x * DT);
        data[i].x = data[i].x + (data[i].vel_x * DT) + (data[i].acc_x * 0.5 * pow(DT, 2.0));
    }

    // Getting updates for the y-axis.
    for(i = 0; i < (Num_tot); i++){
        if(i < Num_x){
            data[i].For_y = (-K * (data[i].y - D)) + (-K * (data[i].y - data[i+Num_x].y + D));
        }
        else if((i / Num_x == Num_y - 1)){
            data[i].For_y = (-K * (data[i].y - data[i-Num_x].y - D)) + (-K * (data[i].y - (Num_y * D)));
        }
        else{
            data[i].For_y = (-K * (data[i].y - data[i-Num_x].y - D)) + (-K * (data[i].y - data[i+Num_x].y + D));
        }
        data[i].acc_y = data[i].For_y / M;
        data[i].vel_y = data[i].vel_y + (data[i].acc_y * DT);
        data[i].y = data[i].y + (data[i].vel_y * DT) + (data[i].acc_y * 0.5 * pow(DT, 2.0));
    }
        if((print_ctrl % STEP) == 0){
            myfile << t << ", ";
            for(i = 0; i < Num_tot; i++){
                myfile << data[i].x << ", ";
            }
            for(i = 0; i < Num_tot; i++){
                myfile << data[i].y << ", ";
            }
            myfile << "\n";
        }
        print_ctrl++;
    }
    myfile.close();
}
