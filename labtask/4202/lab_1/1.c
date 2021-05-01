#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//=======================================
void bitwiseway()
{
    int n;
    scanf("%d", &n);
    (n & 1) ? printf("Odd\n") : printf("Even\n");
    return;
}

void thecharway()
{
    char a, b, o[5] = {'1', '3', '5', '7', '9'};
    b = getchar();
    while (1)
    {
        a = getchar();
        if (a == ' ' || a == '\n')
            break;
        else
            b = a;
    }
    for (int i = 0; i < 5; i++)
    {
        if (b == o[i])
        {
            printf("odd\n");
            return;
        }
    }
    printf("even\n");
    return;
}

int main()
{
    printf("Which one you want to use?\n1.Using bitwise and\n2.Using char\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
        bitwiseway();
    else if (n == 2)
        thecharway();
    return 0;
}