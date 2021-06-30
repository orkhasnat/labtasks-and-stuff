#include <iostream>
#include <stack>
using std::cin, std::cout, std::endl;

class BinarySearchTree
{
    bool flag = false; // see if reservation can be done or not
    struct Node
    {
        int data, sub; 
        Node *left, *right;
        Node(int data)
            : data(data), left(NULL), right(NULL), sub(0) {}
    };
    Node *root = NULL;
    void insertIter(int val)
    {
        Node *newNode = new Node(val);
        if (!root) // first node
        {
            root = newNode;
            return;
        }
        Node *tmp = root, *prev = NULL;
        while (tmp) // tmp !=NULL
        {           //traversal until found
            prev = tmp;
            if (val < tmp->data)
                tmp = tmp->left;
            else if (val > tmp->data)
                tmp = tmp->right;
        }
        if (val < prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
    void inOrderIter()
    {
        std::stack<Node *> a;
        Node *tmp = root;
        while (tmp || !a.empty()) // tmp!=NULL and stack not empty
        {
            if (tmp)
            { // tmp!=NULL
                a.push(tmp);
                tmp = tmp->left;
            }
            else
            {
                tmp = a.top(); // because tmp is null in the prev line
                cout << a.top()->data << " ";
                a.pop();
                tmp = tmp->right;
            }
        }
    }
    void update(int val)
    {
        Node *tmp=root;
        while (tmp)
        {
            if (val < tmp->data){
            	tmp->sub++;
                tmp = tmp->left;
            }
            else if (val > tmp->data){
				tmp->sub++;
                tmp = tmp->right;
            }
            else
                break; // because after insertion the new node will be child node            
        }
    }

public:
    void insert(int);
    void print();
    int query(int);
};

void BinarySearchTree::insert(int val)
{
    insertIter(val);
    update(val);
}
void BinarySearchTree::print()
{
    inOrderIter();
    cout << endl;
}
int BinarySearchTree::query(int val)
{
    int count = 0;
    Node *temp=root;
    while (temp->data != val)
    {
        if (val < temp->data)
            temp = temp->left;
        else
        {
            count++;                      // as the parent is eligible so the count is increased by 1
            if (temp->left)               // tmp has left child ie tmp->left not null
                count += temp->left->sub+1; //count all the children and itself
            temp = temp->right;
        }
    }
    if (temp->left != NULL) // the desired values left children would also come before
        count += temp->left->sub;
    return count;
}

int main()
{
    BinarySearchTree reservation;
    reservation.insert(50);
    reservation.insert(75);
    reservation.insert(25);
    reservation.insert(29);
    reservation.insert(45);
    reservation.insert(60);
    reservation.insert(10);

    cout << "(Current Reservations) ";
    reservation.print();

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << reservation.query(n) << endl;
    }
}
