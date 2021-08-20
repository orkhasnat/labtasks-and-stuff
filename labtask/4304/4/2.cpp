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
    void insertFront(int key);
    void insertBack(int key);
    void insert_atNode(int key, int prevKey);
    void updateNode(int newVal, int old);
    void removeFront();
    void removeNode(int key);
    void removeEnd();
    void displayFront();
    void displayRear();
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

void DList::insert_atNode(int key, int prevKey)
{
    if (!head)
        return; // for empty list
    Node *tmp = head;
    while (tmp->data != prevKey)
    {
        tmp = tmp->nxt;
        if (tmp == NULL)
        {
            cout << "Your given item doesnt exist!!\n";
            return;
        }
    }
    if (tmp == tail) //newNode will be appended at end
        return insertBack(key);
    Node *newNode = new Node();
    newNode->data = key;
    newNode->nxt = tmp->nxt;
    tmp->nxt = newNode;
    newNode->prev = tmp;
    newNode->nxt->prev = newNode;
}

void DList::updateNode(int newVal, int old)
{ // if theres duplicate keys it finds the first one and returns
    if (!head)
        return; // for empty list
    Node *tmp = head;
    while (tmp->data != old)
    {
        tmp = tmp->nxt;
        if (tmp == NULL)
        {
            cout << "Your given item doesnt exist!!\n";
            return;
        }
    }
    tmp->data = newVal;
}

void DList::removeFront()
{
    if (!head)
        return; // for empty list
    if (head == tail)
    { // for only one node
        delete head;
        head = tail = NULL;
        return;
    }
    Node *tmp = head;
    head = head->nxt;
    head->prev = NULL;
    delete tmp;
}

void DList::removeNode(int key)
{
    if (!head || !tail)
        return; // for empty list
    Node *tmp = head;
    if (tmp->data == key) //ie first node needs to be deleted.
        return removeFront();
    while (tmp->data != key)
    {
        tmp = tmp->nxt;
        if (tmp = tail) //ie last node
            return removeEnd();
        if (tmp->nxt == NULL)
        {
            cout << "Your given item doesnt exist!!\n";
            return;
        }
    } // if found then next steps
    tmp->prev->nxt = tmp->nxt;
    tmp->nxt->prev = tmp->prev;
    delete tmp;
}

void DList::removeEnd()
{
    if (!tail || !head)
        return;       //for empty list
    if (head == tail) //only one node
        return removeFront();
    Node *tmp = tail;
    tail = tail->prev;
    tail->nxt = NULL;
    delete tmp;
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

void DList::displayRear()
{
    if (tail)
    {
        Node *tmp = tail;
        cout << "Items Backwards: ";
        while (tmp)
        {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
    }
    else
        cout << "Empty Dlist";
    cout << endl;
}

void exec(DList *list, int ch)
{
    int item, oldval;
    switch (ch)
    {
    case 1:
        cout << "Give key:\t";
        cin >> item;
        list->insertFront(item);
        break;
    case 2:
        cout << "Give key:\t";
        cin >> item;
        list->insertBack(item);
        break;
    case 3:
        cout << "Give node:\t";
        cin >> oldval;
        cout << "Give newVal:\t";
        cin >> item;
        list->insert_atNode(item, oldval);
        break;
    case 4:
        cout << "Give old Value:\t";
        cin >> oldval;
        cout << "Give new value:\t";
        cin >> item;
        list->updateNode(item, oldval);
        break;
    case 5:
        cout << "Give key to remove:\t";
        cin >> item;
        list->removeNode(item);
        break;
    case 6:
        list->removeEnd();
        break;
    default:
        break;
    }
    list->displayFront();
    list->displayRear();
}

int main()
{
    int ch;
    DList *list = new DList();
    while (1)
    {
        cout << "Press 1 to inser at front\n"
             << "Press 2 to insert at back\n"
             << "Press 3 to insert after a node\n"
             << "Press 4 to update a node\n"
             << "Press 5 to remove a node\n"
             << "Press 6 to remove the last node\n"
             << "Press 7 to exit\n";
        scanf("%d", &ch);
        if (ch == 7)
            break;
        exec(list, ch);
    }
    delete list;
}