//things to do 
//work on malloc 
//now it can only store first struct but create an array of struct where you can store more std 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[128];


typedef struct tStudent
{
  char *name;
  int   matrNr;
  int   noteBel;
  float noteKl;

}tStud;

int main(){

    
    FILE* fp;
    tStud std;
    char* ptr;
    unsigned char len;

    fp = fopen("stud.ser","rb");


    while(fread(&len,sizeof(len),1,fp)==1){

            for (int i = 1;i<=4; i++){

                                     /// reading only one bite or only the first bite
            ptr = malloc(len+1); // it allocats memory of the actual length (first bite) of the complete string dynamically
            ptr[len] = '\0'; 
            fread(ptr,len,1,fp);

            if(i==1){
                std.name=ptr;
                printf("%s",std.name);
                free(std.name);
                
            }
            else if(i==2){
                std.matrNr=atoi(ptr);
                printf("%d",std.matrNr);
                free(ptr);
            }
            else if(i==3){
                std.noteBel=atoi(ptr);
                printf("%d",std.noteBel);
                free(ptr);
            }
            else {
                std.noteKl=atof(ptr);
                printf("%f\n",std.noteKl);
                free(ptr);
            } 

            if (i < 4) {
            if (fread(&len, 1, 1, fp) != 1) return 0; // EOF mid-record -> stop
        }
        }
    }

    fclose(fp);
    return 0;
}