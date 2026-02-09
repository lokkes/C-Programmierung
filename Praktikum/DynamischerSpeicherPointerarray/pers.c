#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pers.h"


/* ---------- read one string ---------- */
char* readStr(FILE* fp)
{
    unsigned char len;

    if (fread(&len, 1, 1, fp) != 1)
        return NULL;

    char *s = malloc(len + 1);
    if (!s) return NULL;

    if (fread(s, 1, len, fp) != len) {
        free(s);
        return NULL;
    }

    s[len] = '\0';
    return s;
}


/* ---------- read one person ---------- */
tpers* readPers(FILE* fp)
{
    tpers *p = malloc(sizeof(tpers));
    if (!p) return NULL;

    p->name = readStr(fp);
    if (!p->name) { free(p); return NULL; }

    p->surname = readStr(fp);
    if (!p->surname) { free(p->name); free(p); return NULL; }

    p->phone  = readStr(fp);
    if (!p->phone) {
        free(p->name);
        free(p->surname);
        free(p);
        return NULL;
    }

    return p;
}


/* ---------- printing ---------- */
void putStr(char* s)
{
    printf("%s\n", s);
}

void putPers(tpers* p)
{
    putStr(p->name);
    putStr(p->surname);
    putStr(p->phone);
    printf("\n");
}


/* ---------- free one person ---------- */
void freePers(tpers* p)
{
    if (!p) return;

    free(p->name);
    free(p->surname);
    free(p->phone);
    free(p);
}


/* ---------- bubble sort (swap pointers only) ---------- */
void bubblesort(tpers **arr, int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {

            if (strcmp(arr[j]->name, arr[j+1]->name) > 0) {

                tpers *tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
