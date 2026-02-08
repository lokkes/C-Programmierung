#include <stdio.h>
#include <stdlib.h>


typedef struct{
		
	double x;
	double y;	
	
}paare;	

paare *foo(double x, double w, int n, double (*f)(double));
double square(double x);

int main(){

  int n = 10;
  paare *arr = foo(0,1,10,square);

  for(int i = 0; i<n; i++){

	printf("x : %.3f  y=f(x) : %.3f",arr[i].x,arr[i].y);	
	
  }

  free(arr);
  return 0;



}

double square(double x){
	
	return x*x;	
}

paare *foo(double x, double w, int n, double (*f)(double)){
	
	int i;
	paare *ptr = malloc(n*sizeof(paare));//with n we know how much paare we need so dont need realloc
	if(ptr == NULL) return -1;
	
	double xi = x;
	for(i = 0; i<n; i++){
 		
		ptr[i].x=xi;
		ptr[i].y=f(xi);
		xi+=w;
	}

	return ptr;
}



