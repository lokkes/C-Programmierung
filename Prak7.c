#include <stdio.h>
#include <stdlib.h>


char vBuf[128];
// use bitmask 
char *crtBitStr(unsigned int x);  

int main(){

    printf("Eingabe einer Int-Zahl : ");
    fgets(vBuf,128,stdin);
    int x = atoi(vBuf);

    printf("***\n");
    printf("dez : %d\n",x);
    printf("hex : %08X\n",x);
    printf("bin : %s\n",crtBitStr(x));
    printf("+++");
    return 0;
}

char *crtBitStr(unsigned int x){
size_t nBits = sizeof(x) * 8;
static char buffer[sizeof(x) * 8 +1];
int pos = 0;

    for(int i = nBits-1;i>=0;i--){

        if ((x >> i) & 1){
            buffer[pos] = '1';
            pos++;
        }

        else{
            buffer[pos] = '0';
            pos ++;
        } 

        if (i % 8 == 0 && i != 0) {
        buffer[pos++] = '|';
        
        }
}  

return buffer;

}