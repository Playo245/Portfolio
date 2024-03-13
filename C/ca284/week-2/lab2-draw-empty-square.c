#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{

    if(argc == 1){
        printf("No input given!");
        return 0;
    }

    int size = atoi(argv[1]);

    for(int j = 0; j < size; ++j) {
        printf("*");
    }

    printf("\n");

    for(int i = 1; i < size - 1; ++i) {

        for(int j = 0; j < size; ++j) {

            if((j == 0) || (j == size - 1))
                printf("*");

            else
                printf(" ");
        }

        printf("\n");
    }

    for(int j = 0; j < size; ++j)
        printf("*");
    printf("\n");

    return 0;
}
