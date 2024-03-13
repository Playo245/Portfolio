/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-is-trianglar.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Here I have 2 functions, a main and istriangle. The istrianle function takes care
of most of the calculations and the main fuction calls it out and provides it a variable "number".
*/
void istriangle(int num);

int main(int argc, char *argv[]){
    int number;
    number = atoi(argv[1]); // assigns the number
    istriangle(number); // calls the function
    return 0;
}

void istriangle(int num){
    int i, sum;
    sum = 1;
    i = 1;
    while(sum < num){
        sum = (i * (i + 1))/2; // loop here checks in the number is-triangular
        ++i;
    } // 2 statements which determine if its a triangular or not.
    if(sum == num){
        printf("%d is a triangular number\n", num);
    }

    else{
        printf("%d is not a triangular number\n", num);
    }
}
