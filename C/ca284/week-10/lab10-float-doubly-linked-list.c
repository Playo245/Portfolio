#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    float value;
    Number *next;
    Number *prev;
};

Number* add_number(int list[], int len){
    Number *current, *first, *tmp;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = list[len - 1];
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        tmp = current;
        current = current->next;
        current->prev = tmp;
        current->value = list[len - 1 - i];
    }
    current->next = NULL;
    return first;
}

void printout(Number *start){
    int count = 0;
    Number* p = NULL;
    for(p = start; p != NULL; p = p->next){
        ++count;
        printf("%.2f\n", p->value);
    }
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int len = atof(argv[1]);
    int list[len];
    for(int i = 0;i < len; ++i){
        list[i] = atoi(argv[2 + i]);
    }
    start = add_number(list, len);
    printout(start);
    return 0;
}
