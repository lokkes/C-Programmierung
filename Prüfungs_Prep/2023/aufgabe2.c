#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



char* Fileconcat(char* pfad, char*Dateiname,char*ext){
	
time_t now = time(NULL);
struct tm *t = localtime(&now);

int year = t->tm_year + 1900;
int month = t->tm_mon + 1;
int date = t->tm_mday; 

char* strptr = malloc(strlen(pfad)+strlen(Dateiname)+strlen(ext)+12); 		
sprintf(strptr,"%s%s_%04d_%02d_%02d%s",pfad,Dateiname,year,month,date,ext);

return strptr;
}
