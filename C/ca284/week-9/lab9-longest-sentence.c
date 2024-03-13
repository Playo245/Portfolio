#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]){
    int length = argc - 1;
    int largest = 0;
    int memory = 0;
    int *plargest = &largest;
    char *pString = calloc(length, sizeof(char));
    if(!pString){
        printf("Unfortunately memory reallocation failed.\n");
        free(pString);
        pString = NULL;
        return 0;
    }
    for(int i = 0; i < length; ++i){
        if(strlen(argv[1 + i]) > *plargest){
            *plargest = strlen(argv[1 + i]);
        }
    }
    for(int i = 0; i < length; ++i){
        if(strlen(argv[1 + i]) == *plargest){
            printf("%s\n", argv[1 + i]);
        }
    }
    free(pString);
    pString = NULL;
    return 0;
}
