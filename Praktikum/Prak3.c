#include <stdio.h>
#include <stdlib.h>

char vBuf[128];

int main(){

    int i1,i2;
    unsigned int u1,u2;

    printf("Enter integer 1 : ");
    fgets(vBuf, 128, stdin);
    i1 = atoi(vBuf);
    u1 = i1;

    printf("Enter integer 2 : ");
    fgets(vBuf, 128, stdin);
    i2 = atoi(vBuf);
    u2 = i2;


    printf("i1 : %10d %08x ",i1, i1);
    printf("i2 : %10d %08x \n",i2, i2);
    printf("u1 : %10u %08x ",u1,u1);
    printf("u2 : %10u %08x \n",u2,u2);

    int in1 = (i1 << 3) + (i1 << 1);
    int in2 = (i2 << 3) + (i2 << 1);
    int uin1 = (u1 << 3) + (u1 << 1);
    int uin2 = (u2 << 3) + (u2 << 1);


    printf("When its Multiplied by 10 : ");
    printf(" %d %d %u %u ",in1, in2, uin1, uin2);


    return 0;
}