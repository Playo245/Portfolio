#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){
    int i, length;
    char sentence[50];
    char reverse[50];
    strcpy(sentence, argv[1]);
    length = strlen(sentence);
    //printf("%c\n", sentence[0]);
    i = 0;
    while(i < length){
        reverse[i] = sentence[length - 1 - i];
        ++i;
    }
    printf("%s\n", reverse);
    return 0;
}
