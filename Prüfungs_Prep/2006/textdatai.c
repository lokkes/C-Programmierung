#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[256];

int main(int argc, char* argv[]){


if(argc != 3){

   printf("<usage> : <./Programname> <DateiName> <gesuchtes wort>");
   return 1;
}


//open file
FILE* fp = fopen(argv[1],"r");
FILE *out = fopen("Datei/tmp/find_x.txt","w");

while(fgets(buf,sizeof(buf),fp)!=NULL){

	if(strstr(buf,argv[2])!=NULL){

	     fputs(buf,out);

	}


}

	fclose(fp);
	fclose(out);

	 return 0;


}
	
