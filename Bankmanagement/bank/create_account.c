#include "header.h"
int valid(char s[50])
{
    for(int i=0; i<strlen(s); i++)
        if(isalpha(s[i])==0&&s[i]!='-')
            return s[i];
    return 1;
}
void create_account()
{
    FILE *account_file;
    Account owner1;
    account_file=fopen("accounts.csv","a");
    char name[50],surname[50],iban[50],coin[4];
    double amount;
    centerText("Create account!\n");
    printf("\n");
    printf("1.Enter your name:");
    scanf("%50s",&name);
    while(valid(name)!=1)
    {
        printf("INVALID USERNAME {%c} IS NOT A LETTER.\nEnter your name:",valid(name));
        scanf("%49s",&name);
    }
    printf("2.Enter your surname:");
    scanf("%49s",&surname);
    while(valid(surname)!=1)
    {
        printf("INVALID USERNAME {%c} IS NOT A LETTER.\nEnter your name:",valid(surname));
        scanf("%s",&surname);
    }
    printf("3.Enter your IBAN:");
    scanf("%49s",&iban);
    if(validateIBAN(iban)==0)
    {printf("Invalid IBAN.Please enter a valid IBAN:");
     scanf("%49s",&iban);
     while(validateIBAN(iban)==0)
     {printf("Invalid IBAN.Please enter a valid IBAN:");
     scanf("%49s",&iban);}
     }
    printf("4.Enter the amount of money to deposit:");
    scanf("%lf",&amount);
    printf("5.Enter the currency(RON/EUR/USD):");
    scanf("%4s",&coin);
    strcpy(owner1.owner.name,name);
    strcpy(owner1.owner.surname,surname);
    strcpy(owner1.iban,iban);
    owner1.amount=amount;
    strcpy(owner1.coin,coin);
    fprintf(account_file,"%s,%s,%s,%lf,%s\n ",owner1.owner.name,owner1.owner.surname,owner1.iban,owner1.amount,owner1.coin);
    fclose(account_file);
}
