#include <stdio.h>
#include <stdlib.h>

int main(){

    int trys, conv, pens, dgoal;
    scanf("%d\n", &trys);
    scanf("%d\n", &conv);
    scanf("%d\n", &pens);
    scanf("%d", &dgoal);
    if(0 > trys || 0 > conv || 0 > pens || 0 > dgoal){
        printf("Positive vaules only!\n");
        return 0;
    }
    else{
        int result = (trys * 5) + (conv * 2) + (pens * 3) + (dgoal * 3);
        printf("%d\n", result);
        return 0;
    }
}

