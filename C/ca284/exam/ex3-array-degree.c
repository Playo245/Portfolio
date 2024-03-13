#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    int value;
    Number *next;
    Number *prev;
};

Number* linkedlist(int *num, int len){
    Number *current, *first, *prev;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = *(num);
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        prev = current;
        current = current->next;
        current->prev = prev;
        current->value = *(num + i);
    }
    current->next = NULL;
    return first;
}

void mostfrequent(Number *start, int len){
    int count = 0;
    int freq;
    for(start; start != NULL; start = start->next){
        if(start->value == start->next->value){
            ++count;
            freq = start->value;
            printf("%d\n", freq);
        } else {
            count = 0;
        }
    }
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int length = argc - 1;
    int *nums = calloc(length, sizeof(int));
    for(int i = 0; i < length; ++i){
        *(nums + i) = atoi(argv[i + 1]);
    }
    start = linkedlist(nums, length);
    //printf("%d", start->value);
    mostfrequent(start, length);
    free(nums);
    return 0;
}
