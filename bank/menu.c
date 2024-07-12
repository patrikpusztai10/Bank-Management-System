#include "header.h"
char* multiple_accounts_verif(int poz, char *name) {
    static char iban_return[50];
    FILE *accounts_file = fopen("accounts.csv", "r");
    char line[1000];
    int line_count = 0;
    int account_count = 0;

    if (accounts_file == NULL) {
        perror("Error opening file");
        return NULL;
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
            continue;
        }
        if (strcmp(fields[0],name) == 0) {
            account_count++;
            if (account_count == 1) {
                strcpy(iban_return, fields[2]);
                return iban_return;
            }
        }
    }

    fclose(accounts_file);
    return iban_return;

}
int menu(int poz)
{
    int i;
    char name[50],surname[50];
    FILE *accounts_file=fopen("accounts.csv", "r");
    char line[1000],iban_for_editing_accounts[500];
    int line_count=0;
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
            i++;
        }
        if (poz==line_count)
        {
            strcpy(name,fields[0]);
            strcpy(surname,fields[1]);
            printf("                          ---------------------Welcome, %s %s------------------------            \n\n",name,surname);
            break;
        }

    }
    printf("\n");
    printf("1.Edit account\n");
    printf("2.Delete account\n");
    printf("3.View account\n");
    printf("4.Transactions\n");
    printf("5.Help\n");
    printf("6.Exit\n");
    printf("Select option [1-4]:");
    int option,option_for_multiple_accounts;
    scanf("%d",&option);
    if(option==1)
    {
        printf("--------------------------------------------------------\n");
        printf("Do you have multiple accounts?\n");
        printf("1.No\n");
        printf("2.Yes\n");
        printf("Select option[1-2]:");
        scanf("%d",&option_for_multiple_accounts);
        if(option_for_multiple_accounts==1)edit_account(poz);
        else
        {   char* current_iban = multiple_accounts_verif(poz,name);
            if (current_iban) {
                printf("\nThis is the IBAN of you're currently using: %s", current_iban);
            }
            printf("\nEnter the IBAN of the account you want to change(input '!' if you want to use this IBAN):");
            scanf("%s",iban_for_editing_accounts);
            if(strcmp(iban_for_editing_accounts,"!")==0)strcpy(iban_for_editing_accounts,current_iban);
            if(is_iban_tied_to_users_account(iban_for_editing_accounts,poz)==0)
            {
                printf("Forbidden action,IBAN not tied to any of your accounts! Enter a valid IBAN:");
                scanf("%s",iban_for_editing_accounts);
                while(is_iban_tied_to_users_account(iban_for_editing_accounts,poz)==0)
                {
                    printf("Forbidden action,IBAN not tied to any of your accounts! Enter a valid IBAN:");
                    scanf("%s",iban_for_editing_accounts);
                }
            }
            edit_account(is_iban_tied_to_users_account(iban_for_editing_accounts,poz));
        }


    }
