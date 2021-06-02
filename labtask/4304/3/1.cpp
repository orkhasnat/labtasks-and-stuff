#include <iostream>
using namespace std;

int arrSize, front = -1, rear = -1;

#define linear 0
#if linear //using linear array
void enqueue(int *arr)
{
    int item;
    cin >> item;
    if (front == -1 /*&& rear == -1*/ /*do i need this??*/) //if queue empty or not
        front++;
    else if (rear == arrSize - 1) //if pushing after reaching capability
    {
        cout << "Overflow\n";
        return;
    }
    rear++;
    arr[rear] = item;
}
void dequeue(int *arr)
{
    if (front == -1)
    {
        cout << "Queue empty!!!\n";
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
    //else
        front++;
}
#else //using circular array
void enqueue(int *arr)
{
    int item;
    cin >> item;
    if (front == -1 && rear == -1)
        front++;
    else if (rear == arrSize - 1)
    {
        cout << "Overflow\n";
        return;
    }
    rear = (rear + 1) % arrSize;
    arr[rear] = item;
}
void dequeue(int *arr)
{
    if (front == -1)
    {
        cout << "Queue empty!!!\n";
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % arrSize;
}
#endif

void print(int *arr)
{
    cout << "items ";
    if (front = -1 && rear == -1)
    {
        cout << "NULL\n";
        return;
    }
    for (int i = front; i <= rear; )
    {
        cout << arr[i] << " ";
        #if linear
        i++;
        #else 
        i=(i+1)%arrSize;
        #endif
    }
    cout << endl;
}

int main()
{
    cin >> arrSize;
    int queue[arrSize];
    int t, cmd;
    cin >> t;
    while (t--)
    {
        cin >> cmd;
        if (cmd == 1)
            enqueue(queue);
        else if (cmd == 2)
            dequeue(queue);
        else
            cout << "Wrong command\n";
        print(queue);
    }
}