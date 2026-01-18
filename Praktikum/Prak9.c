#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[128];
typedef struct {

    char* Name; // this will store only adress not the string 
    short Tag;
    short Monat;
    short Jahr;
    char* Notiz; // this will store only adress not the string 

}tPers;

int main(){

    tPers* persons = NULL; // persons is a pointer variable poting to nothing 
    int count = 0;
    char buf[128];
    char status = 'Y';
    int i; 

    do{
    count++;
    i = count - 1; 
    printf("Name : ");
    fgets(buf,128,stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if(count == 1){
        persons = malloc(count*sizeof(tPers));
    }

    else{

    if(persons == NULL){
    printf("Memory allocation failed!\n");
    return 1;

    }
        tPers* tmp = realloc(persons,sizeof(tPers)*count);
        persons = tmp;
    }

    persons[i].Name = malloc(strlen(buf)+1);
    strcpy(persons[i].Name,buf);

    printf("Tage : ");
    fgets(buf,128,stdin);
    persons[i].Tag = atoi(buf);

    printf("Monat : ");
    fgets(buf,128,stdin);
    persons[i].Monat = atoi(buf);

    printf("jahr : ");
    fgets(buf,128,stdin);
    persons[i].Jahr = atoi(buf);

    printf("Notiz : ");
    fgets(buf,128,stdin);
    persons[i].Notiz = malloc(strlen(buf)+1);
    strcpy(persons[i].Notiz,buf);


    printf("continue(y/n) : ");
    fgets(buf,sizeof(buf),stdin);
    status = buf[0];
   
    }while(status == 'y' || status == 'Y');

    for(int k = 0; k<count; k++){
        printf("Name : %s\n",persons[k].Name);
        printf("Day : %d\n",persons[k].Tag);
        printf("Month : %d\n",persons[k].Monat);
        printf("Year : %d\n",persons[k].Jahr);
        printf("Note : %s\n",persons[k].Notiz);
        free(persons[k].Name);
        free(persons[k].Notiz);
    }

        free(persons);

    return 0;
}