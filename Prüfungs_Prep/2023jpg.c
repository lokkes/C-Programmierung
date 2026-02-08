#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

  typedef struct{
   
      char vBez [25+1];
      char vNr [12+1];
      uint4_t Lbst;

   }tArt;

int main(int argc, char *argv[]){
  if(argc != 3){
	printf("usage : <quell Datei> <ziel Datei>");	
	return 0;
}

 tArt tart;

   // datei öffenen
   FILE* fp = fopen(argv[1],"rb");
   FILE* fpd=fopen(argv[2],"wb");
   

  //datei lesu und zur kontrolle anzeigen
   while(fread(&tart,sizeof(tart),1,fp)==1){

   printf("%s",tart.vBez);
   printf("%s",tart.vNr);
   printf("%u",tart.Lbst);	

  //byte oder von Lbst änderen
  unsigned char *p = (unsigned char*) &tart.Lbst;

 //swap 0 und 3 dann 1 und 2
  unsigned char tmp;
  tmp=p[0];
  p[0]=p[3];
  p[3]=tmp;

  tmp=p[1];
  p[1]=p[2];
  p[2]=tmp;

//writing to the file 
fwrite(&tart,sizeof(tart),1,fpd);

}

fclose(fp);
fclose(fpd);
   return 0;
 
}










