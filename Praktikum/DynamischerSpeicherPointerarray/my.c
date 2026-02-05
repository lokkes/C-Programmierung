// reading the file manually to understand how reaing works 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pers.h"

char buf[128];

int main(){

    tpers* ptr;
    unsigned char len; 
      
    FILE* fp = fopen("phone.dat","rb");
    
    ptr= malloc(sizeof(tpers)); 

    int i=0,j=1;
    while(fread(&len,sizeof(len),1,fp)==1){
   
    j++;

    ptr[i].name=malloc(len+1);
    fread(ptr[i].name,len,1,fp);
    ptr[i].name[len] = '\0';
    printf("%s",ptr[i].name);
    


    fread(&len,sizeof(len),1,fp);

    ptr[i].surname=malloc(len+1);
    fread(ptr[i].surname,len,1,fp);
    ptr[i].surname[len] = '\0';
    printf("%s\t",ptr[i].surname);
    


    fread(&len,sizeof(len),1,fp);

    ptr[i].phone=malloc(len+1);
    fread(ptr[i].phone,len,1,fp);
    ptr[i].phone[len] = '\0';
    printf("%s\n",ptr[i].phone);
   


    i++;
    

    ptr= realloc(ptr,sizeof(tpers)*j);

    }

    free(ptr);


    return 0;


}



