#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char cout[50];
    float pop;
    int size;
} Country;

void printout(Country player1){
    printf("%s\n%s\n%.2f million people\n%d km2\n", player1.name, player1.cout, player1.pop, player1.size);
}

int main(int argc, char *argv[]){
    Country player1;
    strcpy(player1.name, argv[1]);
    strcpy(player1.cout, argv[2]);
    player1.pop = atof(argv[3]);
    player1.size = atoi(argv[4]);
    printout(player1);
    return 0;
}
