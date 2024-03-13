#include <stdlib.h>
#include <stdio.h>

void sum(int *num, int length, int *prod, int size){
    for(int i = 0; i < length / 2; ++i){
        *prod += *(num + i) * *(num + size + i);
    }
}

void printout(int product){
    printf("%d\n", product);
}

int main(int argc, char*argv[]){
    int length = argc - 2;
    int size = atoi(argv[1]);
    int product = 0;
    int *pproduct = &product;
    int *pNumber = calloc(length, sizeof(int));
    if(!pNumber){
        printf("Unfortunately memory reallocation failed.\n");
        free(pNumber);
        pNumber = NULL;
        return 0;
    }
    for(int i = 0; i < length; ++i){
        *(pNumber + i) = atoi(argv[i + 2]);
    }
    sum(pNumber, length, pproduct, size);
    printout(product);
    free(pNumber);
    pNumber = NULL;
    return 0;
}
