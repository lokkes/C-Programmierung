#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char vBuf[128];

int main(){

    printf("Eingabe : "); 

    while(1){

    fgets(vBuf,128, stdin);
    if(vBuf[0] == 'q' && vBuf[1] == 'q'){
        printf("Programm exited sucessfully");
        break;
    }

    switch (vBuf[0])

    {
       
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    printf("Nummer\n");
    break;

    
            // Uppercase letters
            case 'A': case 'B': case 'C': case 'D': case 'E':
            case 'F': case 'G': case 'H': case 'I': case 'J':
            case 'K': case 'L': case 'M': case 'N': case 'O':
            case 'P': case 'Q': case 'R': case 'S': case 'T':
            case 'U': case 'V': case 'W': case 'X': case 'Y':
            case 'Z':
            printf("Großbuchstaben\n");
            break;

            // Lowercase letters
            case 'a': case 'b': case 'c': case 'd': case 'e':
            case 'f': case 'g': case 'h': case 'i': case 'j':
            case 'k': case 'l': case 'm': case 'n': case 'o':
            case 'p': case 'q': case 'r': case 's': case 't':
            case 'u': case 'v': case 'w': case 'x': case 'y':
            case 'z':
            printf("Kleinbuchstaben\n");
            break;
    
    default:
        printf("Sonderzeichen");
        break;
    }

    return 0;
}

}

