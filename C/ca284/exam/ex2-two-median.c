/*
Author - Daniel Pelech
Student ID - 21510383
Date - 3/11/2022
Program - ex2-two-median.c
*/
#include <stdio.h>
#include <stdlib.h>
/*
In this script the main goal is the get the 2 median
values of a unsorted array.
*/

//The function sort, sorts the array of numbers
void sort(int numbers[], int length){
    int i, j;
    for(i = 0; i < length; ++i){
        for(j = 0; j < length; j++){
            if(numbers[j] > numbers[j + 1]){
                int tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }
}
//As it states, it prints out the 2 medians
void printout(int numbers[], int length){
    printf("%d\n", numbers[length - 1]);
    printf("%d\n", numbers[length]);
}

int main(int argc, char*argv[]){
    int length = argc - 1;
    int numbers[length];
    int i;
    for(i = 0; i < length; ++i){
        numbers[i] = atoi(argv[i + 1]);//Assigns each value from argv to array "numbers"
    }
    sort(numbers, length - 1);
    printout(numbers, length / 2);
}
