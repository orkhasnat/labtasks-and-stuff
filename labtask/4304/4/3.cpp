#include <iostream>
using namespace std;

class DList
{
    struct Node
    {
        int data;
        Node *prev;
        Node *nxt;
    };
    Node *head, *tail;

public:
    DList()
    {
        head = NULL;
        tail = NULL;
    }
    ~DList()
    {
        delete head;
    }
    void insertFront(int key);
    void insertBack(int key);
    int removeFront();
    int removeEnd();
    void displayFront();
};

void DList::insertFront(int key)
{
    Node *newNode = new Node();
    newNode->data = key;
    if (head)
    { // if head has something
        newNode->nxt = head;
        if (!head->nxt) // if list has only one node before inserting
            tail = head;
        head->prev = newNode; //2nd node points to the first node
        head = newNode;
    }
    else
    { // if empty list
        tail = newNode;
        head = newNode;
    }
}

void DList::insertBack(int key)
{
    if (!head || !tail)
        return insertFront(key); // for empty list
    Node *newNode = new Node();
    newNode->data = key;
    Node *tmp = tail;
    tmp->nxt = newNode;
    newNode->prev = tmp;
    tail = newNode;
}

int DList::removeFront()
{
    if (!head)
        return '\0'; // for empty list
    int data = head->data;
    if (head == tail)
    { // for only one node
        delete head;
        head = tail = NULL;
        return data;
    }
    Node *tmp = head;
    head = head->nxt;
    head->prev = NULL;
    delete tmp;
    return data;
}

int DList::removeEnd()
{
    if (!tail || !head)
        return '\0'; //for empty list
    int data = tail->data;
    if (head == tail) //only one node
        return removeFront();
    Node *tmp = tail;
    tail = tail->prev;
    tail->nxt = NULL;
    delete tmp;
    return data;
}

void DList::displayFront()
{
    if (head)
    {
        Node *tmp = head;
        cout << "Items Forwards: ";
        while (tmp) //until temp is null
        {
            cout << tmp->data << " ";
            tmp = tmp->nxt;
        }
    }
    else
        cout << "Empty DList";
    cout << endl;
}

class Deque : public DList
{
    DList queue;

public:
    inline void push_front(int key) { queue.insertFront(key); }
    inline void push_back(int key) { queue.insertBack(key); }
    inline int pop_front() { return queue.removeFront(); }
    inline int pop_back() { return queue.removeEnd(); }
    inline void print() { queue.displayFront(); }
};

int main()
{
    Deque dq;
    int ch;
    bool f = true;
    while (f)
    {
        cout << "Press 1 to push_front\n"
             << "Press 2 to push_back\n"
             << "Press 3 to pop_front\n"
             << "Press 4 to pop_back\n"
             << "Press 5 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Input Key: ";
            cin >> ch;
            dq.push_front(ch);
            break;
        case 2:
            cout << "Input Key: ";
            cin >> ch;
            dq.push_back(ch);
            break;
        case 3:
            cout << "Element: " << dq.pop_front() << endl;
            break;
        case 4:
            cout << "Element: " << dq.pop_back() << endl;
            break;
        case 5:
            f = false;
            break;
        default:
            break;
        }
        dq.print();
    }
}