// DO NOT FORGET ITS IMPLEMENTED WITH 1 BASED INDEXING
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, heapSize;
int findParent(int i)
{ // find parent in 1 based indexing
    if (i <= 1)
        return 0;
    return floor(i / 2);
}
int findLch(int i)
{ // find left child in 1  based indexing
    return 2 * i;
}
int findRch(int i)
{ // find right child in 1 based indexing
    return 2 * i + 1;
}
void heapify_max(int *heap, int index)
{ //equivalent heapify_down()
    int left = 2 * index, right = (2 * index) + 1, largest;
    if (left <= heapSize && heap[left] > heap[index]) // first check if left is not out of bounds
        largest = left;                               // leftCh is bigger than parent
    else
        largest = index;
    if (right <= heapSize && heap[right] > heap[largest])
        largest = right; // rightCh is bigger than the prev largest
    if (largest != index)
    {
        swap(heap[largest], heap[index]);
        heapify_max(heap, largest);
    }
}
void heapify_up(int *heap, int i)
{
    // check if the node at index `i` and its parent violate the heap property
    if (i && heap[findParent(i)] < heap[i])
    {
        swap(heap[i], heap[findParent(i)]);
        heapify_up(heap, findParent(i)); // heapifyUp on the parent
    }
}
void build_max_heap(int *heap)
{
    for (int i = heapSize / 2; i != 0; i--)
        heapify_max(heap, i);
}
int heap_maximum(int *heap)
{
    return heap[1];
}
void heapSort(int *heap)
{
    build_max_heap(heap);
    int i = heapSize;
    while (i != 1)
    {
        swap(heap[i], heap[1]);
        heapSize--;
        heapify_max(heap, 1);
        i--;
    }
}
int extract_max(int *heap)
{
    int max = heap[1];
    swap(heap[1], heap[heapSize]);
    heapSize--;
    heapify_max(heap, 1);
    return max;
}
void heap_insert(int *heap, int value)
{
    heapSize++;
    heap[heapSize] = value;
    heapify_up(heap, heapSize);
    // non-recursive method
    /*int i = heapSize;
        while (heap[i]>heap[findParent(i)] && i>1)
        {
            swap(heap[i],heap[findParent(i)]);
            i=i/2; // returning to the parent
        }*/
}
void maxHeap_increseKey(int *heap, int position, int newValue)
{
    heap[position] = newValue;
    heapify_up(heap, position);
}
void maxheap_decreseKey(int *heap, int position, int newValue)
{
    heap[position] = newValue;
    heapify_max(heap, position);
}

int main()
{
    cin >> N;
    heapSize = N;
    int arr[N];
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    heapSort(arr);
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << endl;
}