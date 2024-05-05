#include <iostream>
#include <stack> // iterative in order traversal
#include <queue> // level order traversal (BFS)
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
    Node *minimum(Node *x)
    {
        while (x->left) // x->left !=NULL
            x = x->left;
        return x;
    }
    Node *maximum(Node *x)
    {
        while (x->right) // x->right !=NULL
            x = x->right;
        return x;
    }
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
    void levelOrderIter()
    {
        std::queue<Node *> q;
        Node *tmp = root;
        q.push(tmp);
        while (!q.empty())
        {
            tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if (tmp->left) // if not NULL
                q.push(tmp->left);
            if (tmp->right) // if not NULL
                q.push(tmp->right);
        }
        cout << endl;
    }
    int findHeightRec(Node *x)
    {
        if (!x)
            return -1; // x==NULL
        int leftSub = findHeightRec(x->left);
        int rightSub = findHeightRec(x->right);
        return std::max(leftSub, rightSub) + 1;
    }
    Node *searchRec(Node *x, int val)
    {
        if (!x || x->data == val) // either x==NULL or val at root
            return x;
        if (val < x->data)
            return searchRec(x->left, val);
        return searchRec(x->right, val);
    }
    Node *searchIter(int val)
    {
        Node *tmp = root;
        while (tmp) // tmp != NUll
        {
            if (val == tmp->data)
                return tmp;
            else if (val < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return tmp;
    }
    bool found(int val)
    {
        if (searchRec(root, val) /*!=NULL*/) // if val exists it returns true ie is found
            return true;
        // if(searchIter(val) /*!=NULL*/ ) // if val exists it returns true ie is found
        //         return true;
        return false;
    }
    Node *deleteRec(Node *x, int data)
    {
        if (!x)
            return x; // empty tree ;; x==NULL
        else if (data < x->data)
            x->left = deleteRec(x->left, data); // recurse on left sub tree
        else if (data > x->data)
            x->right = deleteRec(x->right, data); // recurse on right sub tree
        else
        { // actual deletion
            //case-1 : no children
            if (!x->left && !x->right) //both child is NULL
            {
                delete x;
                x = NULL; //handling dangling pointer
            }
            // case-2 : one child exists
            else if (!x->left) // right child exists
            {
                Node *tmp = x;
                x = x->right; // deleted nodes parent takes up the rC of deleted as its own rC
                delete tmp;
            }
            else if (!x->right) // left child exists
            {
                Node *tmp = x;
                x = x->left; // deleted nodes parent takes up the lC of deleted as its own lC
                delete tmp;
            }
            //case-3 : both child exist (most complicated one)
            else
            {
                Node *tmp = successor(x);                  // the minimum after x->right is the successor of x
                x->data = tmp->data;                       // copying the value of successor
                x->right = deleteRec(x->right, tmp->data); // removing the duplicate
            }
        }
        return x;
    }
    Node *successor(Node *x)
    {                                 // the node which will come after x if printed in a in-order fashion ie sorted way
        if (x->right)                 // x->right!=NULL
            return minimum(x->right); // if x->right exists then the min of that node will be succ
        Node *tmp = root, *succ = NULL;
        while (tmp) // if succ is an ancestor
        {
            if (tmp->data > x->data)
            {
                succ = tmp;
                tmp = tmp->left;
            }
            else if (tmp->data < x->data)
                tmp = tmp->right;
            else
                return succ;
        }
        return NULL;
    }

    // Lowest Common Ancestor --https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
    Node *LowestCommonAncestor(Node *x, int p, int q)
    { //recursive implementation
        if (!x)
            return NULL; // if x==null
        if (p < x->data and q < x->data)
            return LowestCommonAncestor(x->left, p, q);
        else if (p > x->data and q > x->data)
            return LowestCommonAncestor(x->right, p, q);
        return x;
    }
    Node *LowestCommonAncestor(int p, int q)
    { //iterative implementation
        Node *tmp = root;
        while (tmp)
        {
            if (tmp->data > p && tmp->data > q)
                tmp = tmp->left;
            else if (tmp->data < p && tmp->data < q)
                tmp = root->right;
            else
                break;
        }
        return tmp;
    }

public:
    void insert(int val)
    {
        //root = insertionRec(root, val);
        insertIter(val);
    }
    void deletion(int x)
    {
        deleteRec(root, x);
    }
    void print()
    {
        //inOrderRec(root);
        inOrderIter();
        cout << endl;
        levelOrderIter();
    }
    int maxHeight()
    {
        return findHeightRec(root);
    }
    void findSuccessor(int data)
    {
        Node *tmp = root;
        while (tmp)
        {
            if (data < tmp->data)
                tmp = tmp->left;
            else if (data > tmp->data)
                tmp = tmp->right;
            else
            {
                tmp = successor(tmp);
                break;
            }
        }
        tmp ? cout << tmp->data << endl : cout << "Successsor not found\n"; // if tmp not null
    }
    void LCA(int p, int q)
    {
        std::cout << LowestCommonAncestor(root, p, q)->data << std::endl;
        //std::cout << LowestCommonAncestor(p, q)->data << std::endl;
    }
};

int main()
{
    BinarySearchTree reservation;
    int input;
    while (cin >> input && input != -1)
    {
        reservation.insert(input);
        reservation.print();
    }
    cout << "Now to delete values\n";
    while (cin >> input && input != -1)
    {
        reservation.deletion(input);
        reservation.print();
    }
}
