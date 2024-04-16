#include "header.h"
void delete_account(int poz)
{
    system("cls");
    centerText("--------------------------------Delete account-----------------------------------\n");
    FILE *accounts_file = fopen("accounts.csv", "r");
    FILE *temp_file = fopen("temp.csv", "w");

    char line[1000];
    int line_count = 0;
    int found = 0;

    int total_accounts = numacc(accounts_file);

    while (fgets(line, sizeof(line), accounts_file) != NULL) {
        line_count++;

        if (line_count == poz) {
            found = 1;
        } else {

            fputs(line, temp_file);
        }
    }

    fclose(accounts_file);
    fclose(temp_file);

    if (found) {

        FILE *new_accounts_file = fopen("accounts.csv", "w");
        temp_file = fopen("temp.csv", "r");

        if (new_accounts_file == NULL || temp_file == NULL) {
            printf("Error: Unable to open file for writing.\n");
            return;
        }
        while (fgets(line, sizeof(line), temp_file) != NULL) {
            fputs(line, new_accounts_file);
        }

        fclose(new_accounts_file);
        fclose(temp_file);
        remove("temp.csv");

        printf("Account deleted successfully!\n");
    } else {
        remove("temp.csv");
    }
}

