#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    int day = atoi(argv[1]);
    char week[][9] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("%s\n", week[day - 1]);
    return 0;
}
