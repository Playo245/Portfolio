/*
Author - Daniel Pelech
Student ID - 21510383
Date - 13/12/2022
Program - ex4-attendance.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
For this program I have two functions, findstatus and main.
The main fuction take care assembling the pointer, while findstatus
finds if the student had an absent check for more or equal two 3.
*/

typedef struct
{
    char log[50];
    int status;
} Attendance;

//This function here is findstatus
void findstatus(Attendance *pAttendance){
    int count = 0;//Counts all the absents.
    int late = 0;//These are all the lates found in a row
    int length = strlen(pAttendance->log);
    for(int i = 0; i < length; ++i){
        char var = pAttendance->log[i];
        if(var == 'L'){
            ++late;
        } else if(var == 'A'){
            ++count;
        } else {
            if(late % 3 != 0){
                late = 3 * (late / 3);//Checks if there was atleast 3 lates in a row.
            }
        }
    }
    int absents = late / 3;//If there where any lates in a row.
    count += absents;
    if(count >= 3){
        pAttendance->status = 1;
    } else {                    //These 2 statements determains the attendance status
        pAttendance->status = 0;
    }
}

int main(int argc, char *argv[]){
    Attendance *pAttendance;
    int length = argc - 1;
    pAttendance = (Attendance*)calloc(length, sizeof(Attendance));
    if(!pAttendance){
        printf("Not enough memory, Exiting.\n"); //Check if memory was allocated.
        free(pAttendance);
        pAttendance = NULL;
        exit(0);
    }
    for(int i = 0; i < length; ++i){
        strcpy((pAttendance + i)->log, argv[1 + i]);
        findstatus((pAttendance + i));
        printf("%d\n", (pAttendance + i)->status);// Prints the status of the student.
    }
    free(pAttendance);//Frees the memory
    pAttendance = NULL;
    return 0;
}
