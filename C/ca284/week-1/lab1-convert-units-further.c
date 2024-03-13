#include <stdio.h>
#include <stdlib.h>


int main(){

    int low_cm = 30;
    int upp_cm = 50;
    float inch = 2.54;

    while(low_cm < upp_cm){
        int i = 0;
        while (i < 5){
            float result = low_cm / inch;
            printf("%.2f ", result);
            low_cm++ && i++;
        }
        printf("\n");
    }
    return (0);
}
