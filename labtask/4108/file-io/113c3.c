#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char *string;
//-------------------------------------------------------------------
#define ERROR printf("File Error")

FILE *rename_file(FILE *from)
{
    printf("What is the new name?");
    char *sh;
    scanf("%s", sh);
    FILE *to;
    char ch;

    if ((to = fopen(sh, "w")) == NULL)
    {
        printf("Error writing destination file.\n");
        exit(1);
    }

    while (!feof(from))
    {
        ch = fgetc(from);
        if (!feof(from))
        {
            fputc(ch, to);
        }
    }
    //printf("Successfully copied the file\n");
    fclose(from);

    fclose(to);
    return to;
}

int main(int argc, string argv[])
{
    FILE *fp;
    if (argc != 2)
    {
        printf("Usuage: program_name <text_file.txt>\n");
        exit(1);
    }
    //---------------------------------
    printf("Which Mode?\n1. Create a new file\n2. Edit an file\n3. Rename a file\n4. Read from file.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 4)
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
        FILE *from, *to;
        if ((from = fopen(argv[1], "r")) == NULL)
        {
            printf("Error reading file\n");
            exit(1);
        }
        to = rename_file(from);
        remove(argv[1]);
    }

    else if (choice == 2)
    {
        //FILE *from,*to;
        if ((fp = fopen(argv[1], "r+")) == NULL)
        {
            printf("Error reading file\n");
            exit(1);
        }
        int pos;
        printf("Enter text position     ");
        scanf("%d", &pos);
        fseek(fp, pos, SEEK_SET);
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
    return 0;
}
