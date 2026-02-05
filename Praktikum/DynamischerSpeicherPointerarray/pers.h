typedef struct{

    char * name;
    char * surname;
    char * phone;

}tpers;


char* readStr(FILE* fp);
void  putStr(char* str);

tpers* readPers(FILE* fp);
void putPers(tpers* p);