#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(int argc, char *argv[])
{
	int radius = 0;
	float area = 0.0;
	int digit = 0;
	radius = atoi(argv[1]);
	if(0 > radius){
	    printf("Radius must be a postive number.\n");
	    return (0);
	}
	else{
	    radius = radius*radius;
	    area = radius*PI;
        printf("%0.2f\n", area);
        return (0);
    }
}
