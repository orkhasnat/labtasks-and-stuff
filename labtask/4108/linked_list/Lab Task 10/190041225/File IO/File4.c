#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    FILE* from;
    FILE* to;
    if(argc!=3)
    {
        printf("usage : name source destination");
        exit(1);
    }
    if((fopen(argv[1],"rb"))==NULL)
    {
        printf("The file could not be opened.");
        exit(1);
    }
    if((fopen(argv[2],"wb"))==NULL)
    {
        printf("The file could not be written.");
        exit(1);
    }

    size_t x,y;
    unsigned char buffer[1000];
    do
    {
        x = fread(buffer, 1, sizeof buffer, from);
        if(x)
        {
            y = fwrite(buffer, 1, x, to);
        }
        else
            y = 0;
    }
    while ((x > 0) && (y == x));
    fclose(from);
    fclose(to);

}
