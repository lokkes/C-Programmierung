#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

char vBuf[128];
/* double PowInt(int x, int y); */

int main(){

    printf("Eingabe Base : ");
    fgets(vBuf,128,stdin);
    int b = atoi(vBuf);

    printf("Eingabe Power : ");
    fgets(vBuf,128,stdin);
    int p = atoi(vBuf);

    double result = PowInt(b,p);
    printf(" %d to the power %d is : %f", b ,p ,result);

    return 0;
}

