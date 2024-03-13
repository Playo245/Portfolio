/*
Author - Daniel Pelech
Student ID - 21510383
Date - 30/11/2022
Program - ex3-delete-even.c
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    int value;
    Number *next;
    Number *prev;
};
/*
This program here deletes all the evens from a list and the prints them
out one by one, it also gives the sum of all the odds.
*/

//Deletes all the odd from the function down below.
Number* del_odd(int *num, int len){
    Number *current, *first, *prev;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = *(num);
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));// This forloop makes the Linkedlist.
        prev = current;
        current = current->next;
        current->prev = prev;
        current->value = *(num + i);
    }
    current->next = NULL;
    return first;
}

void printout(Number *start){//This function prints out the values.
    int count = 0;
    Number* p = NULL;
    for(p = start; p != NULL; p = p->next){
        if(p->value % 2 == 1){
            printf("%d\n", p->value);
            count += p->value;
        }
    }
    printf("%d\n", count);
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int length = argc - 1;
    int *nums = calloc(length, sizeof(int));
    for(int i = 0; i < length; ++i){
        *(nums + i) = atoi(argv[i + 1]);
    }
    start = del_odd(nums, length);
    printout(start);
    free(nums);
    return 0;
}
