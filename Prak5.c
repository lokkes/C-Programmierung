#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char vBuf[128];

double Sinian(double x){
    double pterm = x;
    double summand = 0;
    double xvalue = x;
    for(int i = 0; fabs(pterm) >= 0.0001; i++){

       double nterm = (pterm * -(xvalue*xvalue)) / ((2*i+2)*(2*i+3)) ; 
       summand += pterm; 
       pterm = nterm;
                                                                                                         
    }
    return summand;
}

int main(){

    //value x Eingabe
    printf("Eingabe von X wert : ");
    fgets(vBuf,128,stdin);
    int x = atoi(vBuf);

    //sinus wert berechnung
    printf("sin(%d) = %f",x, Sinian(x));
    return 0;
}