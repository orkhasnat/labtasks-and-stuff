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
    void update_height(Node *x)
    {
        while (x)
        {
            updateNode(x);
            x = x->parent;
        }
    }
    void updateNode(Node *x)
    {
        x->height = 1 + std::max(height(x->left), height(x->right));
    }
    int balance_factor(Node *x)
    {
        return height(x->left) - height(x->right);
    }
    void inOrder(Node *x)
    { // InOrder Fashion : data(balance_factor)
        if (!x)
            return;
        inOrder(x->left);
        //std::cout << x->data << " ";
        printf("%d(%d) ", x->data, balance_factor(x));
        inOrder(x->right);
    }

    //REcursive Methods
    Node *insert(Node *x, int val)
    {
        if (!x)
            return new Node(val); // empty tree
        if (val < x->data)
        {
            x->left = insert(x->left, val);
            x->left->parent = x; // this is done after func call is because x->left may not exist before this
        }
        else if (val > x->data)
        {
            x->right = insert(x->right, val);
            x->right->parent = x; // yes it is always updating the parent ptr which is wastefull but if we give a condition it will be same waste without one
        }
        else
            return x; // duplicates not allowed
        updateNode(x);

        // fix imbalnced nodes
        int balance = balance_factor(x);
        if (balance > 1 && val < x->left->data) // LR rotation
            return rightRotateRec(x);
        if (balance < -1 && val > x->right->data) //RR rotation
            return leftRotateRec(x);
        if (balance > 1 && val > x->left->data) //LR rotation
        {
            x->left = leftRotateRec(x->left);
            return rightRotateRec(x);
        }
        if (balance < -1 && val < x->right->data) // RL rotation
        {
            x->right = rightRotateRec(x->right);
            return leftRotateRec(x);
        }
        // return unchanged pointer
        return x;
    }
    Node *rightRotateRec(Node *A)
    {
        Node *B = A->left;   //          A                       B
        Node *Br = B->right; //    B           Ar  ->        C            A
        // Perform rotation  //C      Br                              Br     Ar
        B->right = A;
        B->parent = A->parent;
        A->parent = B;
        A->left = Br;
        if (Br) // if Br is null then it has no parent pointer
            Br->parent = A;
        updateNode(A); 
        updateNode(B);
        return B;    // Return new root
    }

    Node *leftRotateRec(Node *A)
    {
        Node *B = A->right;
        Node *Bl = B->left;
        // Perform rotation
        B->left = A;
        B->parent - A->parent;
        A->parent = B;
        A->right = Bl;
        if (Bl) // if Bl is null then it has no parent pointer
            Bl->parent = A;
        updateNode(A);
        updateNode(B);
        return B;    // Return new root
    }

    // Iterative Methods-- some problems exist!!!
    void insert(int val)
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
        check_balance(newnode, val);
    }
    void check_balance(Node *x, int val)
    { // iterative fashion -- for recursive implement in insert func
        while (x)
        {
            int bf = balance_factor(x);
            if (std::abs(bf) > 1)
            { //if imbalanced -- bf<-1 || bf>1
                balance_node(x, bf, val);
                break;
            }
            x = x->parent;
        }
    }
    void balance_node(Node *x, int bf, int val)
    {
        if (bf > 1 and val < x->left->data)
            LLrotation(x);
        else if (bf > 1 and val > x->left->data)
            LRrotation(x);
        else if (bf < -1 and val < x->right->data)
            RLrotation(x);
        else if (bf < -1 and val > x->right->data)
            RRrotation(x);
    }

    void LLrotation(Node *A)
    { // right rotation
        Node *B = A->left;
        Node *Br = B->right;
        if (A == root) // fixing if root
        {
            root = B;
            B->parent = NULL; // =A->parent
        }
        else // fixing the parent of A
        {
            B->parent = A->parent;
            if (A == A->parent->right)
                A->parent->right = B;
            else
                A->parent->left = B;
        }
        // fix B
        B->right = A;
        A->parent = B;
        // fix A
        A->left = Br;
        if (Br) // if Br is null then it has no parent pointer
            Br->parent = A;
        update_height(A); //goes up recursively
    }
    void RRrotation(Node *A)
    { // left rotation
        Node *B = A->right;
        Node *Bl = B->left;
        if (A == root) // fixing if root
        {
            root = B;
            B->parent = NULL; // =A->parent
        }
        else // fixing the parent of A
        {
            B->parent = A->parent;
            if (A == A->parent->right)
                A->parent->right = B;
            else
                A->parent->left = B;
        }
        // fix B
        B->left = A;
        A->parent = B;
        // fix A
        A->right = Bl;
        if (Bl) // if Bl is null then it has no parent pointer
            Bl->parent = A;
        update_height(A); //goes up recursively
    }
    void LRrotation(Node *A)
    { // Easy way:
        // RRrotation(A->left);
        // LLrotation(A);

        // Hard way:
        Node *B = A->left;
        Node *C = B->right;
        if (A == root) // fixing if root
        {
            root = C;
            C->parent = NULL; // =A->parent
        }
        else // fixing the parent of A
        {
            C->parent = A->parent;
            if (A == A->parent->right)
                A->parent->right = C;
            else
                A->parent->left = C;
        }
        //fix A
        A->parent = C;
        A->left = C->right;
        if (C->right) // if null then no parent pointer
            C->right->parent = A;
        //fix B
        B->parent = C;
        B->right = C->left;
        if (C->left) // if null then no parent pointer
            C->left->parent = B;
        //fix C
        C->left = B;
        C->right = A;
        //fix heights -- we can update all parents of A/B and only update the other itself
        update_height(B);
        updateNode(A);
    }
    void RLrotation(Node *A)
    {
        // Easy way:
        // LLrotation(A->right);
        // RRrotation(A);

        // Hard way:
        Node *B = A->right;
        Node *C = B->left;
        if (A == root) // fixing if root
        {
            root = C;
            C->parent = NULL; // =A->parent
        }
        else // fixing the parent of A
        {
            C->parent = A->parent;
            if (A == A->parent->right)
                A->parent->right = C;
            else
                A->parent->left = C;
        }
        //fix A
        A->parent = C;
        A->right = C->left;
        if (C->left) // if null then no parent pointer
            C->left->parent = A;
        //fix B
        B->parent = C;
        B->left = C->right;
        if (C->right) // if null then no parent pointer
            C->right->parent = B;
        //fix C
        C->left = A;
        C->right = B;
        //fix heights -- we can update all parents of A/B and only update the other itself
        update_height(B);
        updateNode(A);
    }

    //searching
    Node *search(int key)
    { //iterative
        Node *tmp = root;
        while (tmp)
        {
            if (key < tmp->data)
                tmp = tmp->left;
            else if (key > tmp->data)
                tmp = tmp->right;
            else
                return tmp;
        }
        return tmp;
    }
    Node *search(Node *x, int key)
    { //recursive
        if (!x or x->data == key)
            return x;
        if (key < x->data)
            return search(x->left, key);
        return search(x->right, key);
    }

    //misc

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
    void push(int);
    void print();
    void LCA(int, int);
};

void AVLtree::push(int val)
{
    root = insert(root, val);
    //insert(val);
}
void AVLtree::print()
{
    inOrder(root);
    std::cout << std::endl;
}
void AVLtree::LCA(int p, int q)
{
    //std::cout << LowestCommonAncestor(root, p, q)->data << std::endl;
    std::cout << LowestCommonAncestor(p, q)->data << std::endl;
}