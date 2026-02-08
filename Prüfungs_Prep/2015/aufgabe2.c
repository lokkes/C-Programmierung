#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void  myFunc(char *dir){
	char buf[128];
	char cmd[128];
	snprintf(cmd,sizeof(cmd),"ls -l %s > /tmp/tmpls",dir);
	system(cmd);

	FILE* fp = fopen("/tmp/tmpls","r");
	if(fp == NULL){
	  
 	   fprintf(stderr,"Fehler beim datei lesen");	

	}	

	while(fgets(buf,sizeof(buf),fp)!=NULL){

		fputs(buf,stdout);

		if(buf[0]=='d'){
		char* token = strtok(buf," ");
		char* last = token;

			while(token != NULL){
				last = token;
				token = strtok(NULL," ");
			}

		 if (strcmp(last, ".") == 0 || strcmp(last, "..") == 0)
                continue;		
			
		char newpath[128];
		snprintf(newpath, sizeof(newpath), "%s/%s", dir, last);
		myfunc(newpath);
		}
		
	}
	
fclose(fp);


}
