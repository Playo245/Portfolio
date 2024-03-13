/*
Author - Daniel Pelech
Student ID - 21510383
Date - 13/12/2022
Program - ex4-duplicate-remover.c
*/

#include <stdio.h>
#include <stdlib.h>

/*
For the following code, I started with a linked-list which I
wasnt able to manupliate without creating a new linked list.
Therefore I used a single array.
*/

//This functions down below is reponsible for removing
//element that occured more than once.
int rm_duplicates(int nums[],int len){
    int count, i, j, a;
    for(i = 0; i < len; ++i){
        count = 0;
        for(int j = i + 1; j < len; ++j){
            if(nums[i] == nums[j]){
                count = 1;
                for(a = j; a < len - 1; ++a){
                    nums[a] = nums[a + 1];//Moves each integer to the left.
                }
                len -= 1;
                j -= 1;
            }
        }
        if(count == 1){
            for(a = i; a < len - 1; ++a){
                nums[a] = nums[a + 1];//The process for both loop which include
            } // "a" is to overwrite each varaible and reduce the length by one
            len -= 1;
            i -= 1;
        }
    }
    //Now that the array has all its duplicates removed, we can print it.
    for(i = 0; i < len; ++i){
        printf("%d\n", nums[i]);
    }
}

int main(int argc, char *argv[]){
    int length = argc - 1;
    int integers[length];
    for(int i = 0; i < length; ++i){
        integers[i] = atoi(argv[1 + i]);//Assign each variable for command-line too array.
    }
    rm_duplicates(integers, length);
    return 0;
}
