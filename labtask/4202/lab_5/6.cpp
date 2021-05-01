#include<iostream>
using namespace std;

int main()
{
    int test,t=0,h1,h2,h3,h4,m1,m2,m3,m4,no=0;
    char c;
    scanf("%d",&test);
    while(test--)
    {
        int a=0,b=0,c=0,d=0;
        scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
        scanf("%d:%d%d:%d",&h3,&m3,&h4,&m4);
        a=(h1*60)+m1;
        b=(h2*60)+m2;
        c=(h3*60)+m3;
        d=(h4*60)+m4;
        if(h1<a&&d<a)
        {
            if(c<b)
            printf("Case %d: Hits Meeting\n",++no);
            else
            printf("Case %d: Mrs Meeting\n",++no);
        }
        else if(c>a&&d>a)
        {
            if(c>b)
            printf("Case %d: Hits Meeting\n",++no);
            else
            printf("Case %d: Mrs Meeting\n",++no);
        }
        else
        printf("Case %d: Mrs Meeting\n",++no);

    }
    return 0;
}