#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char buf[128];
int arr[11]={0};

int main(int argc, char*argv[]){

    if(argc != 2){

        printf("usage : <program name> <File name>");
        return 1;

    }

    FILE* fp = fopen(argv[1],"r");
    if(fp == NULL){

        printf("File failed to open");
        return 1;

    }

    //fgets returns the buffer pointer on success
    //It returns NULL on end-of-file or error

    while(fgets(buf,sizeof(buf),fp) != NULL){

        char* token = strtok(buf," \t\r\n");  
      
        while (token != NULL) {
            
            int len = strlen(token);

            if (len >= 1 && len <= 10) {
                arr[len]++;
            } else {
                arr[0]++;   // sonstige Wörter (>10)
            }
             token = strtok(NULL, " \t\r\n");
        }   

    }

    for(int i = 1; i<=10; i++){

        printf(" %d : %d\n", i, arr[i]);  
        
    }
    printf(" 11 : %d sonstiges",arr[0]);

   fclose(fp);
    return 0;
}

