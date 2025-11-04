#include <stdio.h>
#include <stdlib.h>
#include <xlocale.h>

char vBuf[128];

int main(){

    //Variable declaration
    double D,R,A;
    int PI = 314;

    //Nutzer Eingabe
    printf("Eingabe des Durchmessers in mm: ");
    fgets(vBuf,128,stdin);
    D = atof(vBuf);

    //flächeninhalt berechnen 
    printf("Berechnung der Kreisflaeche\n");
    D = D/10; // convert in cm 
    R = D/2;
    A = (PI/100.0) * (R*R);

    printf("Flaecheninhalt in cm²: %4lf", A);

    return 0;

}