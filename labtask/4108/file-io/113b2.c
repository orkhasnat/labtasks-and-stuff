#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file1, *file2;
    if (argc != 3)
    {
        printf("Usage programme_name <file 1> <file 2>\n");
        exit(1);
    }

    if ((file1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error openning file 1\n");
        exit(1);
    }

    if ((file2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("Error openning file 2\n");
        exit(1);
    }
    int i = 0, j = 0;
    int a1, a2;
    while (1)
    {
        i++;
        a1 = fgetc(file1);
        a2 = fgetc(file2);
        if (a1 == EOF && a2 == EOF)
            break;
        if (a1 != a2)
        {
            j++;
            printf("%d ", i);
        }
    }

    fclose(file1);
    fclose(file2);
    if (j == 0)
        printf("same file!");
    return 0;
}
