#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char * argv[])
{
    FILE* fp;
    char str[1000];
    char ch;
    int i;
    if(argc!=2)
    {
        printf("usage: name <source>");
        exit(1);
    }
    do
    {
        fflush(stdin);
        fflush(stdout);
        printf("1. Write to file\n");
        printf("2.Read from file\n");
        printf("3.Append to file\n");
        printf("0.Terminates the program\n");
        printf("Enter a choice: ");
        scanf("%d",&i);
        if(i==1)
        {
            if((fp=fopen(argv[1],"w"))==NULL)
            {
                printf("The file was not created.");
                exit(1);
            }
            fflush(stdin);
            {
                printf("Enter data to be written: ");
            }
            do
            {
                gets(str);
                strcat(str,"\n");
                if(*str!='\n')
                    fputs(str,fp);
            }
            while(*str!='\n');
            fclose(fp);
        }
        else if(i==2)
        {
            if((fp=fopen(argv[1],"r"))==NULL)
            {
                printf("The file was not opened");
                exit(1);
            }
            fflush(stdin);
            while(!feof(fp))
            {
                ch=fgetc(fp);
                putchar(ch);
            }
            fclose(fp);
        }
        else if(i==3)
        {
            if((fp=fopen(argv[1],"a"))==NULL)
            {
                printf("The file could not be appended.");
                exit(1);
            }
            fflush(stdin);
            do
            {
                gets(str);
                strcat(str,"\n");
                if(*str!='\n')
                    fputs(str,fp);
            }
            while(*str!='\n');
            fclose(fp);
        }
    }
    while(i!=0);
    return 0;
}
