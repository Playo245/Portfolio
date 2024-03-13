/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-hailstones.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
In the script down below I have one int function and a main.
The hailstone function takes care of generating a new variable for "number".
This new "number" will keep changing until it reaches one, which is when the sequence is complete.
*/
int hailstone(int number);

int main(int argc, char *argv[]){
    int number = atoi(argv[1]);
    printf("%d", number); // prints the number which started the sequence as it is asked
    while(number != 1){
        number = hailstone(number); // this while loop takes care of finding the sequence using a function
        printf(" %d", number); // Also each time the loop runs, it updates "number" to a new variable
    }
    printf("\n");
    return 0;
}

int hailstone(int number){
    int result; // 2 statements which determaine if number is odd or even.
    if(number % 2 == 0){
        result = number / 2;
    }
    else{
        result = (3 * number) + 1;
    }
    return result;
}
