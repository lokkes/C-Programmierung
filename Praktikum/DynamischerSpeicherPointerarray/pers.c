#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pers.h"



int main(){

    FILE* fp= fopen("phone.dat","rb");
    tpers* ptr;
    tpers ** pAll=NULL;
    pAll = malloc(sizeof(tpers*));
    int n = 0;

        while((ptr = readPers(fp)) != NULL){

            pAll=realloc(pAll,sizeof(tpers*)*(n+1));
            pAll[n]=ptr;
            n++;    
            
            putPers(ptr);

            //free all the pointers 
            free(ptr->name);
            free(ptr->surname);
            free(ptr->phone);
            free(ptr);
        }

    fclose(fp);  
    free(pAll); 
    return 0;
}

tpers* readPers(FILE* fp){

    tpers* ptr;

   ptr = malloc(sizeof(tpers));
   if(ptr == NULL){
    free(ptr);
    return NULL;
   } 

   ptr->name=readStr(fp);
   if(ptr->name == NULL){

        free(ptr);
        return NULL;
   } 

   ptr->surname=readStr(fp);
   if(ptr->surname == NULL){
        free(ptr->name);
        free(ptr);
        return NULL;
   } 

   ptr->phone=readStr(fp);

   if(ptr->phone == NULL){
        free(ptr->name);
        free(ptr->surname);
        free(ptr);
        return NULL;

   } 

   
   return ptr; 
   
}

char* readStr(FILE* fp){

    unsigned char len;
    char *ptr;

    if(fread(&len,1,sizeof(len),fp)==1){
        ptr = malloc(len+1);
        if(ptr == NULL) return NULL;
    }

    else{

        return NULL;
    }
   
   if(fread(ptr,len,1,fp)== 1){

           ptr[len] = '\0';
           return ptr;
    }

    else{

        free(ptr);
        return NULL;
    }
 

}

void putStr(char* str){
    printf("%s\n",str);
}

void putPers(tpers* p){

        putStr(p->name);
        putStr(p->surname);
        putStr(p->phone);

}