if(option==2)
{
    printf("Do you have multiple accounts?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    printf("Select option[1-2]:");
    scanf("%d",&option_for_multiple_accounts);
    char iban_for_deleting_accounts[50];
    if(option_for_multiple_accounts==1)delete_account(poz);
    else
    {   char* current_iban = multiple_accounts_verif(poz, name);
            if (current_iban) {
                printf("\nThis is the IBAN of your current account: %s", current_iban);
            }
            printf("\nEnter the IBAN of the account you want to change(input '!' if you want to use this IBAN):");
            scanf("%s",iban_for_deleting_accounts);
            if(strcmp(iban_for_deleting_accounts,"!")==0)strcpy(iban_for_deleting_accounts,current_iban);
            while(is_iban_tied_to_users_account(iban_for_deleting_accounts,poz)==0)
            {
                printf("Forbidden action,IBAN not tied to any of your accounts! Enter a valid IBAN:");
                scanf("%s",iban_for_deleting_accounts);
            }

            delete_account(is_iban_tied_to_users_account(iban_for_deleting_accounts,poz));
    }
    printf("\nDo you want to create another account?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    int option5;
    printf("Select option[1-2]:");
    scanf("%d",&option5);
    if (option5==2)
    {
        create_account();
    }
    if (option5==1)
    {
        return 1;
    }

}
if(option==3)
{
    printf("Your account has the following details\n");
    view_account(poz);
    int option_for_viewing_account;
    printf("--------------------------------------------------------\n");
    centerText("\nBack to menu?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    printf("Select option[1-2]:");
    scanf("%d",&option_for_viewing_account);
    if(option_for_viewing_account==2)
    {
        system("cls");
        menu(poz);
    }
    if(option_for_viewing_account==1)
        return 0;

}
if(option==4)
{
    int option_for_transfers;
    printf("--------------------------------------------------------\n");
    printf("Do you have multiple accounts?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    printf("Select option[1-2]:");
    scanf("%d",&option_for_transfers);
    if(option_for_transfers==1)transaction(poz);
    if(option_for_transfers==2)
    {   char* current_iban = multiple_accounts_verif(poz, name);
            if (current_iban) {
                printf("\nThis is the IBAN you're currently using: %s", current_iban);
            }
        char iban_for_transfers[50];
        printf("\nEnter the IBAN of the account you want to perform a transfer from(input '!' if you want to use this IBAN):");
            scanf("%s",iban_for_transfers);
            if(strcmp(iban_for_transfers,"!")==0)strcpy(iban_for_transfers,current_iban);
        if(is_iban_tied_to_users_account(iban_for_transfers,poz)==0)
            {
                printf("Forbidden action,IBAN not tied to any of your accounts! Enter a valid IBAN:");
                scanf("%s",iban_for_transfers);
                while(is_iban_tied_to_users_account(iban_for_transfers,poz)==0)
                {
                    printf("Forbidden action,IBAN not tied to any of your accounts! Enter a valid IBAN:");
                    scanf("%s",iban_for_transfers);
                }
            }
        transaction(is_iban_tied_to_users_account(iban_for_transfers));
    }

}
if(option==5)
{
    system("cls");
    centerText("--------------------------------Support center-----------------------------------\n");
    printf("1.Edit account \n");
    printf("\033[1m");
    printf("This functionality allows you to change the details regarding your IBAN, deposit or withdraw money from your account and change the currency of the money that was deposited.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("2.Delete account \n");
    printf("\033[1m");
    printf("By choosing this option your account will be deleted.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("3.View account \n");
    printf("\033[1m");
    printf("By choosing this option you will be able to view the personal details of all of your registered accounts. \n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("4.Transactions\n");
    printf("\033[1m");
    printf("Transactions allows you to transfer money to other accounts.You will be asked to input the IBAN of the account you intend to sent money to, and then you need to specify the amount of money to be sent and the coin.The currency will be matched automatically.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("5.Exit\n");
    printf("\033[1m");
    printf("By choosing this option you will exit the application.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("\n");
    printf("FAQ\n");
    printf("\n");
    printf("\033[0;36m");
    printf("What happens if I have multiple accounts registered on my name?\n");
    printf("\033[1m");
    printf("If you have multiple accounts and you want to perform the actions mentioned , you will be asked to input the IBAN of the account you want to use. We inform you about the default IBAN that you are using , and if it differs from the one you want to use you can change it.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("Can other users use my IBAN to modify my account?\n");
    printf("\033[1m");
    printf("Users are unable to use IBANs that aren't linked to their own accounts.If they try an error will be raised to protect the security and privacy of the users.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("Are there any fees involved in performing transactions?\n");
    printf("\033[1m");
    printf("No, we don't tax performing transactions.\n");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("--------------------------------------------------------\n");
    printf("\nBack to menu?\n");
    printf("1.No\n");
    printf("2.Yes\n");
    printf("Select option[1-2]:");
    int back_to_menu;
    scanf("%d",&back_to_menu);
    if(back_to_menu==2)
    {
        system("cls");
        menu(poz);
    }
    if(back_to_menu==1)
        return 0;

}
if(option==6)
{
    return 0;
}
fclose(accounts_file);
}

