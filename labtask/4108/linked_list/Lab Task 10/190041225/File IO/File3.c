#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char * argv[])
{
    FILE* fp;
    FILE* from;
    FILE* to;
    char str[1000];
    char name[100];
    char ch;
    int i;
    long x;
    if(argc!=2)
    {
        printf("usage: name <source>");
        exit(1);
    }
    do
    {
        fflush(stdin);
        fflush(stdout);
        printf("1. Create a new file\n");
        printf("2. Edit an existing file\n");
        printf("3. Rename a file\n");
        printf("4. Read from file");
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
        else if(i==4)
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
        else if(i==2)
        {
            if((fp=fopen(argv[1],"w"))==NULL)
            {
                printf("The file was not edited");
                exit(1);
            }
            fflush(stdin);
            printf("Which position has to be changed? : ");
            scanf("%ld",&x);
            fseek(fp,x,SEEK_SET);
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
        else if(i==3)
        {
            fflush(stdin);
            printf("Enter the new name of the file: ");
            gets(name);
            if((from=fopen(argv[1],"r"))==NULL)
            {
                printf("The file was not opened");
                exit(1);
            }
             if((to=fopen(name,"w"))==NULL)
            {
                printf("The new file was not opened");
                exit(1);
            }
            while(!feof(from))
            {
                ch=fgetc(from);
                if(!feof(from)) fputc(ch,to);
            }
            fclose(from);
            fclose(to);
            remove(argv[1]);
            argv[1]=name;
        }
    }
        while(i!=0);
        return 0;
}

