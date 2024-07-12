#include "header.h"
double currency(double amount, char coin[5], char coin2[5])
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
int numacc(FILE *accounts)
{
    char line[1000];
    int i=0;
    FILE *accounts_file=fopen(accounts, "r");
    while (fgets(line, sizeof(line),accounts_file))
    {

        char *token,*fields[1000];
        int field_count=0;
        i++;
        token = strtok(line, ",");
        while (token != NULL && field_count<5)
        {
            fields[field_count++] = token;
            token = strtok(NULL, ",");
        }
    }
    return i;
}
void edit_account(int poz)
{
    FILE *accounts_file = fopen("accounts.csv", "r");
    FILE *temp_file = fopen("temp.csv", "w");

    if (accounts_file == NULL || temp_file == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    char line[1000];
    int line_count = 0;
    int found = 0;
    int total_accounts = numacc(accounts_file);

    while (fgets(line, sizeof(line), accounts_file) != NULL)
    {
        line_count++;

        char name[50], surname[50], iban[50],coin[5],coin2[5];
        double amount,deposit,withdraw;
        if (sscanf(line, "%[^,],%[^,],%[^,],%lf,%4s", name, surname, iban, &amount, coin) == 5)
        {
            if (line_count == poz)
            {
                system("cls");
                printf("Your account has the following details:\n");
                printf("Name: %s\n", name);
                printf("Surname: %s\n", surname);
                printf("IBAN: %s\n", iban);
                printf("Amount: %f\n", amount);
                printf("Coin: %s\n", coin);
                printf("------------------------------------\n");
                int option;
                printf("Change the:\n");
                printf("1. IBAN\n");
                printf("2. Amount\n");
                printf("3. Coin\n");
                printf("Select option [1-3]: ");
                scanf("%d", &option);

                if (option == 1)
                {
                    system("cls");
                    centerText("--------------------------------Change IBAN------------------------------------\n");
                    printf("Enter new IBAN: ");
                    scanf("%s", iban);
                while(is_iban_in_csv(iban)!=0)
                {
                    printf("Forbidden action,IBAN is already tied to a different account! Enter a valid IBAN:");
                    scanf("%s",iban);
                }

                    while(validateIBAN(iban)==0)
                    {printf("Invalid IBAN!Enter a valid IBAN:");scanf("%s", iban);}
                }
                else if (option == 2)
                {
                    system("cls");
                    centerText("--------------------------------Deposit or withdraw-----------------------------------\n");
                    printf("Your current balance is: %.2f %s \n\n",amount,coin);
                    printf("1.Deposit\n");
                    printf("2.Withdrawal\n");
                    printf("Select option[1-2]:");
                    int option_for_dep_or_with;
                    scanf("%d",&option_for_dep_or_with);
                    if(option_for_dep_or_with==1)
                    {
                        printf("Enter amount of money you want to deposit[AMOUNT]:");
                        scanf("%lf",&deposit);
                        amount+=deposit;
                    }
                    if(option_for_dep_or_with==2)
                    {
                        printf("Enter amount of money you want to withdraw[AMOUNT]:");
                        scanf("%lf",&withdraw);
                        amount-=withdraw;
                    }
                }
                else if (option == 3)
                {
                    system("cls");
                    centerText("--------------------------------Currency-----------------------------------\n");
                    printf("\nEnter new coin: ");
                    scanf("%s",coin2);
                    printf("\nThe currency is changed automatically!\n");
                    amount=currency(amount,coin,coin2);
                    strcpy(coin,coin2);
                    printf("Account balance:%.2f %s\n\n",amount,coin);
                }

                found = 1;
            }

            // Write account details to temp file
            fprintf(temp_file, "%s,%s,%s,%f,%s\n", name, surname, iban, amount, coin);
        }
    }

    fclose(accounts_file);
    fclose(temp_file);
    if (found)
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

        remove("temp.csv");

        printf("Account updated successfully!\n");
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
