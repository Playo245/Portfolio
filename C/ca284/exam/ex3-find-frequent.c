/*
Author - Daniel Pelech
Student ID - 21510383
Date - 30/11/2022
Program - ex3-find-freqent.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
This program here find the most find the frequent numbers
which have been foind in a list more than 3 times.
*/

//Function down below sorts the list pointer.
void sort(int *num, int length){
    int tmp = 0;
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(*(num + i) > *(num + j)){
                tmp = *(num + i);
                *(num + i) = *(num + j);
                *(num + j)= tmp;
            }
        }
    }
}


//Function down below find the most frequent variables.
int *findfreqencys(int *num, int length, int *var){
    int *nNumbers = (int*)calloc(5, sizeof(int));
    for(int i = 0; i < length; ++i){
        int count = 1;
        int j = i + 1;
        while(*(num + i) == *(num + j)){
            ++count;
            ++j;
        }
        if(count > 3){
            for(int t = 0; t < count; ++t){
                *(nNumbers + *var) = *(int*)calloc(1, sizeof(int)); //Memory alloction
                *(nNumbers + *var) = *(num + i);
                ++*var;
            }
            i += count;
        }
    }
    return nNumbers;
}

void printout(int *num, int length){ //Prints out the frequent numbers.
    for(int i = 0;i < length; ++i){
        printf("%d\n", *(num + i));
    }
}

int main(int argc, char*argv[]){
    int length = argc - 1;
    int nlength = 0;
    int *var = &nlength;
    int *pNumber = (int*)calloc(5, sizeof(int));
    for(int i = 0; i < length; i++) {
        *(pNumber + i) = *(int*)calloc(1, sizeof(int));
        *(pNumber + i) = atoi(argv[i + 1]);
    }
    sort(pNumber, length);
    pNumber = findfreqencys(pNumber, length, var);
    printout(pNumber, nlength);
    return 0;
}
