#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findchar(char *letter[], char *string[]);

int main(int argc, char * argv[]){
    char *letter = argv[1];
    char *string = argv[2];
    //printf("%s\n", string);
    char answer = findchar(&letter, &string);
    printf("%c\n", answer);
    return 0;
}

int findchar(char *letter[], char *string[]){
    int i, answer = 0;
    char *search_str = *string;
    char *character = *letter;
    for(i = 0; i < strlen(search_str); ++i){
        if(*character == search_str[i]){
            ++answer;
        }
    }
    return answer;
}
