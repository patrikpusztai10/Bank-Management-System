#include "header.h"
double convertCurrency(double amount, char coin[5], char coin2[5])
{
    if(strcmp("RON",coin)==0)
    {
        if(strcmp("USD",coin2)==0)
        {
            amount*=0.21;
        }
        if(strcmp("EUR",coin2)==0)
        {
            amount*=0.20;
        }
    }
    else if(strcmp("EUR",coin)==0)
    {
        if(strcmp("USD",coin2)==0)
        {
            amount*=1.07;
        }
        if(strcmp("RON",coin2)==0)
        {
            amount*=4.99;
        }
    }
    else if(strcmp("USD",coin)==0)
    {
        if(strcmp("RON",coin2)==0)
        {
            amount*=4.67;
        }
        if(strcmp("EUR",coin2)==0)
        {
            amount*=0.94;
        }
    }
    return amount;
}
void transaction(int poz)
{
    system("cls");
    centerText("--------------------------------Money transfer-----------------------------------\n");
    printf("Enter the IBAN of the intended recipient for the money transfer:\n");
    char destinationiban[50];
    scanf("%s",destinationiban);
    while(validateIBAN(destinationiban)==0)
    {
        printf("Invalid IBAN!Enter a valid IBAN:");
        scanf("%s",destinationiban);
    }
    char line[1000],cointransfer[5];
    int line_count = 0,founddest=0,found = 0;
    double amountdest;
    printf("Specify the amount you wish to transfer[AMOUNT COIN]:\n");
    scanf("%lf %4s",&amountdest,cointransfer);
    FILE *accounts_file = fopen("accounts.csv", "r");
    FILE *temp_file = fopen("temp.csv", "w");
    if (accounts_file == NULL || temp_file == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }
    int total_accounts = numacc(accounts_file);

    while (fgets(line, sizeof(line), accounts_file) != NULL)
    {
        line_count++;
        char name[50], surname[50], iban[50],coin[5];
        double amount;
        if (sscanf(line, "%[^,],%[^,],%[^,],%lf,%4s", name, surname, iban, &amount, coin) == 5)
        {
            if(strcmp(destinationiban,iban)==0)
            {

                amount+=convertCurrency(amountdest,cointransfer,coin);
                printf("\n");

            }
            if(line_count==poz)
            {

               amount-=convertCurrency(amountdest,cointransfer,coin);
               found=1;
            }
          fprintf(temp_file, "%s,%s,%s,%lf,%s\n", name, surname, iban, amount, coin);
        }

    }
    fclose(accounts_file);
    fclose(temp_file);
    if (found==1)
    {

        FILE *new_accounts_file = fopen("accounts.csv", "w");
        temp_file = fopen("temp.csv", "r");

        if (new_accounts_file == NULL || temp_file == NULL)
        {
            printf("Error: Unable to open file for writing.\n");
            return;
        }


        while (fgets(line, sizeof(line), temp_file) != NULL)
        {
            fputs(line, new_accounts_file);
        }

        fclose(new_accounts_file);
        fclose(temp_file);
        printf("Transfer done successfully!\n");
        view_account(is_iban_tied_to_users_account(destinationiban));
        remove("temp.csv");
    }
    centerText("\nBack to menu?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    printf("Select option[1-2]:");
    int option_for_new_actions;scanf("%d",&option_for_new_actions);
    if(option_for_new_actions==2)
    {
        system("cls");
        menu(poz);
    }
    if(option_for_new_actions==1)
        return 0;
}
