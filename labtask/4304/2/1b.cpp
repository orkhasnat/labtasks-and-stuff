#include <iostream>
#include<stack>
using namespace std;

void print_tb(stack<int> a) //top to bottom
{
    cout << "size=" << a.size() << "\t"
         << "items= ";
    if (a.empty())
        cout << "NULL";
    while (!a.empty())
    { // because stack is already empty so it will not enter loop
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
}

void print_bt(stack<int> a){ //bottom to top
    int n=a.size(),j=n;
    cout << "size=" << n << "\t"<<"items= ";
    int arr[n];
    if (a.empty())
        cout << "NULL";
    while(!a.empty()){      // because stack is already empty so it will not enter loop
        arr[j-1]=a.top();
        j--;
        a.pop();
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,t;
    cin>>n>>t;
    stack<int> st;
    while(t--){
        int c;
        cin>>c;
        if(c==1) {
            int item;
            cin>>item;
            st.push(item);
            print_bt(st);
        }
        else if (c==2){
            if(!st.empty()) st.pop(); //without the if, terminates throwing a bad allocation !!
            print_bt(st);
        }
    }
}
// if pushed after the sizelimit then std::stack pushes the new item in the front of the stack 
// Example: 2(n) 3(t) 1 23 1 21 1 34 
//          print:- 34 23 21