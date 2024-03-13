#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diagonal_sum(int len, int dim, int array[]){
    int var = 0;
    int total = 0;
    for(int i = 0; i < dim; ++i){
        total += array[var];
        var += dim + 1;
    }
    return total;
}

int main(int argc, char *argv[]){
    int answer, length = argc - 2;
    int dimension = atoi(argv[1]);
    int matrix[length];
    for(int i = 0; i < length; ++i){
        matrix[i] = atoi(argv[i + 2]);
    }
    answer = diagonal_sum(length, dimension, matrix);
    printf("%d\n", answer);
    return 0;
}
