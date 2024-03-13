/*
Author - Daniel Pelech
Student ID - 21510383
Date - 13/12/2022
Program - ex4-label-product.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
The Following code has 2 functions, main and printout.
The reason I didnt make a seprate function for creating a linked list,
is because I had many error regarding of getting the mean.
*/

//Down below I got my struct
typedef struct Product Product;

struct Product{
    char item[20];
    float price;
    int sold;
    int status;
    Product *next;
};

//This function takes care of finding the status and printing the variables
void printout(Product *start, float mean){
    Product *tmp = NULL;
    char var1;
    for(tmp = start; tmp != NULL; tmp = tmp->next){
        float revenue = tmp->price * tmp->sold;
        if(revenue > mean){
            printf("1\n");
        } else {           //Find if the status is greater or below the mean
            printf("0\n");
        }
        switch (tmp->item[0] + tmp->item[1]){//Check which country belong to code,Example "IE" == Ireland
            case 'S' + 'P':
                printf("Spain\n");
                break;
            case 'F' + 'R':
                printf("France\n");
                break;
            case 'I' + 'E':
                printf("Ireland\n");
                break;
            case 'U' + 'S':
                printf("USA\n");
                break;
            case 'R' + 'U':
                printf("Russia\n");
                break;
        }
    }
}

//The creation of the linked-list is assisiated with the "main" function.
int main(int argc, char *argv[]){
    Product *current, *start, *next;

    int length = (argc - 1) / 3;// Divided by 3 as each country has 3 assosiated values
    int count = 3;
    int var = 1;
    float mean;
    start = (Product*)calloc(1, sizeof(Product));
    current = start;
    strcpy(current->item, argv[1]);
    current->price = atof(argv[2]);
    current->sold = atoi(argv[3]);
    current->status = 0;
    mean += current->price * current->sold;
    for(int i = 1; i < length; ++i){
        current->next = (Product*)calloc(1, sizeof(Product));// This forloop makes the Linkedlist.
        current = current->next;
        strcpy(current->item, argv[1 + count]);
        current->price = atof(argv[2 + count]);
        current->sold = atoi(argv[3 + count]);
        current->status = 0;
        mean += current->price * current->sold;//Adds each coutry to the mean
        count += 3;
        ++var;
    }
    mean = mean / var;// Then its divides by var, which is the amount of countries.
    //printf("%.2f", mean);
    printout(start, mean);
    free(start);
    return 0;
}
