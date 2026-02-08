#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]){


       if (argc != 4){

	    printf("Usage : <ProgramName> <x1> <xn> <n()anzahl der unterteilung>")
	    return 1;
	}

	double x = atoi(argv[1]);
        double xn = atoi(argv[2]);
	double n = atoi(argv[3]);

	float width = 0;
	float area = 0;

	width = (xn - x)/n

	for(int i = 0 i<n; i++){

	area += ( f(x) + f(x+width) ) / 2  *  width;
	x+=width;
	
	}


	printf("the Area is : %f",area)
	return 0;	
}
