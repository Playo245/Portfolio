/*
Author - Daniel Pelech
Student ID - 21510383
Date - 3/11/2022
Program - ex2-diagonal.c
*/
#include <stdio.h>
#include <stdlib.h>
/*
This script has the purpose of getting the sum
of anti-diagonal line in a matrix, So from top
right to bottom left of the matrix.
*/

//This fuction adds up all the anit-diagonal elements.
void anti_diagonal(int matrix[], int size, int length, int *panswer){
    int laps = size - 1; //This is the amount of variable it has to skip.
    int var = laps;
    for(int i = 0; i < size; ++i){
        *panswer += matrix[var]; //Stores all the anti-diagonal variables.
        var += laps;
    }
}
//As stated, prints out the answer/sum.
void printout(int answer){
    printf("%d\n", answer);
}

int main(int argc, char*argv[]){
    int answer = 0, length = argc - 2;
    int *panswer = &answer;
    int size = atoi(argv[1]);
    int matrix[length];
    for(int i = 0; i < length; ++i){
        matrix[i] = atoi(argv[i + 2]);//Assigns each value from argv to array "matrix".
    }
    anti_diagonal(matrix, size, length, panswer);//Using pointers to get the sum/answer.
    printout(answer);
    return 0;
}
