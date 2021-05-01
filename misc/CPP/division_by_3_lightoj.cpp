#include <stdio.h>
//using namespace std;
//#define endl '\n'
//this one didnt work 
/*int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //******************************************************
    unsigned int tc;
    //cin >> tc;
    scanf("%ud",&tc);
    for(int u=1;u<=tc;u++)
    {
        long long int a, b sum = 0;
        int count=0;
        //cin >> a >> b;
        scanf("%lld%lld",&a,&b);
        for (int k = a; k <= b; k++)
        {
            sum=0;
            for (int i = 1; i <= k; i++)
            {
                sum += i;
            }
            if (sum % 3 == 0)
                    count++;
           // cout<< count<<"   "<<sum<< endl;
        }
        //cout << "Case : " << count << endl;
        printf("Case %ud: %d\n",u,count);
    }
    return 0;
}*/
long long divc(long long n)
{
   
    int count = (n/3)*2;
    if (n%3==2) count++;
    return count;
}

int main()
{
 long long tc;
    int cases=1;
    scanf("%lld",&tc);
    while(tc--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        
        printf("Case %d: %d\n",cases++,divc(b)-divc(a-1));
        //cases++;

    }
    return 0;
}

