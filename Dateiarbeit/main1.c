#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "students.h"

char buf[128];
int main(int argc, char**argv){

  FILE* fp = NULL;
  tStud stud;
  tStud* pstud;// this is just a pointer to the stud type struct it didnt have an adress of tstud yet 

  if(argc != 4){ // argc counts program name as argument 1 
    printf("usage : %s <File> <Name> <MatrNr> ", argv[0]);
    exit(-1);
  }

  fp = fopen(argv[1],"ab");
  if (fp == NULL){

    printf("File failed to open");
    exit (-1);

  }

  strcpy(stud.name,argv[2]);
  stud.matrixr=atoi(argv[3]);
  stud.noteBel=0;
  stud.noteKl=0;

  // store the above object in a file 
  writeStud(fp,&stud);// small doubt here why does the second argument needs to be a adress 
  fclose(fp);

  // read data from file and show it 
  fp = fopen(argv[1],"rb");

  while((pstud=readStud(fp)) != NULL){
    displayStudent(pstud);
    free(pstud);
  }

  return 0; 
}
