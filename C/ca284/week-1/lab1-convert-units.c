#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){

    int centimetres = atoi(argv[1]);
    float inches = centimetres / 2.54;
    printf("%.2f\n", inches);
}
