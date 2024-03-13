#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char*argv[]){
    int value = atoi(argv[1]);
    int index = 0;
    int length = argc;
    int i = 2;
    while(i < length){
        if(atoi(argv[i]) == value) {
            break;
        }
        else{
            ++index;
        }
        ++i;
    }
    if(i == length){
        printf("%d not found.\n", value);
    }
    else{
        printf("Found %d at %d\n", value, index);
    }
    return 0;
}
