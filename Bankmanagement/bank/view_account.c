#include "header.h"

int view_account(int poz)
{
    FILE *accounts_file=fopen("accounts.csv", "r");
    char line[1000];int i=0;
    char name[50],surname[50];
    int line_count=0;
    while (fgets(line, sizeof(line),accounts_file))
    {

        char *token,*fields[1000];
        line_count++;
        int field_count=0;
        token = strtok(line, ",");
        while (token != NULL && field_count<5) {
            fields[field_count++] = token;
            token = strtok(NULL, ",");
        }
        if(poz==line_count)
        {

            strcpy(name,fields[0]);
            strcpy(surname,fields[1]);

        }
        if(strcmp(fields[0],name)==0&&strcmp(fields[1],surname)==0)
        {  printf("Name:%s\n",fields[0]);
           printf("Surname:%s\n",fields[1]);
           printf("IBAN:%s\n",fields[2]);
           printf("Amount:%s\n",fields[3]);
           printf("Coin:%s\n",fields[4]);
        }
    }
    fclose(accounts_file);

}

