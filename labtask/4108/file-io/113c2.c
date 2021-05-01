#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* string;
//-------------------------------------------------------------------
#define ERROR printf("File Error")

int main(int argc, string argv[])
{
    FILE *fp;
    if (argc != 2)
    {
        printf("Usuage: program_name <text_file.txt>\n");
        exit(1);
    }
    //---------------------------------
    printf("Which Mode?\n1. Write to file\n2. Read from file\n3. Append to file\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
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
    else if (choice == 1)
    {
        if ((fp = fopen(argv[1], "w")) == NULL)
        {
            ERROR;
            exit(1);
        }
        printf("Enter Text:\n");
        char ch[100];
        do
        {
            fflush(stdin);
            gets(ch);
            strcat(ch, "\n");
            if (*ch != '\n')
                fputs(ch, fp);

        } while (*ch != '\n');
        printf("...Finished Editing!");
        fclose(fp);
        return 0;
    }

    else if (choice == 3)
    {
        if ((fp = fopen(argv[1], "a")) == NULL)
        {
            ERROR;
            exit(1);
        }
        printf("Enter Text:\n");
        char ch[100];
        do
        {
            fflush(stdin);
            gets(ch);
            strcat(ch, "\n");
            if (*ch != '\n')
                fputs(ch, fp);

        } while (*ch != '\n');
        printf("...Finished Editing!");
        fclose(fp);
        return 0;
    }
}

