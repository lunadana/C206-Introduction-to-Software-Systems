//Luna Dana 260857641

#include<stdio.h>
#include<stdlib.h>
#include"ssv.h"
#include"linked.h"
#include <string.h>

void main(){
FILE *p = fopen("students.ssv", "r");


if(p == NULL){
exit(EXIT_FAILURE);
}

char line[30];
        int *acct = malloc(sizeof(int));
        float *amnt = malloc(sizeof(float));
        int account;
        float amount;

        fgets(line, 29, p);

        //While it is not the end of the file
        while (!feof(p)){

          parse(line, acct, amnt);

          //Either add the node or update existing node. 
          account = *acct;
          amount = *amnt;
          findUpdate(account, amount);

          //get next line.
          memset(line, 0, sizeof(line));
          fgets(line, 29,p);
        }
        free(acct);
        free(amnt);

        prettyPrint();

        fclose(p);
        exit(EXIT_SUCCESS);

}