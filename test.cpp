#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define Num 100
#define TT 5.0
#define M 1.0
#define K 500.0
#define D 5.0
#define DT 0.0001

struct particle{
    double v;
    double s;
    double a;
    double F;
    double U;
    int id;
};

double* mol_dyn(int N, struct particle data[]){
    int i;

    for(i = 0; i < N; i++){
        data[i].s = data[i].s + (data[i].v * DT) + (0.5 * data[i].a * pow(DT, 2.0));
        data[i].v = data[i].v + (data[i].a * DT);
    }

    data[0].F = (-K * (data[0].s - D)) + (-K * (data[0].s - data[1].s + D));
    for(i = 1; i < (N-1); i++){
        data[i].F = (-K * (data[i].s - data[i-1].s - D)) + (-K * (data[i].s - data[i+1].s + D));
    }
    data[N-1].F = (-K * (data[N-1].s - data[N-2].s - D)) + (-K * (data[N-1].s - (N * D)));

    for(i = 0; i < N; i++){
        data[i].a = data[i].F / M;
    }
}

double* pos_arr(int N, struct particle data[]){
    char c;
    int i;

    for(i = 0; i < N; i++){
        data[i].s = 0.0;
    }

    printf("Define initial positions? [y/n] ");
    scanf(" %c", &c);
    while(c != 'y' && c != 'n'){
        printf("Invalid. [y/n] ");
        scanf(" %c", &c);
    }

    while(c == 'y'){
        printf("i: ");
        scanf(" %d", &i);
        printf("s[%d]: ", i);
        scanf(" %lf", &data[i].s);
        printf("Add another initial position? [y/n] ");
        scanf(" %c", &c);
        while(c != 'y' && c != 'n'){
            printf("Invalid. [y/n] ");
            scanf(" %c", &c);
        }
    }
}

double* vel_arr(int N, struct particle data[]){
    char c;
    int i, m = 0;

    for(i = 0; i < N; i++){
        data[i].v = 0.0;
    }

    printf("Define initial velocities? [y/n] ");
    scanf(" %c", &c);
    while(c != 'y' && c != 'n'){
        printf("Invalid. [y/n] ");
        scanf(" %c", &c);
    }

    while(c == 'y'){
        printf("i: ");
        scanf(" %d", &i);
        printf("v[%d]: ", i);
        scanf(" %lf", &data[i].v);
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
    int i, id[Num];
    double t;
    struct particle data[Num];
    std::cout << std::fixed << std::setprecision(5);
    vel_arr(Num, data);
    pos_arr(Num, data);

    for(i = 0; i < Num; i++){
        data[i].a = 0.0;
        data[i].s += ((i + 1) * D);
        data[i].F = 0.0;
    }

    for(t = 0.0; t <= TT; t += DT){
        mol_dyn(Num, data);
        if((m % 100) == 0){
            myfile << t << ", ";
            for(i = 0; i < Num; i++){
                myfile << data[i].s << ", ";
            }
            myfile << "\n";
        }
        m++;
    }
myfile.close();
}
