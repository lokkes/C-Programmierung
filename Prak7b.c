#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapStr(char*p1, char*p2, int len);

int main(int argc, char* argv[]){
size_t longest = 0;
int arglen = argc-1;

    for(int i = 1; i < argc; i++){
       size_t l = strlen(argv[i]);
       if (longest < l){
            longest = l;
       }
    }

    char arrayStrgs[arglen][longest+1];
  
    for(int i = 0; i < arglen; i++){
        strcpy(arrayStrgs[i],argv[i+1]);  
    }

 for (int i = 0; i < arglen - 1; i++) {          // number of passes
    for (int j = 0; j < arglen - i - 1; j++) {  // compare adjacent pairs
        if (strcmp(arrayStrgs[j], arrayStrgs[j+1]) > 0) {
            swapStr(arrayStrgs[j],arrayStrgs[j+1],longest+1);
        }
    }

}

    printf(" ++++++++++++++++++After sorting+++++++++++++++++++ \n");
     for(int i = 0; i < arglen; i++){
        printf("%s\n",arrayStrgs[i]);
    }
    printf("++++++++++++++++++ sorted +++++++++++++++++++++++++\n");
    return 0;
}


    void swapStr(char*p1, char*p2, int len){
        char tmp[len];
        strcpy(tmp,p1);
        strcpy(p1,p2);
        strcpy(p2,tmp);
    }
