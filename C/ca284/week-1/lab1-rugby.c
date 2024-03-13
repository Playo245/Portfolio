#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

    int trys = atoi(argv[1]);
    int conversion = atoi(argv[2]);
    int penalty = atoi(argv[3]);
    int drop_goal = atoi(argv[4]);
    int result = (trys * 5) + (conversion * 2) + (penalty * 3) + (drop_goal * 3);
    printf("%d\n", result);
}

