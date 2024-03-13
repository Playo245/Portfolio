/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-odd-even-array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
In this scpript, i setup 2 void functions which print out
the even and odd sums.
*/
void oddcalc(int numbers[], int length);
void evencalc(int numbers[], int length);

int main(int argc, char *argv[]){
    int length = argc;
    int number;
    int odds = 0;
    int evens = 0;
    int odd[50];
    int even[50];
    for(int i = 1; i < length; ++i)//This for-loop takes care of sorting the odd and even into different arrays
    {
        number = atoi(argv[i]);
        if((number % 2) == 0)
        {
            even[evens] = number;
            ++evens;
        }
        else{
            odd[odds] = number;
            ++odds;
        }
    }
    oddcalc(odd, odds);//Calling the functions
    evencalc(even, evens);
    return 0;
}

void oddcalc(int numbers[], int length){
    int i;
    int sum = 0;
    if(length == 0){ //This statement is here just incase if the array is empty
        sum = 0;
    }
    else{
        for(i = 0; i < length; ++i){ // this loop adds all the odds
            sum += numbers[i];
        }
    }
    printf("%d\n", sum);
}

void evencalc(int numbers[], int length){
    int i, sum;
    if(length == 0){ //This statement is here just incase if the array is empty
        sum = 0;
    }
    else{
        sum = numbers[0];
        for(i = 1; i < length; ++i){ // this loop calculates all the evens
            sum -= numbers[i];
        }
    }
    printf("%d\n", sum);
}
