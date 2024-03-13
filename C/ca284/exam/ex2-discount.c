/*
Author - Daniel Pelech
Student ID - 21510383
Date - 3/11/2022
Program - ex2-discount.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
This script, really similar to "ex2-show-cart.c"
has the task of getting the final price of all
the products on the list. Also the script will
lower down the final price if there is a sale.
*/

//Typedef is used for simplicity.
typedef struct
{
    char name[50];
    int amount;
    float price;
    char promo[7];
} Product;

//This function declares if there is a sale.
char *sale(int binary){
    if(binary > 0){
        return "On Sale";
    }
    return "No Sale";
}

/*
As the for loop goes through every item in main function, the
price is add throught pointer.
*/
void calc(Product product, float *psum){
    int value = strcmp(product.promo, "No Sale");
    if(value == 0){
        *psum += product.amount * product.price;
    } else {
        int free = product.amount / 3;
        *psum += (product.amount - free) * product.price;
    }
}

//As stated, prints out the sum/final price.
void printout(float sum){
    printf("%.2f\n", sum);
}

int main(int argc, char*argv[]){
    int length = (argc - 1)/4;
    int i, tmp, j = 0;
    float sum;
    float *psum = &sum;
    Product product[100]; //Stated in the question, Max 100 items.
    for(i = 0; i < length; ++i){
        strcpy(product[i].name, argv[1 + j]);
        product[i].amount = atoi(argv[2 + j]);
        product[i].price = atof(argv[3 + j]); //This for loop assignes values to Product struct.
        char *tmp = sale(atoi(argv[4 + j]));
        strcpy(product[i].promo, tmp);
        j += 4;
    }
    for(i = 0; i < length; ++i){
        calc(product[i], psum); //Sums up the price of all products.
    }
    printout(sum);
}
