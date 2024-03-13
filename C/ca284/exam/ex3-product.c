/*
Author - Daniel Pelech
Student ID - 21510383
Date - 30/11/2022
Program - ex3-product.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Struct for this task.
*/
typedef struct Product Product;

struct Product {
    char Code[100];
    char Country[100];
    int Price;
    Product *next;
};

/*
The function downbelow find the product.
*/
Product* fillList(char *argv[], int length) {
	Product *current, *first;
    first = (Product*)calloc(1,sizeof(Product));
	current = first;
    strcpy(current->Code, argv[1]);
    strcpy(current->Country, argv[2]);
    current->Price = atoi(argv[3]);
    for (int i = 1; (i * 3) + 1 < length - 1; i++) {
        current->next = (Product*)calloc(1,sizeof(Product));
	    current = current->next;
        strcpy(current->Code, argv[(3 * i) + 1]);
        strcpy(current->Country, argv[(3 * i) + 2]);
        current->Price = atoi(argv[(3 * i) + 3]);
    }
    return first;
}

void printLinkedList(Product *LinkedList) {
	Product* current = NULL;
	for(current = LinkedList; current != NULL; current = current->next)
	{
        printf("%s\n", current->Code);
        printf("%s\n", current->Country);
        if (strcmp(current->Country, "Ireland") == 0) {
            float price = current->Price * 1.20;
            printf("%.0f\n", price);
        } else {
            printf("%d\n", current->Price);
        }
	}
}

int main(int argc, char*argv[]) {
    int length = argc;
    Product *LinkedList;
    LinkedList = fillList(argv, length);
    printLinkedList(LinkedList);
    return 0;
}

