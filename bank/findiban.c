#include "header.h"

int is_iban_tied_to_users_account(char iban[50], int poz) {
    char line[1000];
    int line_count = 0;
    int found = 0;
    char name[50], surname[50];
    FILE *accounts_file = fopen("accounts.csv", "r");

    if (accounts_file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(line, sizeof(line), accounts_file)) {
        char *token, *fields[1000];
        line_count++;
        int field_count = 0;
        token = strtok(line, ",");
        while (token != NULL && field_count < 5) {
            fields[field_count++] = token;
            token = strtok(NULL, ",");
        }
        if (line_count == poz) {
            strcpy(name, fields[0]);
            strcpy(surname, fields[1]);
        }
        if (strcmp(iban, fields[2]) == 0) {
            if (strcmp(name, fields[0]) == 0 && strcmp(surname, fields[1]) == 0) {
                fclose(accounts_file);
                return line_count;
            }
        }
    }

    fclose(accounts_file);
    return 0;
}
int is_iban_in_csv(char iban[50])
{
    char line[1000];
    int line_count = 0;
    int found = 0;
    char name[50], surname[50];
    FILE *accounts_file = fopen("accounts.csv", "r");

    if (accounts_file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(line, sizeof(line), accounts_file)) {
        char *token, *fields[1000];
        line_count++;
        int field_count = 0;
        token = strtok(line, ",");
        while (token != NULL && field_count < 5) {
            fields[field_count++] = token;
            token = strtok(NULL, ",");
        }
        if (strcmp(iban, fields[2]) == 0) {
                return line_count;
            }
        }


    fclose(accounts_file);
    return 0;
}
