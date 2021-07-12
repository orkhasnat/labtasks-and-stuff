// Adelson-Velski and Landis Tree
#include <iostream>
class AVLtree
{
    struct Node
    {
        int data;
        int height;
        Node *left, *right, *parent;
        Node(int data)
            : data(data), height(0), left(NULL), right(NULL), parent(NULL) {}
    };
    Node *root = NULL;
    int height(Node *x)
    {
        if (x == NULL)
            return -1; // if height is initialized as 1 then change -1 to 0
        else
            return x->height;
    }
    int balance_factor(Node *x)
    {
        return height(x->left) - height(x->right);
    }

    Node *insertRec(Node *x, int val)
    {
        if (!x)
            return new Node(val); // empty tree
        if (val < x->data)
        {
            x->left = insertRec(x->left, val);
            x->left->parent = x; // this is done after func call is because x->left may not exist before this
        }
        else if (val > x->data)
        {
            x->right = insertRec(x->right, val);
            x->right->parent = x; // yes it is always updating the parent ptr which is wastefull but if we give a condition it will be same waste without one
        }
        else
            return x; // duplicates not allowed

        x->height = 1 + std::max(height(x->left), height(x->right));
        return x;
    }

    void insertIter(int val)
    {
        Node *newnode = new Node(val);
        if (!root)
        {                   // empty free
            root = newnode; // first node
            return;
        }
        Node *tmp = root, *prev;
        while (tmp)
        {
            prev = tmp;
            if (val < tmp->data)
                tmp = tmp->left;
            else if (val > tmp->data)
                tmp = tmp->right;
            else
                return;
        }
        newnode->parent = prev;
        if (val < newnode->parent->data)
            newnode->parent->left = newnode; // prev->left = newnode
        else
            newnode->parent->right = newnode; // prev->right = newnode
        update_height(newnode);
    }

    void inOrderRec(Node *x)
    { // InOrder Fashion : data(balance_factor)
        if (!x)
            return;
        inOrderRec(x->left);
        printf("%d(%d) ", x->data, balance_factor(x));
        inOrderRec(x->right);
    }
    void update_height(Node *x)
    {
        while (x)
        {
            x->height = 1 + std::max(height(x->left), height(x->right));
            x = x->parent;
        }
    }

public:
    void push(int);
    void print();
};

void AVLtree::push(int val)
{
    //root = insertRec(root,val);
    insertIter(val);
}
void AVLtree::print()
{
    inOrderRec(root);
    std::cout << std::endl;
}

int main()
{
    AVLtree tree;
    int input;
    while (std::cin >> input && input != -1)
    {
        tree.push(input);
        tree.print();
    }
}

//12 8 5 11 20 4 7 17 18 -1
