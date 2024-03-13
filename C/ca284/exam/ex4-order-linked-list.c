/*
Author - Daniel Pelech
Student ID - 21510383
Date - 13/12/2022
Program - ex4-order-linked-list.c
*/

#include <stdio.h>
#include <stdlib.h>

/*
For this program I was required to use a doubly linked list,
which I did. The programs main purpose is to find if the order
of the linkedlist goes in a desending order.
*/


//The struct down below is used to create a Linked-List.
typedef struct Numbers Numbers;

struct Numbers{
    float value;
    Numbers *next;
    Numbers *prev;
};

//This function creates the actual linked-list.
Numbers* add_number(float list[], int len){
    Numbers *current, *first, *tmp;
    first = (Numbers*)calloc(1, sizeof(Numbers));//Allocates memory for the HEAD.
    current = first;
    current->value = list[0];
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Numbers*)calloc(1, sizeof(Numbers));//Allocates memory for each NODE.
        tmp = current;
        current = current->next;
        current->prev = tmp;
        current->value = list[i];
    }
    current->next = NULL;
    return first;//Returns the HEAD of the linked-list.
}

/*
The function down below focuses on printing the answer,
as also deciding if the list is in a descending order.
*/
void printout(Numbers *start){
    int answer = 1; // Static answer of yes
    Numbers* p = NULL;
    for(p = start; p != NULL; p = p->next){
        if(p->next == NULL){
            break;
        }
        float var1 = p->value;
        float var2 = p->next->value;
        if(var1 < var2){
            answer = 0;//Turns the static answer to 0
        }
    }
    printf("%d\n", answer);
}

int main(int argc, char *argv[]){
    Numbers *start = NULL;

    int len = argc - 1;
    float list[len];
    for(int i = 0;i < len; ++i){
        list[i] = atof(argv[1 + i]); //Assigns each value from argv.
    }
    start = add_number(list, len);
    printout(start);
    return 0;
}
