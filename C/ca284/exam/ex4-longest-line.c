#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Number Number;

struct Number{
    char value;
    Number *next;
    Number *prev;
};

Number* add_number(char list[], int len){
    Number *current, *first, *tmp;
    first = (Number*)calloc(1, sizeof(Number));
    current = first;
    current->value = list[0];
    current->prev = NULL;
    for(int i = 1; i < len; ++i){
        current->next = (Number*)calloc(1, sizeof(Number));
        tmp = current;
        current = current->next;
        current->prev = tmp;
        current->value = list[i];
    }
    current->next = NULL;
    return first;
}

void printout(Number *start, char tofind){
    int count = 0;
    int ncount = 0;
    int string[250];
    Number* current = NULL;
    for(current = start; current != NULL; current = current->next){
        if(current->value == '.' || current->value == '?'){
            string[ncount] = current->value;
            count = ncount;
            ncount = 0;
        } else {
            string[ncount] = current->value;
            ++count;
        }
    }
}

int main(int argc, char *argv[]){
    Number *start = NULL;
    int length = strlen(argv[1]);
    char string[length];
    char tofind = argv[2];
    for(int i = 0; i < length; ++i){
        string[i] = argv[1][i];
    }
    start = add_number(string, length);
    printout(start, tofind);
    return 0;
}
