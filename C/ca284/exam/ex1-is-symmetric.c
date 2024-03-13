/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-symmetric.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Here I have 2 loops, symetrical and main. All of the calculations to determine
if the string is symmetrical is in the symetrical function, which returns a
interger as an answer.
*/

int symetrical(char string[], int length);

int main(int argc, char*argv[]){
    int length, answer;
    length = strlen(argv[1]);
    char string[length];
    strcpy(string, argv[1]);
    answer = symetrical(string, length);
    //Here "answer" is my verfication, If its still 0 it means its symmetrical, and if not it means otherwise
    if(answer == 0){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}

/*Here I check if the string is symmetrical*/
int symetrical(char string[], int length){
    int i;
    int answer = 0;
    //printf("%c", string[1]);
    for(i = 0; i < length/2; ++i){
        if(string[i] != string[length - i - 1]){
            ++answer;
        }
    }
    return answer;
}
