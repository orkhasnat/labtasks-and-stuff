#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;

template <typename T>
void bubbleSort(T arr[], int begin, int end, int comp = 1)
{ // ascending order (for descending order pass comp=-1)
    comp = comp != -1 ? 1 : -1;
    for (int i = begin; i < end - 1; i++)
    {
        for (int j = begin; j < end - i - 1; j++)
        {
            if (comp * arr[j] > comp * arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}
template <typename T>
void selectionSort(T arr[], int begin, int end, int comp = 1)
{ // ascending order (for descending order pass comp=-1)
    comp = comp != -1 ? 1 : -1;
    int max = arr[begin];
    for (int i = begin; i < end - 1; i++)
    {
        for (int j = begin; j < end - i - 1; j++)
            max = comp * max < comp * arr[j] ? arr[j] : max;
        std::swap(arr[max], arr[end - i - 1]);
    }
}
template <typename T>
void print(T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void insertionSort(T arr[], int begin, int end, int comp = 1)
{
    // ascending order (for descending order pass comp=-1)
    comp = comp != -1 ? 1 : -1;
    for (int i = begin + 1; i < end; i++)
    {
        int tmp = arr[i];
        int j = begin;
        while (j >= begin && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

//------------MergeSort-------------------

template <typename T>
void merge(T arr[], int lo, int mid, int hi, int size)
{
    int i = lo, j = mid + 1, tmp[size], k;
    for (k = lo; k <= hi; k++)
        tmp[k] = arr[k]; // copying it to a temp array
    for (k = 0; k <= hi; k++)
    {
        // edge case
        if (i > mid)
            arr[k] = tmp[j++];
        else if (j > hi)
            arr[k] = tmp[i++];
        // usual case
        else if (tmp[j] < tmp[i])
            arr[k] = tmp[j++];
        else
            arr[k] = tmp[i++];
    }
}

template <typename T>
void mergeSort(T arr[], int lo, int hi, int size)
{
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2; //(lo + hi)/2;
    mergeSort(arr, lo, mid, size);
    mergeSort(arr, mid + 1, hi, size);
    merge(arr, lo, mid, hi, size);
}

int main()
{
    char fg[50] = "helloIUTImbackfromfookingDhaka";
    float gh[5] = {4.5, 6.7, 8.9, -0.45, 0.0098};
    int n = sizeof(fg) / sizeof(char);
    //bubbleSort(fg, 0, n, 1);
    //selectionSort(fg, 0, n, 1);
    //bubbleSort(gh, 1, 5, 1);
    mergeSort(fg, 0, n, n);
    print(fg, n);
    //print(gh, 5);
}