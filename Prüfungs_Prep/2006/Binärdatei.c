#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
typedef struct
{

  char Name[30];
  float KlausurNote;
  float BelegNote;

} tStudent;

int main(int argc, char* argv[]){

  //eingabe parameter prüfen
   if(argc!=2){

	printf("usage : <./out> <Datei Name>");
	return 1;
   }
	
   // variablen deklaration
   tStudent tstud;
   int anzahl = 0;
   float durchschnit = 0;
   int result;
   float sum = 0;

  //Datei öffnen
   FILE* fp = fopen(argv[1],"rb");

  //datei lesen
   while(fread(&tstud,sizeof(tstud),1,fp)==1){

       float endNote = (3*tstud.KlausurNote + 2*tstud.BelegNote)/5;
       //ab und aufrunden
       int base = (int)endNote;
       float frac = endNote - base;
       
       if(frac > 0.5){

	   result = base+1;

       }

	else result = base;
	
	printf("%-30s %8.2f %8.2f %8d\n",tstud.Name,tstud.KlausurNote,tstud.BelegNote,result);
      
       anzahl++;
       sum+=result;

   }

       //leerzeichen
       printf("\n");
       printf("Durchschnit %46f\n",sum/anzahl);
       printf("Teilnehmer %46d",anzahl);

      //datei schließen
      fclose(fp);
   return 0;
}
