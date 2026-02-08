#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
   if(argc!=3){
	fprintf(stderr,"Usgae : <%s> <quell datei> <ziel datai>",argv[0]);
	return -1;
   }
  FILE* fp = fopen(argv[1],"rb");
  if(fp==NULL){
	fprintf(stderr,"cannot open input file");
	return -1;
  }
   FILE* outptr = fopen(argv[2],"wb");
     if(outptr==NULL){
        fprintf(stderr,"cannot open output file");
	fclose(fp);
        return -1;
  }
   tArt tart;
   while(fread(&tart,sizeof(tart),1,fp)==1){
  // 4 bits genai umdrehen
   unsigned char* p = (unsigned char*) &tart.Lbst;
  //byte von idex 0 und 4 swappen
   unsigned char tmp;
   tmp = p[0];
   p[0]=p[3];
   p[3]=tmp;
  //byte von index 1 und 2 swap
   tmp = p[1];
   p[1] = p[2];
   p[2] = tmp;
  //die geänderte Datensätzte zur kontrolle zeigen
  printf("%-26s %-13s %-8u\n",tart.vBez, tart.vNr, tart.Lbst);
  //in ziel datei schreiben 
  if(fwrite(&tart,sizeof(tart),1,outptr)!=1){
        fprintf(stderr,"Fehler in datei schreiben");
        fclose(fp);
        fclose(outptr);
        return -1;
    }
  }	
   //closeing the file
   fclose(fp);
   fclose(outptr);
    return 0;
}




