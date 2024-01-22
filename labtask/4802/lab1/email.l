%option noyywrap
%{
	#include<stdio.h>
	//int wc=0,nc=0,oc=0;
%}

%%


[a-z]*\.?[a-z0-9_]@[a-z0-9-]+\.[a-z]{2,}  {printf("Valid Email: %s\n",yytext);}
.+  {printf("Invalid Address");}

%%
int main()
{
	puts("Enter a string");
	yylex();
	 // printf("Word Count: %d\nNumber Count %d\nUnknown Count %d",wc,nc,oc);
	return 0;
}