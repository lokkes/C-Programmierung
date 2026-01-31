#include "debug.h"

FILE *ProtFile = NULL;   // IMPORTANT: define it once in exactly one .c file

int main(void) {

 

    DEBUG_STR("Program start\n");
    DEBUG_STR("Hello from debug macro!\n");

    int a = 10;
    DEBUG_INT(a);

    long l = 10.00000;
    DEBUG_LONG(l);

    char c = 'Y';
    DEBUG_CHR(c);
    


    return 0;
}