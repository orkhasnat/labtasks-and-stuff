#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include <windows.h>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            min = arr[min] > arr[j] ? j : min;
        }
        swap(arr[min], arr[i]);
    }
}
void Merge(int arr[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;
    int tmp[hi-lo+1];
    //copy(arr, arr + size, tmp);
    for (int k = lo; k <= hi; k++)
        arr[k] = tmp[k];
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            arr[k] = tmp[j++];
        else if (j > hi)
            arr[k] = tmp[i++];
        else if (tmp[j] < tmp[i])
            arr[k] = tmp[j++];
        else
            arr[k] = tmp[i++];
    }
}
void mergeSortAux(int arr[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int mid = (lo + hi) / 2; //lo + (hi - lo) / 2;
    mergeSortAux(arr, lo, mid);
    mergeSortAux(arr, mid + 1, hi);
    Merge(arr, lo, mid, hi);
}
void mergeSort(int arr[], int size)
{
    mergeSortAux(arr, 0, size);
}

int main()
{
    int arr[9] = {4, 5, 8, 9, 6, 1, 0, 2, 3};
    //bubbleSort(arr, 9);
    //selectionSort(arr, 9);
    mergeSort(arr, 9);
    for (int i = 0; i < 9; i++)
        cout
            << arr[i] << " ";
    cout << endl;
}
