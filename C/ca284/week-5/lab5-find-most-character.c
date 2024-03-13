#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int most_frequent(char *string[]);

int main(int argc, char * argv[]){
    char *string = argv[1];
    char answer = most_frequent(&string);
    printf("%c\n", answer);
    return 0;
}

int most_frequent(char *string[]){
    int i, j, answer = 0;
    char character;
    char *search_str = *string;
    for(i = 0; i < strlen(search_str); ++i){
        int tmp = 0;
        for(j = 0; j < strlen(search_str); ++j){
            if(search_str[i] == search_str[j] && search_str[i] != ' '){
                ++tmp;
            }
        }
        if(tmp > answer){
            answer = tmp;
            character = search_str[i];
        }
    }
    //printf("%c\n", character);
    return character;
}
