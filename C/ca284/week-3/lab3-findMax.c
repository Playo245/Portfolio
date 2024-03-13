#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findmaxium(int val1, int val2);


int main(int argc, char*argv[]){
    int length = argc;
    int i = 1;
    int max = 0;
    while(i < length) {
        max = findmaxium(max, atoi(argv[i]));
        ++i;
    }
    printf("%d\n", max);
    return 0;
}

int findmaxium(int val1, int val2){
    int sum = 0;
    if(val1 > val2){
        sum = val1;
    }
    else{
        sum = val2;
    }
    return sum;
}
