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

float *pop_sort(float list[], int len){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	float tmp = 0;
	for(int i = 0; i < len; ++i){
		for(int j = 1 + i; j < len; ++j){
			if(list[i] > list[j]){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
	return list;
}


int main(int argc, char *argv[]){
    int length = (argc - 1)/4;
	float pop_list[length];
	float *slist;
    int j = 0, i = 0;
    Countries countries[50];
    for(i = 0; i < length; ++i){
        strcpy(countries[i].name, argv[1 + j]);
        strcpy(countries[i].cout, argv[2 + j]);
        countries[i].pop = atof(argv[3 + j]);
        pop_list[i] = atof(argv[3 + j]);
        countries[i].size = atoi(argv[4 + j]);
        j += 4;
    }
	slist = pop_sort(pop_list, length);
	for(i = 0; i < length; ++i){
		for(j = 0; j < length; ++j){
		//	printf("%.2f\n", *(slist + length - 1 - i));
			if(countries[j].pop == *(slist + (length - i - 1))){
				printout(countries[j]);
			}
		}
	}
    return 0;
}
