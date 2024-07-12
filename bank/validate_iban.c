#include"header.h"
int validateIBAN(char iban[50])
{
    if(strlen(iban)>34&&strlen(iban)<10)
      return 0;
    char countrycode_1,countrycode_2;
    countrycode_1=iban[0];
    countrycode_2=iban[1];
    if(!(countrycode_1>='A'&&countrycode_2<='Z'))
        return 0;
    char digits_1,digits_2;
    digits_1=iban[2];
    digits_2=iban[3];
    if(!(digits_1>='0'&&digits_2<='9'))
        return 0;
    char bank_code1,bank_code2,bank_code3,bank_code4;
    bank_code1=iban[4];
    bank_code2=iban[5];
    bank_code3=iban[6];
    bank_code4=iban[7];
    if(!(bank_code1>='A'&&bank_code1<='Z'&&bank_code2>='A'&&bank_code2<='Z'&&bank_code3>='A'&&bank_code3<='Z'&&bank_code4>='A'&&bank_code4<='Z'))
    return 0;
    for(int i=7;i<strlen(iban);i++)
      if(!((iban[i]>='A'&&iban[i]<='Z')||(iban[i]>='0'&&iban[i]<='9')))
      return 0;
    return 1;


}
