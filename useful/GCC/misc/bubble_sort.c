#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

/*void swap (int &a,int &b)
{
  int t;
  t=a;
  a=b;
  b=t;
    return;
}

*/


int main()
{
  int n,i,j,count,t,swapped=0;
  scanf("%d",&n);
  int a[n];
   for (i=0;i<n;++i)
    {
       scanf("%d",&a[i]);
       //printf("\n");
    }
  scanf("%d",&count);
  for (i=0;i<count-1;i++)
  {
    for ( j = 0; j<count-1-i; j++)
    {
      if(a[j]>a[j+1]) {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        swapped=1;
      }
      if (swapped==0) break;
    }

  }

  for ( i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }

  return 0;
}
