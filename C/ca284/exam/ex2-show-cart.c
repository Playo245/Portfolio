/*
Author - Daniel Pelech
Student ID - 21510383
Date - 3/11/2022
Program - ex2-show-cart.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
This script has the purpose of accepting
a list of products and printing them out
in a certain order.Also specifying if there
is a sale.
*/

//Typedef is used for simplicity.
typedef struct
{
    char name[50];
    int amount;
    float price;
    char promo[50];
} Product;

//This function declares if there is a sale.
char *sale(int binary){
    if(binary > 0){
        return "On Sale";
    }
    return "No Sale";
}

//As stated, prints out the items.
void printout(Product product){
    printf("%s,%d,%.2f,%s\n",
    product.name,
    product.amount,
    product.price,
    product.promo);
}

int main(int argc, char*argv[]){
    int length = (argc - 1)/4;
    int i, tmp, j = 0;
    Product product[100]; //Stated in the question, Max 100 items.
    for(i = 0; i < length; ++i){
        strcpy(product[i].name, argv[1 + j]);
        product[i].amount = atoi(argv[2 + j]); //This for loop assignes values to Product struct.
        product[i].price = atof(argv[3 + j]);
        char *tmp = sale(atoi(argv[4 + j]));
        strcpy(product[i].promo, tmp);
        j += 4;
    }
    for(i = 0; i < length; ++i){ //Prints out each item.
        printout(product[i]);
    }
    return 0;
}
