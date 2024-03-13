#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char name[20];
    char programme[20];
    float grade;
} Student;

void studentlist(Student *student, char *name, char *programme, float grade){
    strcpy(student->name, name);
    strcpy(student->programme, programme);
    student->grade = grade;

}

void printout(Student *student){
    printf("%s, %s, %.2f\n", student->name, student->programme, student->grade);
}

int main(int argc, char *argv[]){
    int students = (argc - 1) / 3;
    int length = argc - 1;
    int start = 2;
    int j = 0;
    Student *pStudents;
    pStudents = (Student*)malloc(start * sizeof(Student));
    if(!pStudents){
        printf("Unfortunately memory reallocation failed.\n");
        free(pStudents);
        pStudents = NULL;
        return 0;
    }
    for(int i = 0; i < length; i += 3){
        if(students > start){
            start = students;
            pStudents = (Student*)realloc(pStudents, students * sizeof(Student));
            if(!pStudents){
                printf("Unfortunately memory reallocation failed.\n");
                free(pStudents);
                pStudents = NULL;
                return 0;
            }
        }
        studentlist(&pStudents[i], argv[1 + i], argv[2 + i], atof(argv[3 + i]));
        printout(&pStudents[i]);
    }
    free(pStudents);
    return 0;
}
