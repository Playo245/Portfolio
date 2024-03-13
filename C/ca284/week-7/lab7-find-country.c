#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char cout[50];
    float pop;
    int size;
} Countries;

void printout(Countries countries){
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", countries.name, countries.cout, countries.size, countries.pop);
}

int main(int argc, char *argv[]){
    int length = (argc - 1)/4;
    int j = 0;
    Countries countries[50];
    for(int i = 0; i < length; ++i){
        strcpy(countries[i].name, argv[1 + j]);
        strcpy(countries[i].cout, argv[2 + j]);
        countries[i].pop = atof(argv[3 + j]);
        countries[i].size = atoi(argv[4 + j]);
        j += 4;
    }
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for(int i = 0; i < length; ++i){
		if(countries[i].size < 100000){
	        printout(countries[i]);
		}
    }
    return 0;
}
