%option noyywrap
%{
	#include<stdio.h>
	int wc=0,nc=0,oc=0;
%}

%%

[\t ] ;
[a-zA-Z]+ {printf("%s : word\n",yytext);wc ++;}
[+-]?([0-9]*\.)?[0-9]+  {printf("%s : num\n",yytext);nc ++;}
. {printf("%s : unknown\n",yytext);oc ++;}


%%
int main()
{
	puts("Enter a string");
	yylex();
	printf("Word Count: %d\nNumber Count %d\nUnknown Count %d",wc,nc,oc);
	return 0;
}