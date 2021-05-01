#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char *string;
//-------------------------------------------------------------------
#define ERROR printf("File Error!")

int main(int argc, string argv[])
{
    FILE *fp;
    if (argc != 2)
    {
        printf("Usuage: program_name <input.txt>\n");
        exit(1);
    }

    if ((fp = fopen(argv[1] ,"r")) == NULL)
    {
        ERROR;
        exit(1);
    }
    int ch;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ferror(fp))
        {
            ERROR;
            exit(1);
        }
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}