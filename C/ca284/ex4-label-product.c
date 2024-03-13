/*
* Author: Duarte Martinho
* Purpose: Accepts the information of a list of items in a cart at a grocery. Each item in the cart contains the following information:
* - Item Code (you can assume it is a sequence of maximum 20 characters)
* - Price (a floating number - price per item)
* - Number of item sold (a positive integer)
* - Status (receiving two value 0 or 1, initial value is 0)
The program prints the status and country of origin of each item line by line.
* Date: 09/12/2021
* Language:  C
*/

/* My Approach
* - Started by making the struct and the linked list 
* - Then I filled the link list and kept track of the total sales
* - Then moved on into the print function
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAXLEN 50
#define MAXCARTS 50

typedef struct Cart Cart;

struct Cart {
    char Code[MAXLEN];
    int Price;
    int Sold;
    int Status;
    Cart *next;
};



/* Function Prototypes */
void printLinkedList(Cart *first, float sales);

int main(int argc, char*argv[]) {
    int totalSales = 0, numCarts = (argc - 1) / 3;
    Cart *current, *first;
    first = (Cart*)calloc(1,sizeof(Cart));
	current = first;
    strcpy(current->Code, argv[1]);
    current->Price = atoi(argv[2]);
    current->Sold = atoi(argv[3]);
    current->Status = 0;
    for (int i = 1; i < (argc - 1) / 3; i++) {
        current->next = (Cart*)calloc(1,sizeof(Cart));
	    current = current->next;
        strcpy(current->Code, argv[(i * 3) + 1]);
        current->Price = atoi(argv[(i * 3) + 2]);
        current->Sold = atoi(argv[(i * 3) + 3]);
        current->Status = 0;
        totalSales += current->Price * current->Sold;
    }
    float avgSales = totalSales / numCarts;
    printLinkedList(first, avgSales);
    return 0;
}

/*
* Function Name: printLinkedList
* Description: Prints Linked List
* Args: Cart Linked List as a pointer, float of average sales
* Returns: no return (VOID)
*/
void printLinkedList(Cart *LinkedList, float sales) {
	Cart* current = NULL;
	for(current = LinkedList; current != NULL; current = current->next)
	{   
        if (sales < current->Price * current->Sold) { printf("1\n"); } else { printf("0\n"); }
        switch (current->Code[0] + current->Code[1]) {
            case 'I' + 'E':
                printf("Ireland\n");
                break;
            case 'F' + 'R':
                printf("France\n");
                break;
            case 'S' + 'P':
                printf("Spain\n");
                break;
            case 'R' + 'U':
                printf("Russia\n");
                break;
            case 'U' + 'S':
                printf("USA\n");
                break;
        }
	}
}