#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char vBuf[128];

int main(){

    printf("To find e^x,  Enter the value of x : ");
    fgets(vBuf,128,stdin);
    int x = atoi(vBuf);


    int n = 1;
    double term = 1.0;
    double y = 1.0;

    while(term > 0.00005){
        term = term * x / n ; // if we see from the formulea its starting from 2nd term as first term is aldready intialised 
        y = y + term;
        n++;
    }
  /*       do {
        term = term * x / n ; // if we see from the formulea its starting from 2nd term as first term is aldready intialised 
        y = y + term;
        n++;
    } while(term > 0.00005); */

  /*   for(n = 1; n>0.0001; n++){
        term = term * x / n ; // if we see from the formulea its starting from 2nd term as first term is aldready intialised 
        y = y + term;
        n++;
    } */

        printf("Ergebniss %lf ",y);
        return 0;
}