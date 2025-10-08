#include <stdio.h>
#include <ctype.h>

int main() {
    int i, j;

    // Print table header
    for (i = 0; i < 4; i++){

       printf(" |dec hex Char ");

    }
  
        printf(" | \n ");


    for (i = 0; i < 32; i++) {
        printf("\n |");
 
        for (j = i; j < 128; j += 32) {
          
            printf("%3d %2X ", j, j);
            if (isgraph(j))
                printf("  %c    |", j);
            else
                printf("  .    |");
    
        }


    }


}
