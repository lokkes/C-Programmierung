#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char buf[128];



//last in first out wird implimentiert 
int main(/* int argc, char*argv[] */){
    tList* inputptr = CreateList();
   
    //Nutzer Eingabe
    do{

    printf("Enter (I)nsert / (O)ut / (Q)uit: ");
    fgets(buf,sizeof(buf),stdin);
  

    if(buf[0] == 'I' || buf[0]== 'i'){

        printf("Enter the text : ");
        fgets(buf,sizeof(buf),stdin);
        char* s= malloc(strlen(buf)+1);//s has the pointer adress 
        strcpy(s,buf);// the string from buf is actually getting copied to the s
        InsertHead(inputptr, s);
    }

    else if(buf[0]=='O' || buf[0]=='o'){

        char* outptr = GetFirst(inputptr); // the outptr is now holding the s 
        printf("%s",outptr);
        RemoveItem (inputptr);
        free(outptr); //we are now freeing the malloc pointer 
    }

    else if(buf[0]=='Q' || buf[0]=='q') {

        printf("quiting......");
        DeleteList(inputptr); 

        
    }

    else{
        printf("Invalide string : usage --> Enter (I)nsert / (O)ut / (Q)uit");
    }



    }while(buf[0]!='Q' && buf[0]!='q');
    
    return 0;
} 
