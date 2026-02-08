#include <stdio.h>
#include <stdlib.h>

double factorial(int k);
int main(int argc, char* argv[]){
	
  if(argc != 3){
	
     fprintf(stderr"Enter : ./progname  x and n");
     return -1;	

  }

  double x = atof(argv[1]);
  int n = atoi(argv[2]);
  double calc = 0.0;
  double result = 1;

  for(int k = 0; k=<n; k++){
	 
	cacl += result/factorial(k);	
	result *=x;
  }

  printf("output : \n");
  printf("%lf %d --> %lf",x,n,cal);

  return 0;

}

double factorial(int k)
{
    if (k == 0) return 1.0;
    double fac = k;
    int kPrev = k - 1;

    while (kPrev > 1) {
        fac *= kPrev;
        kPrev--;
    }
    return fac;
}
