#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float sum(int, int);
float difference(int, int);
float product(int, int);
float devision(int, int);
float power(int, int);
float logg(int, int);

int main(int argc, char *argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float (*pfunction)(int, int);

    pfunction = sum;
    float result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = difference;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = product;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = devision;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = power;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = logg;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    return 0;
}

float sum(int a, int b){
    return a + b;
}

float difference(int a, int b){
    return a - b;
}

float product(int a, int b){
    return a * b;
}

float devision(int a, int b){
    return a / b;
}

float power(int a, int b){
    float res = a;
    for(int i = 0; i < b - 1; ++i){
        res *= a;
    }
    return res;
}

float logg(int a, int b){
    return log(a) + log(b);
}
