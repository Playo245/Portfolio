#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordfinder(char *string1[], char *string2[]){
    char *word = *string2;
    char *string = *string1;
    int start, finish;
    int amount = 0;
    for(int i = 0; i < strlen(string); ++i){
        if(word[0] == string[i]){
            for(int j = 0; j < strlen(word); ++j){
                if(word[j] == string[j + i] && string[j + i] != '\0'){
                    ++amount;
                }
            if(amount == strlen(word)){
                start = i;
                finish = amount + i - 1;
            }
            }
        }
    }
    printf("%d %d\n", start, finish);
}

int main(int argc, char *argv[]){
    char *string1 = argv[1];
    char *string2 = argv[2];
    wordfinder(&string1, &string2);
    return 0;
}
