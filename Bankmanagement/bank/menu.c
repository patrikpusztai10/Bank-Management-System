#include "header.h"
int menu(int poz)
{
    int i;
    char name[50],surname[50];
    FILE *accounts_file=fopen("accounts.csv", "r");
    char line[1000],iban2[500];
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
            i++;
        }
        if (poz==line_count)
        {strcpy(name,fields[0]);
         strcpy(surname,fields[1]);
         printf("                          ---------------------Welcome, %s %s------------------------            \n\n",name,surname);break;}

    }
    printf("\n");
    printf("1.Edit account\n");
    printf("2.Delete account\n");
    printf("3.View account\n");
    printf("4.Perform transactions\n\n");
    printf("Select option [1-4]:");
    int option,option2;
    scanf("%d",&option);
    if(option==1)
    {   printf("--------------------------------------------------------\n");
        printf("Do you have multiple accounts?\n");
        printf("1.No\n");
        printf("2.Yes\n");
        printf("Select option[1-2]:");scanf("%d",&option2);
        if(option2==1)edit_account(poz);
        else{
         printf("\nEnter the IBAN of the account you want to change:");
         scanf("%s",iban2);
         if(findiban(iban2)==0)
            printf("Account not found\n");
         else
         edit_account(findiban(iban2));
        }
        int option6;
         printf("--------------------------------------------------------\n");
         printf("\nDo you want to change other information regarding your account?\n");
         printf("1.No\n");
         printf("2.Yes\n");
         printf("Select option[1-2]:");scanf("%d",&option6);
         if(option6==2)
         {
             edit_account(poz);
         }
         if(option6==1)
         {
         int option7;
         printf("--------------------------------------------------------\n");
         printf("\nDo you want to perform other actions?\n");
         printf("1.No\n");
         printf("2.Yes\n");
         printf("Select option[1-2]:");scanf("%d",&option7);
         if(option7==2)
         {   system("cls");
             menu(poz);
         }
         if(option7==1)
         return 0;

         }

    }
    if(option==2)
    {
        printf("Do you have multiple accounts?\n");
        printf("1.No\n");
        printf("2.Yes\n");
        printf("Select option[1-2]:");scanf("%d",&option2);
        if(option2==1)delete_account(poz);
        else{
         printf("\nEnter the IBAN of the account you want to change:");
         scanf("%s",iban2);
         if(findiban(iban2)==0)
            printf("Account not found\n");
         else
         delete_account(findiban(iban2));}
        printf("\nDo you want to create another account?\n");
        printf("1.No\n");
        printf("2.Yes\n");
        int option5;
        printf("Select option[1-2]:");scanf("%d",&option5);
        if (option5==2){create_account();}
        if (option5==1){return 1;}

    }
    if(option==3)
    {
        printf("Your account has the following details\n");
        view_account(poz);
        int option8;
        printf("--------------------------------------------------------\n");
         centerText("\nDo you want to perform other actions?\n");
         printf("1.No\n");
         printf("2.Yes\n");
         printf("Select option[1-2]:");scanf("%d",&option8);
         if(option8==2)
         {   system("cls");
             menu(poz);
         }
         if(option8==1)
         return 0;

    }
    if(option==4)
    {
        int option9;
        printf("--------------------------------------------------------\n");
        printf("Do you have multiple accounts?\n");
        printf("1.No\n");
        printf("2.Yes\n");
        printf("Select option[1-2]:");scanf("%d",&option9);
        if(option9==1)transaction(poz);
        if(option9==2)
        {char iban3[50];
         printf("Enter the IBAN of the account you want to perform a transfer from:");
         scanf("%s",iban3);
         transaction(findiban(iban3));
        }
        int option11;
        printf("--------------------------------------------------------\n");
         centerText("\nDo you want to perform other actions?\n");
         printf("1.No\n");
         printf("2.Yes\n");
         printf("Select option[1-2]:");scanf("%d",&option11);
         if(option11==2)
         {   system("cls");
             menu(poz);
         }
         if(option11==1)
         return 0;

    }
    fclose(accounts_file);
}
