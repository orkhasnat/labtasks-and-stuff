#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//=======================================

int main()
{
    int n,a;
    scanf("%d",&n);
    a= log10(n)+1; 
    printf("%d",a);
    return 0;
}

// double log10(double x)