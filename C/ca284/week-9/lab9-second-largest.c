#include <stdlib.h>
#include <stdio.h>

void sort(float *num, int length){
    float tmp = 0;
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(*(num + i) > *(num + j)){
                tmp = *(num + i);
                *(num + i) = *(num + j);
                *(num + j)= tmp;
            }
        }
    }
}

void printout(float *num, int len){
    int var = 0;
    while(var == 0){
        if(*(num + (len - 1)) != *(num + len)){
            printf("%.1f\n", *(num + (len - 1)));
            var = 1;
        }
        len = len - 1;
    }
}

int main(int argc, char*argv[]){
    int length = argc - 1;
    float *pNumber = calloc(length, sizeof(float));
    if(!pNumber){
        printf("Unfortunately memory reallocation failed.\n");
        free(pNumber);
        pNumber = NULL;
        return 0;
    }
    for(int i = 0; i < length; ++i){
        *(pNumber + i) = atof(argv[i + 1]);
    }
    sort(pNumber, length);
    printout(pNumber, length - 1);
    free(pNumber);
    pNumber = NULL;
    return 0;
}
