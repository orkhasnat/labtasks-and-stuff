#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   int n,i;
   scanf("%d",&n);

 for (i=2;n>i;i++)
    {

    if(n%i==0) {
        printf("%d ",i);
    }

    }
  return 0;
}
