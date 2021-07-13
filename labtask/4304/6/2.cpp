// Adelson-Velski and Landis Tree
#include <iostream>
#include <stack>
#define debug puts("debug\n")
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
            __update(x);
            x = x->parent;
        }
    }
    void __update(Node *x)
    {
        x->height = 1 + std::max(height(x->left), height(x->right));
    }
    int balance_factor(Node *x)
    {
        return height(x->left) - height(x->right);
    }

    void inOrderIter()
    {
        std::stack<Node *> st;
        Node *tmp = root;
        while (tmp or !st.empty())
        {
            if (tmp)
            {
                st.push(tmp);
                tmp = tmp->left;
            }
            else
            {
                tmp = st.top(); // because tmp is now null ; need previous node
                printf("%d(%d) ", st.top()->data, balance_factor(st.top()));
                st.pop();
                tmp = tmp->right;
            }
        }
        printf("\n");
    }

    void insertIter(int val)
    {
        Node *newnode = new Node(val);
        if (!root)
        {                   // empty free
            root = newnode; // first node
            printf("%d(%d)\nBalanced\n", root->data, balance_factor(root));
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
        bool check = false;
        while (x)
        {
            int bf = balance_factor(x);
            if (std::abs(bf) > 1)
            { //if imbalanced -- bf<-1 || bf>1
                check = true;
                balance_node(x, bf, val);
                break;
            }
            x = x->parent;
        }
        if (!check)
        {
            inOrderIter();
            printf("Balanced\n");
        }
    }
    void balance_node(Node *x, int bf, int val)
    {
        inOrderIter();
        printf("Imbalance at Node: %d\n", x->data);
        if (bf > 1 and val < x->left->data)
            LLrotation(x);
        else if (bf > 1 and val > x->left->data)
            LRrotation(x);
        else if (bf < -1 and val < x->right->data)
            RLrotation(x);
        else if (bf < -1 and val > x->right->data)
            RRrotation(x);
        printf("Status: ");
        inOrderIter();
    }

    void LLrotation(Node *A)
    { // right rotation
        printf("LL case\nRight_rotate(%d)\n", A->data);
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
        update_height(A);
    }
    void RRrotation(Node *A)
    { // left rotation
        printf("RR case\nLeft_rotate(%d)\n", A->data);
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
        printf("LR case\nLeft_rotate(%d),Right_rotate(%d)\n", B->data, A->data);
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
        //fix heights
        __update(B);
        update_height(A);
    }
    void RLrotation(Node *A)
    {
        // Easy way:
        // LLrotation(A->right);
        // RRrotation(A);

        // Hard way:
        Node *B = A->right;
        Node *C = B->left;
        printf("RL case\nRight_rotate(%d),Left_rotate(%d)\n", B->data, A->data);
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
        //fix heights
        __update(B);
        update_height(A);
    }

public:
    void push(int);
    void print();
    void printRoot();
};

void AVLtree::push(int val)
{
    insertIter(val);
}
void AVLtree::printRoot()
{
    std::cout << "Root:" << root->data << std::endl;
}
void AVLtree::print()
{
    inOrderIter();
    std::cout << "Root:" << root->data << std::endl;
}

#define dash printf("---------------------------\n")

int main()
{
    AVLtree tree;
    int input;
    while (std::cin >> input && input != -1)
    {
        tree.push(input);
        tree.printRoot();
        dash;
    }
    std::cout << "Status: ";
    tree.print();
    std::cout << std::endl;
}
// 12 9/8 5 11 20 4 7 17 18 -1
// 12 9 5 11 20 15 7 3 6 27 -1
// 10 5 4 2 13 27 6 7 20 25 26 3 -1
