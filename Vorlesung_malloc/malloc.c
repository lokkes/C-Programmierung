#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[128];

typedef struct {
    char name[31];
    int matrNr;
    float noteKl;
    int noteBel;
} tstud;

void displaystudent(tstud* s) {
    printf("%30s , %6d , %3.1f , %d\n",
           s->name,
           s->matrNr,
           s->noteKl,
           s->noteBel);
}

tstud getStudent() {
    tstud st;

    printf("%10s: ", "Name");
    fgets(buf, 128, stdin);
    buf[strcspn(buf, "\n")] = 0;
    strcpy(st.name, buf);

    printf("%10s: ", "MatrNr");
    fgets(buf, 128, stdin);
    st.matrNr = atoi(buf);

    st.noteKl = 0.0f;
    st.noteBel = 0;

    return st;
}

int main(void) {
    char proceed = 'j';
    tstud *pdata = NULL;
    tstud *ptmp;
    int count = 0;
    int i;

    do {
        ptmp = realloc(pdata, sizeof(tstud) * (count + 1));
        if (ptmp) {
            pdata = ptmp;
            pdata[count] = getStudent();
            count++;
        }

        printf("You want to add more students? (j/n): ");
        fgets(buf, 128, stdin);
        proceed = buf[0];

    } while (proceed == 'j');

    for (i = 0; i < count; i++) {
        displaystudent(&pdata[i]);
    }

    free(pdata);
    return 0;
}
