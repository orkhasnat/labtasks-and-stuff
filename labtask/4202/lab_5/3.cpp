#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define push_back pb

int conv(string &m){
    int tmp=0;
    tmp=(1000*(m[0]-'0'))+(100*(m[1]-'0'))+(10*(m[3]-'0'))+(m[4]-'0');
    return tmp;
}

int main()
{
    int test,t=0,h1,h2,h3,h4,m1,m2,m3,m4,no=0;
    char c;
    scanf("%d",&test);
    while(test--)
    {
        int a=0,b=0,c=0,d=0;
        scanf("%d%:%d%d:%d",&h1,&m1,&h2,&m2);
        scanf("%d:%d%d:%d",&h3,&m3,&h4,&m4);
        a=(h1*60)+m1;
        b=(h2*60)+m2;
        c=(h3*60)+m3;
        d=(h4*60)+m4;
        if(h1<a&&d>a)
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


// int main()
// {
//     int i;
//     cin >> i;
//     for(int t=1;t<=i;t++)
//     {
//         string ms, me,fs,fe;
//         cin >> ms >> me>> fs >> fe;
//         int a=conv(ms),b=conv(me),c=conv(fs),d=conv(fe);
//         cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<"  "<<"\n";
//         if(a<c && b<c) printf("Case %d: Hits Meeting\n",t);
//         else if(c<a && d>a) printf("Case %d: Mrs Meeting\n",t);
//         else if(c<b && d<b) printf("Case %d: Hits Meeting\n",t);
//         else if(a<c && b>c) printf("Case %d: Mrs Meeting\n",t);
//     }
// }