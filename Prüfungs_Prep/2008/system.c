#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // <-- needed for strtok()

char buf[128];

int getFree(char* dir){

        char cmd[128];
        char* tokens;
        int i=0, j=0;

        sprintf(cmd,"df %s > /tmp/tmpdf",dir);
        system(cmd);

        FILE* fp = fopen("/tmp/tmpdf","r");
        if(fp == NULL) return -1;   // <-- needed (open failed)

        while(fgets(buf,sizeof(buf),fp)!=NULL){

                //as i = 0 muss der header von tabelle sein
                if(i==1){

                 j = 0;  // <-- needed (start counting tokens fresh for the data line)
                 tokens = strtok(buf, " \t\n");

                while(tokens!=NULL){

                     if(j==3){

                     fclose(fp);    // <-- needed (close before return)
                     return atoi(tokens);

                    }
           tokens =  strtok(NULL, " \t\n");
           j++;
        }


    }

        i++;

  }

        fclose(fp);     // <-- needed (close if not returned inside)
        return -1;      // <-- needed (fallback if parsing failed)

}



