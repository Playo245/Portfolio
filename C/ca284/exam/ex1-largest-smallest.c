/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-largest-smallest.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
using the void function to not cluster the main function.
Got 2 functions, findlargest and findsmallest. Both functions have
there own purposes like find the smallest and largest number.
The main function only sets up a array and send it to whatever
function the user might want to use.
*/
void findlargest(float numbers[], int length);
void findsmallest(float numbers[], int length);

int main(int argc, char *argv[]){
    float sum;
    int length = argc - 2;
    float numbers[length];
    int result = strcmp(argv[1], "largest");
    for(int i = 0; i < length; ++i) //Here the for-loop assigns each argv vairable to the "numbers" array.
    {
        numbers[i] = atof(argv[i + 2]);
        //printf("%.1f\n", numbers[i]);
    }
    //Here cmp gives a number, can be negative or postive or 0, But if it is 0 that means the user is asking for the largest number, and else otherwise.
    if(result == 0)
    {
        findlargest(numbers, length);
    }
    else
    {
        findsmallest(numbers, length);
    }
    return 0;
}
//here it find the largest
void findlargest(float number[], int length){
    float largest = 0;
    //searching the array for largest
    for(int i = 0; i < length; ++i){
        if(number[i] > largest){
            largest = number[i];
        }
    }
    printf("%.2f\n", largest);;
}
//here it find the smallest
void findsmallest(float number[], int length){
    float smallest = number[0];
    for(int i = 0; i < length; ++i){
        if(number[i] < smallest){
            smallest = number[i];
        }
    }
    printf("%.2f\n", smallest);
}
