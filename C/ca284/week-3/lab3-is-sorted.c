#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sorter(int numbers[], int length);

int main(int argc, char*argv[]){
    int length = argc - 1;
    int numbers[length];
    int *sorted;
    int i = 0;
    for(int i = 0; i < length; ++i){
        numbers[i] = atoi(argv[i + 1]);
    }
    sorted = sorter(numbers, length);
    while(i < length){
        printf("%d\n", sorted[i]);
        ++i;
    }
    return 0;
}

int *sorter(int numbers[], int length){
    int j, i;
    int temp;
    for(i = 0; i < length; ++i){
        for(j = 0; j < length; ++j){
            if(numbers[i] < numbers[j]){
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    return numbers;
}
