#include <iostream>
#include <stack>
using std::cin, std::cout, std::endl;

class BinarySearchTree
{
    bool flag = false; // see if reservation can be done or not
    struct Node
    {
        int data;
        Node *left, *right;
        Node(int data)
            : data(data), left(NULL), right(NULL) {}
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
    Node* searchIter(int val){
        Node* tmp= root;
        while (tmp) // tmp != NUll
        {
            if(val==tmp->data) return tmp;
            else if(val<tmp->data)
                tmp=tmp->left;
            else 
                tmp= tmp->right;
        }
        return tmp;
    }

    bool found(int);

public:
    void insert(int);
    void print();
};

void BinarySearchTree::insert(int val)
{
    if (found(val) || found(val + 3) || found(val - 3) || found(val - 2) || found(val + 2) ||
        found(val + 1) || found(val - 1))
        flag=true;
    else
        insertIter(val); // if >=k-3 and <=k+3 not found then insert
}
bool BinarySearchTree::found(int val){
    // if(searchRec(root,val) /*!=NULL*/ ) // if val exists it returns true ie is found
    //     return true;
    if(searchIter(val) /*!=NULL*/ ) // if val exists it returns true ie is found
        return true;
    return false;
}
void BinarySearchTree::print()
{
    inOrderIter();
    if (flag)
        cout << "(Reservation failed)";
    flag=false;
    cout << endl;
}

int main()
{
    BinarySearchTree reservation;
    int input;
    while (cin >> input && input != -1)
    {
        reservation.insert(input);
        reservation.print();
    }
}

//50 75 53 25 60 29 45 42 28 10 -1
