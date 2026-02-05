#include <stdio.h>
#include <stdlib.h>
#include "pers.h"

int main(void)
{
    FILE *fp = fopen("phone.dat", "rb");
    if (!fp) {
        perror("phone.dat");
        return 1;
    }

    tpers **pAll = NULL;
    int n = 0;

    tpers *p;

    /* -------- read all persons -------- */
    while ((p = readPers(fp)) != NULL) {

        tpers **tmp = realloc(pAll, (n+1) * sizeof(tpers*));
        if (!tmp) {
            freePers(p);
            break;
        }

        pAll = tmp;
        pAll[n++] = p;
    }

    fclose(fp);


    /* -------- sort (Aufgabe 3) -------- */
    bubblesort(pAll, n);


    /* -------- print all -------- */
    for (int i = 0; i < n; i++)
        putPers(pAll[i]);


    /* -------- free memory -------- */
    for (int i = 0; i < n; i++)
        freePers(pAll[i]);

    free(pAll);

    return 0;
}
