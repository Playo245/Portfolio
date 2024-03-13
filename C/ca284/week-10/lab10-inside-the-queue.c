#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    int value;
    Number *next;
    Number *prev;
};

Number* add_number(int list[], int len){
    Number *current, *first, *prev;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = list[0];
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        prev = current;
        current = current->next;
        current->prev = prev;
        current->value = list[i];
    }
    current->next = NULL;
    return first;
}

void printout(Number *start){
    int count = 0;
    Number* p = NULL;
    for(p = start; p != NULL; p = p->next){
        ++count;
        printf("%d\n", p->value);
    }
}

Number* push(Number *start, int push, int val){
    Number *current, *prev, *next;
    current = start;
    while(current->value != val){
        current = current->next;
    }
    next = current->next;
    prev = current;
    current->next = (Number*)calloc(1, sizeof(Number));
    current = current->next;
    current->prev = prev;
    current->value = push;
    current->next = next;
    return start;
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int val = atoi(argv[1]);
    int vpush = atoi(argv[2]);
    int list[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    start = add_number(list, 10);
    start = push(start, vpush, val);
    printout(start);
    return 0;
}
