#include "students.h"

// implementaion file 
void displayStudent(tStud *s){

        printf("%s\n",s->name);
        printf("%d\n",s->matrixr);
        printf("%f\n",s->noteKl);
        printf("%d\n",s->noteBel);
}

/* tStud* getStudent(){


} */

//  this function writes only one student (tStud) entry to the file per call.
// If you want to write multiple students, you need to call this function in a loop for each student,
// or modify it to take an array of tStud and a count.

int writeStud(FILE* fp, tStud* ps) {
    return fwrite(ps, sizeof(tStud), 1, fp);
}

tStud* readStud(FILE* fp){

    tStud* tmp = malloc(sizeof(tStud));

    if(tmp){
        int ret = fread(tmp,sizeof(tStud),1,fp);
        if (ret != 1){
            free(tmp);
            tmp = NULL;
        } 

        return tmp;
    }
}