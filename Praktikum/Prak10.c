#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct waehrung
{
    char cName[31];
    char cCode[4];
    char währungskurzel[4];
    double kauf;
    double verkauf;
};

struct waehrung currencies[] = {
    {"Vereinigte Staaten von Amerika", "USA", "USD", 0.7093, 0.0},
    {"Schweiz", "CH ", "CHF", 0.6053, 0.0},
    {"Grossbritanien", "GB ", "GBP", 1.4355, 0.0},
    {"Japan", "JP ", "JPY", 0.006165, 0.0},
    {"Kanada", "CA ", "CAD", 0.7090, 0.0},
    {"Australien", "AU ", "AUD", 0.6154, 0.0},
    {"Russland", "RU ", "RUR", 0.02830, 0.0},
    {"China", "CHI", "CHY", 0.09414, 0.0},
    {"Schweden", "S  ", "SWK", 0.10858, 0.0},
    {"Indien", "IN ", "INR", 0.01787, 0.0}};

void calverkauf(struct waehrung arr[], int count);
void sortcurrencies(struct waehrung arr[], int count);
void swap(struct waehrung *a, struct waehrung *b);
void printCurrencies(struct waehrung arr[], int count);
int (*compar)(const void *, const void *);
/* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); */
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int comparbyname(const void *p1, const void *p2);
int comparbycode(const void *p1, const void *p2);
int comparbycurrency(const void *p1, const void *p2);

int main()
{

    int choice;
    printf("Sort by:\n1 = Country Name\n2 = Country Code\n3 = Currency Abbreviation\n");
    scanf("%d", &choice);

    if (choice == 1)
        compar = comparbyname;
    else if (choice == 2)
        compar = comparbycode;
    else
        compar = comparbycurrency;

    int count = sizeof(currencies) / sizeof(currencies[0]);
    calverkauf(currencies, count);
    /* sortcurrencies(currencies,count); */
    qsort(currencies, count, sizeof(currencies[0]), compar);// qsort nach Land, Landeskürzel oder Währungsbezeichnung
    mysort(currencies,count,sizeof(currencies[0]), compar);
    printCurrencies(currencies, count);

    return 0;
}

void calverkauf(struct waehrung arr[], int count)
{

    for (int i = 0; i < count; i++)
    {
        arr[i].verkauf = arr[i].kauf * 0.92;
    }
}

void sortcurrencies(struct waehrung arr[], int count)
{

    for (int i = 0; i < count - 1; i++)
    {

        for (int j = i + 1; j < count; j++)
        {

            if ((strcmp(arr[i].cName, arr[j].cName)) > 0)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(struct waehrung *a, struct waehrung *b)
{
    struct waehrung temp = *a;
    *a = *b;
    *b = temp;
}

void printCurrencies(struct waehrung arr[], int count)
{
    printf("%-30s, %-3s, %-3s, %10s, %10s\n",
           "Country", "CC", "WC", "Buy(EUR)", "Sell(EUR)");
    for (int i = 0; i < count; i++)
    {
        printf("%-30s, %-3s, %-3s, %10.5f, %10.5f\n",
               arr[i].cName, arr[i].cCode, arr[i].währungskurzel,
               arr[i].kauf, arr[i].verkauf);
    }
}

// mysort noch implementiern und funktionen untern muss auch implementiert werden
int comparbyname(const void *p1, const void *p2)
{

    const struct waehrung *a = (const struct waehrung *)p1;
    const struct waehrung *b = (const struct waehrung *)p2;
    return strcmp(a->cName,b->cName);
   
}
int comparbycode(const void *p1, const void *p2)
{

    const struct waehrung *a = (const struct waehrung *)p1;
    const struct waehrung *b = (const struct waehrung *)p2;
    return strcmp(a->cCode,b->cCode);

}
int comparbycurrency(const void *p1, const void *p2)
{

    const struct waehrung *a = (const struct waehrung *)p1;
    const struct waehrung *b = (const struct waehrung *)p2;
    return strcmp(a->währungskurzel,b->währungskurzel);

}

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)){

   
    char *arr = (char *) base;
  
    for (size_t i = 0; i<nmemb-1; i++){
          
        for(size_t j = i+1; j<nmemb; j++){
            void *p1 = arr+i*size;
            void *p2 = arr+j*size;
            if(compar(p1,p2) > 0){
                //swap the results 
                char tmp[size];
                memcpy(tmp,p1,size);//memcpy(destination,source,bytes)
                memcpy(p1,p2,size);
                memcpy(p2,tmp,size);

            }
        }
        
    }
    
}
