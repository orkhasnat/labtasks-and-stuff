#include <iostream>
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
    int findHeightRec(Node *x)
    {
        if (!x)
            return -1; // x==NULL
        int leftSub = findHeightRec(x->left);
        int rightSub = findHeightRec(x->right);
        return std::max(leftSub, rightSub) + 1;
    }

public:
    void insert(int);
    int maxHeight()
    {
        return findHeightRec(root);
    }
};

void BinarySearchTree::insert(int val)
{
    root = insertionRec(root, val);
}
int main()
{
    BinarySearchTree r;
    int input;
    while (cin >> input && input != -1)
        r.insert(input);
    cout << r.maxHeight()<<endl;
}
