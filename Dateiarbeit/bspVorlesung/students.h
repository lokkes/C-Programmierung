#include <stdio.h>
#include <stdlib.h>

extern char buf[];

typedef struct tStudent
{
    char name[30+1];
    int matrixr;
    float noteKl;
    int noteBel;
}tStud;

// displays the one Student
void displayStudent(tStud *s);

// gets on Student vom stdin vial Textdialog
tStud* getStudent();

// writes one student pointed to by ps into the open file pf
int writeStud(FILE* fp, tStud* ps);


// reads one student out of the open File pf
// the returned buffer has to free by the caller
tStud* readStud(FILE* fp);