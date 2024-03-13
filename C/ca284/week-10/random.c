#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Student */
typedef struct Student Student;

struct Student {
	char name[20];
	char programme[20];
	float grade;
	Student *next;
};

/*Functional prototype */
Student* get_students(); /* You may notice that the function get_students return the type Student*, implying that the function will return a pointer that points to a Student */

int main()
{
	Student *start = NULL;

	start = get_students();
	return 0;
}

Student* get_students() /* This mean that the function will return a pointer that points to the structure Student */
{
	Student *current, *first; /*declare two pointers */
	first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	return first; /* return the address of the first node */
}
