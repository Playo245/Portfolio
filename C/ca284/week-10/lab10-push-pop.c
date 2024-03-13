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

Number* pop(Number *start){
    Number *current;
    current = start;
    while(current->next != NULL){
        current = current->next;
    }
    current = current->prev;
    current->next = NULL;
    return start;
}

Number* push(Number *start, int num){
    Number *current, *prev;
    current = start;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = (Number*)calloc(1, sizeof(Number));
    prev = current;
    current = current->next;
    current->prev = prev;
    current->value = num;
    current->next = NULL;
    return start;
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int len = atoi(argv[1]);
    int pushes[2];
    int list[len];
    for(int i = 0;i < len; ++i){
        list[i] = atoi(argv[2 + i]);
        if(i < 2){
            pushes[i] = atoi(argv[len + 2 + i]);
        }
    }
    start = add_number(list, len);
    start = pop(start);
    start = pop(start);
    start = push(start, pushes[0]);
    start = push(start, pushes[1]);
    printout(start);
    return 0;
}
