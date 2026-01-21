#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char buf[128];
int arr[10]={0};
void increment(int x);

int main(int argc, char*argv[]){

    if(argc != 2){

        printf("usage : <program name> <File name>");
        return 1;

    }

    FILE* fp = fopen(argv[1],"r");

    //fgets returns the buffer pointer on success
    //It returns NULL on end-of-file or error

    while(fgets(buf,sizeof(buf),fp) != NULL){

        char* token = strtok(buf, " ");  
      
        while (token != NULL) {
            
            int len = strlen(token);

            if((len > 0) && (len <= 10)){
                increment(len);
            }

            else{
               /*  printf("11 : sonstiger wörter"); */
            }
             token = strtok(NULL, " ");
        }   

    }

    for(int i = 1; i<=10; i++){
        printf(" %d : %d\n", i, arr[i]);
    }
    
    return 0;
}

void increment(int x){
    arr[x]++;
    
}
