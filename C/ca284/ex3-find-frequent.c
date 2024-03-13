/*
* Author: Duarte Martinho
* Purpose: Finds and displays frequent elements from a list of integers.
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function Prototypes */
void looparray(int *array, int length);
void sortarray(int *array, int length);
void printarray(int *array, int length);
void makefinalarray(int *array, int *currentLength, int val, int count);

int main(int argc, char*argv[]) {
    int length = argc - 1;
    int *array = (int*)malloc(sizeof(int) * (5));
    for (int i = 0; i < length; i++) {
        *(array + i) = *(int*)malloc(sizeof(int) * (1)); // Allocate memory for the next element
        *(array + i) = atoi(argv[i + 1]);
    }
    looparray(array, length);
    free(array);
    return 0;
}

/*
* Function Name: looparray
* Description: loops throught the given array and checks the count of the elements
* Args: array and length of array
* Returns: no return (VOID)
*/
void looparray(int *array, int length) {
    sortarray(array, length);
    int *newArray = (int*)malloc(sizeof(int) * (5));
    int i, newLength = 0;
    for (i = 0; i < length; i++ ){
        int count = 1, j = i + 1;
        while (array[j] == array[i]) {
            // printf("iterate while %d\n", count);
            count++;
            j++;
        }
        if (count > 3) {
            // printf("count - %d | val - %d\n", count, array[i]);
            for (int k = 0; k < count; k++) {
                *(newArray + (newLength + k)) = *(int*)malloc(sizeof(int) * (1)); // Allocate memory for the next element
                *(newArray + (newLength + k)) = array[i];
            }
            newLength += count;
            i += count;
        }
    }
    printarray(newArray, newLength);
    free(newArray);
}

/*
* Function Name: sortarray
* Description: sorts the given array
* Args: array and length of array
* Returns: no return (VOID)
*/
void sortarray(int *array, int length) {
    for (int i = 0; i < length; i++ ){
        for (int j = 0; j < length; j++) {
            if (array[j] > array[i]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

/*
* Function Name: printarray
* Description: Prints Array
* Args: array and length of array
* Returns: no return (VOID)
*/
void printarray(int *array, int length) {
    for (int i = 0; i < length; i++ ){
        printf("%d\n", array[i]);
    }
}