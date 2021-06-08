#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n,i,b,r,t;
    scanf("%d",&n);
    b=0;
    t=1;
    for(i=0;n>0;i++)
    {
        r=n%2;
        n=n/2;
        b=b+r*t;
        t=t*10;

    }



printf("%d",b);

    return 0;
}
