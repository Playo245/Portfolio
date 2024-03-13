#include <stdio.h>
int main(void)
{
    int count = 0;                               // Declared in outer block
    do
    {
        ++count;
        printf("count = %d\n", count);
    }
    while( ++count <= 5);
    printf("count1 = %d\n", count);
    return 0;
}
