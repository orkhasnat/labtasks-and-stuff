#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    FILE *fp;
    char ch;
    if(argc!=2)
    {
        printf("usage : program_name <source_file>");
        exit(1);
    }

    if((fp=fopen(argv[1],"r"))==NULL)
       {
           printf("The file was not opened");
           exit(1);
       }
    while(!feof(fp))
        {
           ch=fgetc(fp);
           putchar(ch);
        }
    fclose(fp);
    return 0;
}
