#include "header.h"
int login_account(Account owner)
{
    FILE *accounts_file = fopen("accounts.csv", "r");
    char line[1000];
    int i=0;
    char name[50],surname[50];
    centerText("Login to your account!\n\n");
    printf("Enter your name:");scanf("%s",name);
    printf("Enter your surname:");scanf("%s",surname);
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

        if(strcmp(fields[0],name)==0 && strcmp(fields[1],surname)==0)
            return line_count;

    }
    return 0;

    fclose(accounts_file);

}
