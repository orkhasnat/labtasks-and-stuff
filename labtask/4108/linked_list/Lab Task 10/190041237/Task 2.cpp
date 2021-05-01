/*  TAHMID RAHMAN
    DAMIAN FOREVER
     MATH LOVER
    NEVER GIVE UP
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
#define ar array
const int mxN=2e5;
const int MOD=1e9+7;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;
struct player{

  string player_name;
   int age;
   int rating;
   double salary;
   string pos;
   struct player* next;
};

struct club{
   string club_name;
   int year;
   float revenue;
   player players;
  struct club* next;

};
 club *head=NULL;
 club *root = NULL;

int len()
{
    ll lens=0;
    struct club *p=head;
    while(p!=NULL)
        {
            lens++;
            p=p->next;
        }
    return lens;
}

void in_ser()
{
  int n,y;
  string nam;
  float d;
  struct club*temp=(struct club*)malloc(sizeof(struct club));
  cout<<"Enter name:";
  cin>>nam;
  temp->club_name=nam;
  cout<<"Enter year of formation:";
  cin>>y;
  temp->year=y;
  cout<<"Enter yearly revenue:";
  cin>>d;
  temp->revenue=d;
  cout<<"Enter position in list:";
  temp->next=NULL;
  cin>>n;
  int siz=len();
   if(n==1)
   {
       temp->next=head;
       head=temp;
       return;
   }
   else if(siz+1<n)
   {
       cout<<"Invalid Position"<<endl;
       return;
   }

   struct club* temp1=head;
   for(int i=0;i<n-2;i++)
   {
       temp1=temp1->next;
   }
   temp->next=temp1->next;
   temp1->next=temp;

}
void del()
{

    struct club *cur=head;
    struct club *prev=NULL;
    cout<<"Enter the club you want to delete:"<<endl;
    string s;
    cin>>s;
    if(head==NULL)
    {
        cout<<"Invalid no Clubs found"<<endl;
    }
    else
    {
        while(cur->club_name!=s)
        {
            if(cur->next=NULL)
            {
                cout<<"NO Club found"<<endl;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }

        }
        if(cur==head)
        {
            head=head->next;
        }
        else
        {
            prev->next=cur->next;
        }

    }




}

void print()
{

 struct club *ptr=head;
 while(ptr!=NULL)
 {
    cout<<ptr->club_name<<endl;
    cout<<ptr->year<<endl;
    cout<<ptr->revenue<<endl;
    ptr=ptr->next;
 }

}
void print_opt()
{
    cout<<"What to you want to do?"<<endl;
    cout<<"1.  Create Club"<<endl;
    cout<<"2.  Delete Club"<<endl;
    cout<<"3.  View Club info"<<endl;
}
int main()
{
   cout<<"La Liga Database Intializing..."<<endl;
   int choice;
   bool f=true;
   while(f)
   {
       print_opt();
       cout<<"Choice:";
       cin>>choice;
       if(choice==1)
       {

           in_ser();
           cout<<"............."<<endl;
       }
       else if(choice==2)
       {
           del();
           cout<<"............."<<endl;
       }
       else if(choice==3)
       {
           int z=len();
           if(z==0)
            cout<<"No club to show"<<endl;
           else
           {
           cout<<"Showing Club list:"<<endl;
           print();
           }
           cout<<"............."<<endl;
       }
       else
       {
           cout<<"La liga database Terminating......"<<endl;
           f=false;
       }

   }
}


