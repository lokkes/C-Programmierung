#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char vBuf[128];

int main(){

    printf("Eingabe : "); 

    while(1){

        fgets(vBuf,128, stdin);

        if(vBuf[0] == 'q' && vBuf[1] == 'q'){
           printf("programm exited sucesfully \n");
           break;
        } 
        if(vBuf[0] != 'q' && vBuf[1] != 'q'){
                if(islower(vBuf[0])) printf("kleinbuchstaben \n");
                else if(isupper(vBuf[0])) printf("Großbuchstaben \n");
                else if(isdigit(vBuf[0])) printf("Nummer \n");
                else printf("sonderzeichen");       
    }

}
    return 0;
}