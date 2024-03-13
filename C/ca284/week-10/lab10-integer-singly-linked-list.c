#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    int value;
    Number *next;
};

Number* add_number(int list[], int len){
    Number *current, *first;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = list[0];
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        current = current->next;
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

int main(int argc, char *argv[]){
    Number *start = NULL;

    int len = atoi(argv[1]);
    int list[len];
    for(int i = 0;i < len; ++i){
        list[i] = atoi(argv[2 + i]);
    }
    start = add_number(list, len);
    printout(start);
    return 0;
}
