#include <iostream>
#include <queue>
using std::cin, std::cout, std::endl;

class BinarySearchTree
{
    struct Node
    {
        int data;
        Node *left, *right;
        Node(int data)
            : data(data), left(NULL), right(NULL) {}
    };
    Node *root = NULL;
    void inOrderRec(Node *x)
    { // left--root--right
        if (!x)
            return; // x==NULL
        inOrderRec(x->left);
        cout << x->data << " ";
        inOrderRec(x->right);
    }
    Node *insertionRec(Node *x, int val)
    {
        if (!x) // x==NULL
            return new Node(val);
        if (val < x->data)
            x->left = insertionRec(x->left, val);
        else if (val > x->data)
            x->right = insertionRec(x->right, val);
        // duplicates not allowed
        return x;
    }
public:
    void insert(int);
    void levelOrder();
};

void BinarySearchTree::insert(int val)
{
    root = insertionRec(root, val);
}
void BinarySearchTree::levelOrder()
    {
        std::queue<Node *> q;
        Node* tmp=root;
        q.push(tmp);
        while (!q.empty()){
            tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if (tmp->left) // if not NULL
                q.push(tmp->left);
            if (tmp->right) // if not NULL
                q.push(tmp->right);
        }
        cout<<endl;
    }
int main()
{
    BinarySearchTree reservation;
    int input;
    while (cin >> input && input != -1)
        reservation.insert(input);
    reservation.levelOrder();
}