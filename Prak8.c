#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct waehrung 
{
    char cName[31];
    char cCode [4];
    char währungskurzel[4];
    double kauf;
    double verkauf;   
};

struct waehrung currencies[] = {
    #include "Prak8.dat"
};

void calverkauf(struct waehrung arr[], int count); 
void sortcurrencies(struct waehrung arr[], int count);
void swap(struct waehrung *a, struct waehrung *b);
void printCurrencies(struct waehrung arr[], int count);

int main(){

int count = sizeof(currencies)/sizeof(currencies[0]);
calverkauf(currencies,count);
sortcurrencies(currencies,count);
printCurrencies(currencies, count);

return 0;

}

void calverkauf(struct waehrung arr[], int count){

    for(int i = 0; i < count; i++){
        arr[i].verkauf = arr[i].kauf * 0.92;
    }
    
}

void sortcurrencies(struct waehrung arr[], int count){

    for(int i = 0; i < count-1; i++){

    for(int j =i+1; j<count; j++){

        if((strcmp(arr[i].cName,arr[j].cName))  > 0 ){
            swap(&arr[i],&arr[j]);
     }

       } 
    }

}

void swap(struct waehrung *a, struct waehrung *b){
    struct waehrung temp = *a;
    *a = *b;
    *b = temp;
}

void printCurrencies(struct waehrung arr[], int count) {
    printf("%-30s, %-3s, %-3s, %10s, %10s\n", 
           "Country", "CC", "WC", "Buy(EUR)", "Sell(EUR)");
    for(int i = 0; i < count; i++) {
        printf("%-30s, %-3s, %-3s, %10.5f, %10.5f\n",
               arr[i].cName, arr[i].cCode, arr[i].währungskurzel,
               arr[i].kauf, arr[i].verkauf);
    }
}





