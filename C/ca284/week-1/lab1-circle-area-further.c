#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[])
{
	int radius = 0;
	float area = 0;
    if (argc > 2 || argc < 2) {
         printf("Please provide the radius as a command line argument\n");
         return 0;
    }
    if (atoi(argv[1]) < 0) {
        printf("Please provide a positive radius!\n");
        return 0;
    }
	radius = atoi(argv[1]);
	radius = radius*radius;
    area = radius*PI;
    printf ("%.2f\n", area);
    return 0;
}
