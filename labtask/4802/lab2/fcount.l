%option noyywrap
%{
	#include<stdio.h>
	#include <stdlib.h>
	int nc=0,wc=0,oc=0,lc=0;

%}


%%
[\t ] ;
[\n]+ {lc++;}
[a-zA-Z]+ {wc++;}
[+-]?([0-9]*\.)?[0-9]+ {nc++;}
. {oc++;}
%%
int main(int argc,char **argv)
{
	printf("\t\twords\tnumbers\tlines\tcharacters\n\n");
	int i=1,tn=0,tw=0,tl=0,tc=0;
	for (;i<argc;i++){
		
		FILE *file;
		file = fopen(argv[i],"r");
		if(!file) {
			printf("\nSorry no such file found\n");
			exit(0);
		}
		else
			yyin=file;
		yylex();
		int chr=nc+wc+oc;
		printf("%s\t%d\t%d\t%d\t%d\n",argv[i],wc,nc,lc,chr);
		tn+=nc;
		tw+=wc;
		tl+=lc;
		tc+=chr;
	}
	printf("Total\t%d\t%d\t%d\t%d\n",tw,tn,tl,tc);
	return 0;
}