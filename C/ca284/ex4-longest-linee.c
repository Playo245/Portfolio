/*
Author - Daniel Pelech
Student ID - 21510383
Date - 13/12/2022
Program - ex4-longest-line.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
The program down below will has 3 functions, which
work together inorder to find the chosen sentence
*/

typedef struct Product Product;

struct Product{
    char *sentence;
    int length;
    Product *next;
};

//The function down below creates "node" to the linked-list.
void adding_node(Product **start, char *sentence, int length){
    Product *new_node, *current;
    new_node = (Product *)calloc(1, sizeof(Product));//Allocating space for the new node.
    new_node->length = length;
    new_node->sentence = sentence;
    new_node->next = NULL;
    if(*start == NULL){//Making sure that we arent assign to nothing.
        *start = new_node;
    } else {
        current = *start;
        while(current->next != NULL){//Lookin for the tail of the linked-list.
            current = current->next;
        }
        current->next = new_node;//Adds it to the linked-list.
    }
}

/*
The function down below handles the spliting the long
string of sentences into actual sentences.
*/
void making_sentence(char *string, Product **start){
    char *sentence = (char *)calloc(200, sizeof(char));//Allocating memory for each sentence.
    int quote = 0;//This will be used to know if a quote was found.
    int i = 0;
    int length = 0;
    while(*string != '\0'){//Checking and adding each character to the list "sentence".
        if(*string == '\''){//This checks if its a quote.
            quote = !quote;
            sentence[i] = *string;//Assigning each character from string to the sentence.
            ++i;
            ++length;
            ++string;
        }
        if(quote || (*string != '.' && *string != '?')){
            if(length > 0 || *string != ' '){
                sentence[i] = *string;
                ++i;
                ++length;
            }
        } else if (!quote && (*string == '.' || *string == '?')){//Both if statement here, determine if
            sentence[i] = *string;
            i++;
            length++;
            adding_node(start, sentence, length);
            sentence = (char *)calloc(200, sizeof(char));
            i = 0;
            length = 0;
        }
        string++;
    }
}

void printout(Product *start, int Short){
    Product *current = start;
    int min = current->length;
    int max = current->length;

    while(current != NULL){
        if(current->length > max){
            max = current->length;
        }
        if(current->length < min){
            min = current->length;
        }
        current = current->next;
    }
    current = start;

    while(current != NULL){
        if((current->length == max && !Short) || (current->length == min && Short)){
            printf("%d\n", current->length);
            printf("%s\n", current->sentence);
        }
        current = current->next;
    }
}

int main(int argc, char *argv[]){
    Product *start = NULL;
    char *string = argv[1];
    char *choice = argv[2];
    int Short = 0;

    if(!strcmp(choice, "shortest")){
        Short = 1;
    } else if(strcmp(choice, "longest") && strcmp(choice, "shortest")){
        printf("Not valid!\n");
        return 0;
    }
    making_sentence(string, &start);
    printout(start, Short);

    return 0;
}
