#include <iostream>
#include <algorithm>

// std::sort(first,end,comp)
// Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool.
// So the compare funcion can only be return a>b or a<b or something of that sort.
// a<b for ascending a>b for descending
// comparison function object which returns ​true if the first argument is less than (i.e. is ordered before) the second.
//
// @how am i passing compare without any return type or parameters?? 
// ======================================================

bool compare(int a, int b)
{
    return a > b;
}

void bubblesort(int n, int arr[], bool (&compare)(int a, int b))
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (compare(arr[j], arr[j + 1]))
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void search(int arr[], int indices[], int count)
{
    // if there are duplicate values then this wont be accurate :<
    for (int i = 0; i < count; i++)
    {
        int j = 0;
        while (arr[i] != indices[j])
            j++;
        std::cout << j << " ";
    }
}

struct Indices
{
    int elm;
    int index;
};

bool cmp(Indices &a ,Indices &b){
    return a.elm < b.elm;
}

#define RT 1

int main()
{
    int n;
    std::cin >> n;
    if (RT) 
    {
        Indices arr[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i].elm;
            arr[i].index = i;
        }
        std::sort(arr, arr + n,cmp);
        for (int i = 0; i < n; i++)
        {
            std::cout<<arr[i].index<<" "; 
        }
        
    }
    else
    {
        int arr[n];
        int indices[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
            indices[i] = arr[i];
        }
        bubblesort(n, arr, compare);
        search(arr, indices, n);
    }
}