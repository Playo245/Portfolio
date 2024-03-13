#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_calc(int mat1[][3], int mat2[][3]){
}

int main(int argc, char *argv[]){
    int first = atoi(argv[1]);
    int second = atoi(argv[2]);
    int length = (first * second) + 3;
    int third = atoi(argv[length]);
    int forth = atoi(argv[length + 1]);
    int matrix1[first][second];
    int matrix2[third][forth];
    int index = 3;
    int nindex = length + 2;
    for(int i = 0; i < first; ++i){
        for(int j = 0; j < second; ++j){
            matrix1[i][j] = atoi(argv[index]);
            ++index;
        }
    }
    for(int i = 0; i < third; ++i){
        for(int j = 0; j < forth; ++j){
            matrix2[i][j] = atoi(argv[nindex]);
            ++nindex;
        }
    }
    matrix_calc(matrix1, matrix2);
    return 0;
}
