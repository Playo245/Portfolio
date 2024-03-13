#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dupsearch(int numbers[], int length);

int main(int argc, char*argv[]){
    int length = argc - 1;
    int numbers[length];
    int duplicate = 0;
    for(int i = 0; i < length; ++i){
        numbers[i] = atoi(argv[i + 1]);
    }
    duplicate = dupsearch(numbers, length);
    if(duplicate != 0){
        printf("%d\n", duplicate);
    }
    else{
        printf("no duplicated number\n");
    }
    return 0;
}

int dupsearch(int numbers[], int length){
    int j, i;
    int total = 0;
    for(i = 0; i < length; ++i){
        for(j = i + 1; j < length; ++j){
            if(numbers[i] == numbers[j]){
                return numbers[i];
            }
        }
    }
    return 0;
}
