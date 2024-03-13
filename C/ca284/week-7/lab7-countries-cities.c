#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char cout[50];
    float pop;
} Countries;

int main(int argc, char *argv[]){
    int length = (argc - 1)/7;
    int j = 0, i = 0;
    Countries countries[50];
    for(i = 0; i < length; ++i){
        strcpy(countries[i].name, argv[1 + j]);
        strcpy(countries[i].cout, argv[2 + j]);
        countries[i].pop = atof(argv[3 + j]);
        if(atof(argv[5 + j]) > countries[i].pop){
	        strcpy(countries[i].cout, argv[4 + j]);
        	countries[i].pop = atof(argv[5 + j]);
        }
        else if(atof(argv[7 + j]) > countries[i].pop){
	        strcpy(countries[i].cout, argv[6 + j]);
        	countries[i].pop = atof(argv[7 + j]);
        }
        j += 7;
    }
	for(i = 0; i < length; ++i){
		printf("%s: %s\n", countries[i].name, countries[i].cout);
	}
    return 0;
}
