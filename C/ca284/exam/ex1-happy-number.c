/*
Author - Daniel Pelech
Student ID - 21510383
Date - 6/10/2022
Program - ex1-happy-number.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
2 functions, main and ishappy. Ishappy takes care of calculating the sum of the number
which then is returned to the main function. The while loop in the main function repeats
the process until "number" is equal too 1 to be happy or 4 meaning the number cannot ever equal to 1
*/
int ishappy(int number);

int main(int argc, char *argv[]){
    int number;
    number = atoi(argv[1]);
    while(number != 1 && number != 4){
        number = ishappy(number);
    }

    if(number == 1){
        printf("is happy\n");
    }

    else{
        printf("not happy\n");
    }
    return 0;
}

int ishappy(int number){
    int remainder, answer;
    remainder = 0;
    answer = 0;

    while(number > 0){
        remainder = number % 10;
        answer = answer + (remainder*remainder);
        number = number / 10;
    }
    return answer;
}
