#include <stdlib.h>
#include <stdio.h>

void sort(int *num, int length){
    int tmp = 0;
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

void printout(int *num, int len){
    int var = 0;
    if((*(num) * 2) < *(num + len)){
        printf("%d\n", *(num + len));
    } else {
        printf("0\n");
    }
}

int main(int argc, char*argv[]){
    int length = argc - 1;
    int *pNumber = calloc(length, sizeof(int));
    if(!pNumber){
        printf("Unfortunately memory reallocation failed.\n");
        free(pNumber);
        pNumber = NULL;
        return 0;
    }
    for(int i = 0; i < length; ++i){
        *(pNumber + i) = atoi(argv[i + 1]);
    }
    sort(pNumber, length);
    printout(pNumber, length - 1);
    free(pNumber);
    pNumber = NULL;
    return 0;
}
