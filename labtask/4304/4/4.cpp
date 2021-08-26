#include <iostream>
using namespace std;

class List
{
    struct Node
    {
        int data;
        Node *nxt;
    };
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void insertFront(int key);
    void display();
    void insert(int n);
};

void List::display()
{
    if (head)
    {
        Node *tmp = head;
        cout << "Items:\t";
        while (tmp) //untill temp is null
        {
            cout << tmp->data << " ";
            tmp = tmp->nxt;
        }
    }
    else
        cout << "Empty List";
    cout << endl;
}
void List::insertFront(int key)
{
    Node *newNode = new Node();
    newNode->data = key;
    if (head) // if head has something then insert new node
        newNode->nxt = head;
    head = newNode;
}

void List::insert(int n)
{
    Node *tmp = head;
    while (tmp->data < n)
    {
        if (!tmp->nxt)
            break; //if tmp is the last element then break
        tmp = tmp->nxt;
    }
    if (tmp->data == n)
        return;
    Node *newNode = new Node();
    newNode->data = n;
    newNode->nxt = tmp->nxt;
    tmp->nxt = newNode;
}

int main()
{
    List *list = new List();
    int ch;
    cin >> ch;
    if (ch != -1)
        list->insertFront(ch);
    else
        return 0;
    while (cin >> ch && ch != -1)
        list->insert(ch);
    //cout<<ch<<" ";
    list->display();
}