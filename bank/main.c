#include "header.h"
void centerText(const char *text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    // Get the console screen buffer info to obtain the terminal width
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

    // Calculate leading spaces to center the text
    int leadingSpaces = (columns - strlen(text)) / 2;

    // Output leading spaces followed by the text
    printf("%*s%s\n", leadingSpaces, "", text);
}
int main()
{

    printf("\033[0;36m");
    printf("  _   ___     _______     \n");
    printf(" | | | \\ \\   / /_   _|    \n");
    printf(" | | | |\\ \\ / /  | |      \n");
    printf(" | |_| | \\ V /   | |      \n");
    printf("  \\___/   \\_/    |_|      \n");
    printf("\033[1;33m");
    printf("  _                 _     \n");
    printf(" | |__   __ _ _ __ | | __ \n");
    printf(" | '_ \\ / _` | '_ \\| |/ / \n");
    printf(" | |_) | (_| | | | |   <  \n");
    printf(" |_.__/ \\__,_|_| |_|_|\\_\\ \n");
    printf("                          \n");
    printf("\033[0;36m");
    centerText("--------------------Welcome to UVT BANK!-------------------------\n\n");
    int option,poz;
    Account new_user;
    printf("1.Login\n\n");
    printf("2.Register\n\n");
    printf("Select option:");
    scanf("%d",&option);
    system("cls");
    if(option==2)
    {
    int ok;
    ok=create_account(new_user);
    if(ok==0)printf("Account created succesfully");
    }
    if(option==1)
    {
        poz=login_account(new_user);
        if(poz>0)
        {system("cls");
         menu(poz);}
        else
        {
         char option[10];
         system("cls");
         printf("Account not found!\n\n");
         printf("Do you want to create an account?");
         scanf("%s",option);
         if(strcmp("yes",option)==0||strcmp("Yes",option)==0||strcmp("YES",option)==0)
         {  system("cls");
            int ok;
            ok=create_account(new_user);
            if(ok==0)printf("Account created succesfully");
         }
         else{
            return 0;
         }
    }

}}

