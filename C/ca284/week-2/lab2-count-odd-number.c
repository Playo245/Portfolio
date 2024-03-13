#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    int length = argc - 1;
    int odds = 0;
    int numbers[length];
    for(int i = 0; i < length; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }

    for(int i = 0; i < length; ++i) {
        if(numbers[i] % 2 == 1) {
            odds += 1;
        }
    }
    printf("%d\n", odds);
    return 0;
}
