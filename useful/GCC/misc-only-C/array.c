#include <stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;++i)
    {
       scanf("%d",&a[i]);
       //printf("\n");

    }
    printf("%d\n",i);
     for (i=0;i<n;i++)
    {
       printf("%d\n",a[i]);
       //printf("\n");

    }



    return 0;
}



/*int main() {
   int n;
   scanf("%d",&n);
  int values[n];
  printf("Enter n integers: ");
  // taking input and storing it in an array
  for(int i = 0; i < n; ++i) {
     scanf("%d", &values[i]);
  }
  printf("Displaying integers: ");
  // printing elements of an array
  for(int i = 0; i < n; ++i) {
     printf("%d\n", values[i]);
  }
  return 0;
}
*/



