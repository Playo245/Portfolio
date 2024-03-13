#include <stdio.h>
#include <stdlib.h>

typedef struct Number Number;

struct Number{
    int value;
    Number *next;
    Number *prev;
};

Number* add_numbers(int *nums, int len){
    Number *current, *first, *prev;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = *(nums);
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        prev = current;
        current = current->next;
        current->prev = prev;
        current->value = *(nums + i);
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

Number* del_odd(Number *start, int length){
    Number *current, *prev, *next;
    current = start;
    for(int i = 0;i < length; ++i){
        if(current-> value % 2 == 0){
            next = current->next;
            prev = current;
            current->next = (Number*)calloc(1, sizeof(Number));
            current = current->next;
            current->prev = prev;
            current->value = push;
            current->next = next;
        }
    }
    return start;
}

int main(int argc, char *argv[]){
    Number *start = NULL;

    int length = argc - 1;
    int *nums = (int)calloc(length, sizeof(int));
    for(int i = 0; i < length; ++i){
        *(nums) = atoi(argv[i + 1]);
    }
    start = add_number(nums, length);
    free(nums);
    start = del_odd(start, length);
    printout(start);
    return 0;
}
