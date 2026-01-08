#include <stdio.h>
#include <stdlib.h>

typedef void(*f)(int i);
f fptr;

void fprintdec(int i){
    printf("%d\n",i);
}

void printhex(int i){
    printf("%x\n",i);
}

void fprintxx(void (*fctp)(int),int i){
    fctp(i);
}

f choice(int i)

    {
        if (i) return printhex;// this is a pointer returned to the f 
        else return fprintdec;// this is also a pointer 
    }

f arr[] = {fprintdec,printhex};


int main(int argc, char *argv[]){


    int i = atoi(argv[1]);
    fptr = fprintdec;
    fptr(i);

    fptr = printhex;
    fptr(i);

    fprintxx(fprintdec,i);
    fprintxx(printhex,i);

    choice(0)(i);
    choice(1)(i);

    arr[0](i);
    arr[1](i);



return 0;
}