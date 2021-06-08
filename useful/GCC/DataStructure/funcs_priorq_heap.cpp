// ITS A BIT MESSY
// PLEASE CLEAN UP THE CODE WHEN YOU CAN
// MAYBE IMPLEMENT THIS USING CLASS (OOP)
// ALSO ADD A heapify_up()
#include <iostream>
#include <cmath>
#include <algorithm>
int heapSize, heap[100 /*heapSize*/];

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

void heapify_down(int index)
{
    int left = 2 * index, right = (2 * index) + 1, largest;
    if (left <= heapSize && heap[left] > heap[index]) // first check if left is not out of bounds
        largest = left;                               // leftCh is bigger than parent
    else
        largest = index;
    if (right <= heapSize && heap[right] > heap[largest])
        largest = right; // rightCh is bigger than the prev largest
    if (largest != index)
    {
        std::swap(heap[largest], heap[index]);
        heapify_down(largest);
    }
}
void heapify_up(int i)
{ // i= index
    // check if the node at index `i` and its parent violate the heap property
    if (i && heap[findParent(i)] < heap[i])
    {
        // swap the two if heap property is violated
        std::swap(heap[i], heap[findParent(i)]);

        // call heapify-up on the parent
        heapify_up(findParent(i));
    }
}

void build_max_heap()
{
    for (int i = heapSize / 2; i != 0; i--)
        heapify_down(i);
}

void heapSort()
{
    build_max_heap();
    int i = heapSize;
    while (i != 1)
    {
        std::swap(heap[i], heap[1]);
        heapSize--;
        heapify_down(1);
        i--;
    }
}

// now priority queue max heap implementation functions
int heap_maximum()
{
    return heap[1];
}

int extract_max()
{
    int max = heap[1];
    std::swap(heap[1], heap[heapSize]);
    heapSize--;
    heapify_down(1);
    return max;
}
void heap_insert(int value)
{
    heapSize++;
    heap[heapSize] = value;
    heapify_up(heapSize);
    // non-recursive method
    /*int i = heapSize; 
        while (heap[i]>heap[findParent(i)] && i>1)
        {
            std::swap(heap[i],heap[findParent(i)]);
            i=i/2; // returning to the parent
        }*/
}

void maxHeap_increseKey(int position, int newValue)
{
    heap[position] = newValue;
    heapify_up(position);
}
void maxheap_decreseKey(int position, int newValue)
{
    heap[position] = newValue;
    heapify_down(position);
}