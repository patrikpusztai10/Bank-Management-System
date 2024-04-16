#include "header.h"
int findiban(char iban[50])
{
    char line[1000];
    int line_count = 0;
    int found = 0;
    FILE *accounts_file = fopen("accounts.csv", "r");
    while (fgets(line, sizeof(line),accounts_file))
    {

        char *token,*fields[1000];
        line_count++;
        int field_count=0;
        token = strtok(line, ",");
        while (token != NULL && field_count<5)
        {
            fields[field_count++] = token;
            token = strtok(NULL, ",");
        }
        if(strcmp(iban,fields[2])==0)
            return line_count;

    }
    return 0;
}
