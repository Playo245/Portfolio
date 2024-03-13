#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float multiplycalc(float var1, float var2);
float dividecalc(float var1, float var2);


int main(int argc, char *argv[]){
    char divide[] = "divide";
    float sum;
    int result;
    result = strcmp(argv[1], divide);

    if(atof(argv[3]) <= 0){
        printf("invalid\n");
    }
    else{
        if(result == 0){
            sum = dividecalc(atof(argv[2]), atof(argv[3]));
            printf("%f\n", sum);
        }
        else{
            sum = multiplycalc(atof(argv[2]), atof(argv[3]));
            printf("%f\n", sum);
        }
    }
    return 0;
}

float multiplycalc(float var1, float var2){
    return var1 * var2;
}
float dividecalc(float var1, float var2){
    return var1 / var2;
}
