#include <stdlib.h>
#include <stdio.h>
//copying files.
int main(int argc,char *argv[1])
{
    FILE *from, *to;
    char ch;
    if (argc!= 3)
    {
        printf("Usage programme_name <hello.exe> <test.exe>");
        exit(1);
    }
    if ((from = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error reading source file\n");
        exit(1);
    }

    if ((to = fopen(argv[2], "wb")) == NULL)
    {
        printf("Error writing destination file.\n");
        exit(1);
    }

    while (!feof(from))
    {
        ch = fgetc(from);
        if (!ferror(from))
        {
            fputc(ch, to);
        }
    }
    printf("Successfully copied the file\n");
    fclose(from);
    fclose(to);
    return 0;
}