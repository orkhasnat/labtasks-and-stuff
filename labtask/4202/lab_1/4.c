#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//=======================================
void voting(int n){
    char arr[n][7];
    int ni=0,sar=0;
    for(int i=0;i<n;i++){
        scanf(" %s",arr+i);
        if (tolower(**(arr+i)) == 'a') ni++;
        if (tolower(**(arr+i)) == 's') sar++;
    }
    //printf("%d %d\n",ni,sar);
    if(ni==sar) printf("No Imposter\n");
    else if (ni>sar) printf("Adham\n");
    else printf("Sartaj");
}

int main()
{
    int n;
    scanf("%d",&n);
    voting(n);
    return 0;
}