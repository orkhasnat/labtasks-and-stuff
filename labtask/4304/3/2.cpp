#include <iostream>
#include <cmath>
using namespace std;
// here we used 1 based indexing.
// be cautious about inputing index values in the functions.
int N, heapSize;

void heapify_max(int *heap, int index){  //equivalent heapify_down()
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
void build_max_heap(int *heap){
    for (int i = heapSize / 2; i != 0; i--)
        heapify_max(heap, i);
}
void heapSort(int *heap){
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
int main(){
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