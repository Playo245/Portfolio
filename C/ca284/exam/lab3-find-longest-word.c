#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findword(char list[], int length);


int main(int argc, char *argv[]){
    int length;
    char sentence[50];
    strcpy(sentence, argv[1]);
    length = strlen(sentence);
    //printf("%d\n", length);
    findword(sentence, length);
    return 0;
}

void findword(char list[], int length){
    int i;
    int longest = 0;
    int tmp = 0;
    for(i = 0; i < length; ++i){
        if(list[i] == ' '){
            if(tmp > longest);
                longest = tmp;
        }
        else{
            ++tmp;
        }
    printf("%d", longest);
    }
}
