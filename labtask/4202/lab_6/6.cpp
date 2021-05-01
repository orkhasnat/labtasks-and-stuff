#include <iostream>
#include <vector>
using namespace std;

int capacity = 1;
int current = 0;

void erase(int *&arr, int start, int finish)
{
    int* tmp = new int[start];
    int i = 0;
    for (; i < start; i++)
        tmp[i]=arr[i];
    for (int j = finish; j < current; j++)
        tmp[i] = arr[j];
    delete[] arr;
    arr = tmp;
    current = current -(finish-start);
}
void popback(int *&arr)
{
    current--;
}
void pushback(int *&arr, int n) // usually we had to return int* but because we passed the pointer by a ref ,
{ // that means even modifying the pointer we still have the address of the pointer to know where the pointer points.
    // so no need of returning the pointer.
    if (current == capacity)
    {
        int *tmp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arr = tmp;
        capacity *= 2;
    }
    arr[current] = n;
    current++;
}
void insert(int *&arr, int index, int n)
{
    int* tmp =new int[index];
    for(int i=0;i<index;i++) tmp[i] =arr[i];
    pushback(tmp,n);
}
void print(int *&arr)
{
    for (int i = 0; i < current; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}

int main()
{
    /*printf("This part is for vectors!!\n");
    vector <int> yum;
    yum.push_back(10);
    yum.push_back(45);
    yum.push_back(15);
    yum.push_back(745);
    yum.push_back(4);
    yum.insert(yum.begin()+3,12);
    yum.pop_back();
    yum.erase(yum.begin()+2,yum.begin()+4);
    for(auto it:yum) cout<<it<<" ";
    */
    cout << "\nThis part is for arrays!!\n";
    int *a = new int[1];
    pushback(a, 10);
    pushback(a, 11);
    pushback(a, 13);
    pushback(a, 14);
    insert(a,2,12);
    //popback(a);
    //erase(a,0,1);
    print(a);
    delete[] a;
}