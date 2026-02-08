#include <stdio.h>
#include <stdlib.h>



typedef struct
{
	unsigned int pid;
	char name[32]; /* Null-terminiert, falls krzer */
	float cpu; /* CPU-Auslastung in Prozent */
	float mem; /* RAM-Anteil in Prozent */
} tProc;

int main(int argc, char* argv[]){

  if(argc!=2){

	fprintf(stderr,"usage : ./%s Datei Name",argv[0]);
	return -1;
   }

 tProc tproc;
 FILE* fp = fopen(argv[1],"rb");
 if(fp == NULL){

fprintf(stderr,"file open failed");
 return -1;

}

printf("PID  NAME  CPU(%)  MEM(%)\n");

int anzahlcpu = 0;
int anzahltreff = 0;

 while(fread(&tproc,sizeof(tproc),1,fp)==1){

	if(tproc.cpu > 80){

		printf("%u %-32s %.1f %.1f\n",tproc.pid,tproc.name,tproc.cpu,tproc.mem);
		anzahltreff++;
	}
		anzahlcpu++;
		
 }

printf("\n");
printf("anzahl Daten satz : %d\n",anzahlcpu);
printf("Treffer > 80% CPU : %d\n",anzahltreff);

fclose(fp);

  return 0;
}

