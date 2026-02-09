#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"

void swap(tArt *x, tArt *y);

int main(int argc, char *argv[]){

    char option;
    tArt* part;

    if(argc != 2){

        printf("usage : <./Programmname> <Filename>");
        return 1;

    }

    FILE* fp = fopen(argv[1],"rb");
    if(fp == NULL){
        printf("Error opening File");
        return 1;
    }

    //to do..
    //determine the length of the file the above 1 will just read the first struct which is not the plan 
    fseek(fp,0,SEEK_END);
    long filesize = ftell(fp); // ftell gives the size of the file 
    fseek(fp,0,SEEK_SET);

    //to find the size of each struct & allocate memory
    long records = filesize/sizeof(tArt);

    // allocates space for all the structs part[1]...
    part = malloc(records*sizeof(tArt));

    if(part == NULL){
        printf("malloc failure");
        return 1;
    }

    fread(part,sizeof(tArt),records,fp);

    
    printf("...........Sort according to Art-Nr or bezeichnung...........\n");
    printf("Type A(art-nt) or B(bez) ");
    scanf("%c",&option);
    printf("Sorting according to option %c\n",option);

    printf("Art.-Nr        Bezeichnung              Stueckzahl   Soll   Unterschrift\n"); 
    

    for (int i = 0; i < records-1; i++) {

        for(int j = i+1; j<records; j++){
        if(option == 'B'){

            if(strcmp(part[i].vBez,part[j].vBez) > 0){
            swap(&part[i],&part[j]);
       } 
            }
    
        else if (option == 'A')
       {
            if(strcmp(part[i].vNr,part[j].vNr) > 0){
            swap(&part[i],&part[j]);
       } 
          }
        

    }
  
        printf("%-15s", part[i].vNr);
        printf("%-25s", part[i].vBez);
        printf("%-12ld", part[i].Lbst);
        printf(" ....");
        printf("   ..........\n");

 }

    fclose(fp);
    free(part);


    return 0;
}


void swap(tArt *x, tArt *y) {
    tArt tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
