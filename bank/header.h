#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
typedef struct{
 char name[50];
 char surname[50];}User;
typedef struct{
 char iban[50];
 User owner;
 double amount;
 char coin[4];
 }Account;


