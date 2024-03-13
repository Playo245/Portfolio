#include <stdio.h>

int main (void)
{

    char letter = 'A';
    char *pletter;

    pletter = &letter;
    pletter +=1;
    printf ("The address of the letter variable is: %p\n\nThe value stored in letter is: %d\n\nThe actual letter is: %c\n\n",&letter,letter,letter);

    printf("letterPTR points at memory address: %p\n\nThe actual data it has access to is: %c\n\n",pletter,*pletter);
    return (0);
}
