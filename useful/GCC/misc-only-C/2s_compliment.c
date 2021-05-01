#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <string.h>
#include<ctype.h>
#include <time.h>

int main()
{
  char bin[100];
  int i,len;
  gets(bin);
  //len=strlen(bin);
  for (i=0;i<strlen(bin);i++)
  {
    if (bin[i]=='0') bin[i]='1';
    else if (bin[i]=='1') bin[i]='0';
  }
  len=strlen(bin)-1 ;
  for ( i = len; i>=0; i--)
  {
    if(bin[i]=='0') {bin[i]='1'; break;}
    else if (bin[i]=='1') {
              bin[i]='0';
              bin[i-1]='1';
    }
  }
  puts(bin);
  return 0;
}
