#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[128];

int main(int argc, char* argv[]){

char* token;
double lowtemp;//low temperature over all lines
double lowtemp_line;//low temperature per line
int first=1; 
char minline[128];

 if(argc != 2){

	fprintf(stderr,"Usage : <./%s> <Filename>",argv[0]);
	return -1;

  }

  FILE* fp = fopen(argv[1],"r");
 //fehler behandlung ordner öffenung
 if(fp == NULL){
	
	fprintf(stderr,"fehler beim ordner öffenen");
	return -1;
 }


  while(fgets(buf,sizeof(buf),fp)!=NULL){
	
	char linecopy[128];
	strcpy(linecopy,buf);

	char *p = strchr(buf, ' ');
	if(!p) continue;
	p++;
	token = strtok(p, ",");

	double val=atof(token);
	lowtemp_line = val;

		while(token != NULL){
 	        token = strtok(NULL, ",");
                if(token == NULL) break;
                val = atof(token);
                if(val < lowtemp_line) lowtemp_line = val;
	}

	
	if(first || lowtemp_line < lowtemp){
	 lowtemp = lowtemp_line;
	strcpy(minline,linecopy);
	first=0;	
	}
  }  

	fclose(fp);
	printf("Minimal Temperatur : %.1f\n",lowtemp);
	printf("%s",minline);

	
  return 0;
}
