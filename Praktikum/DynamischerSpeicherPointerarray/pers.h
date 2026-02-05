#ifndef PERS_H
#define PERS_H

#include <stdio.h>

typedef struct {
    char *name;
    char *surname;
    char *phone;
} tpers;

char*  readStr(FILE* fp);
void   putStr(char* str);

tpers* readPers(FILE* fp);
void   putPers(tpers* p);

void   freePers(tpers* p);
void   bubblesort(tpers **arr, int n);

#endif
