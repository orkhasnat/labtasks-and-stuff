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
        std::stack<Node*> a;
        Node *tmp = root;
        while (tmp || !a.empty()) // tmp!=NULL and stack not empty
        {
            if (tmp){ // tmp!=NULL
                a.push(tmp);
                tmp = tmp->left;
            }
            else{
                tmp=a.top(); // because tmp is null in the prev line
                cout << a.top()->data << " ";
                a.pop();
                tmp = tmp->right;
            }
        }
    }
	void levelOrderIter()
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
	int findHeightRec(Node* x){
	        if(!x) return -1; // x==NULL
	        int leftSub=findHeightRec(x->left);
	        int rightSub=findHeightRec(x->right);
	        return std::max(leftSub,rightSub) +1;
	    }
	Node *searchRec(Node *x, int val)
	    {
	        if (!x || x->data == val) // either x==NULL or val at root
	            return x;
	        if (val < x->data)
	            return searchRec(x->left, val);
	        return searchRec(x->right, val);
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
	bool found(int val){
		if(searchRec(root,val) /*!=NULL*/ ) // if val exists it returns true ie is found
		        return true;
		// if(searchIter(val) /*!=NULL*/ ) // if val exists it returns true ie is found
		//         return true;
		return false;
	}

public:
    void insert(int);
    void print();
    int maxHeight(){
            return findHeightRec(root);
        }
};

void BinarySearchTree::insert(int val)
{
    //root = insertionRec(root, val);
    insertIter(val);
}
void BinarySearchTree::print()
{
    //inOrderRec(root);
    inOrderIter();
    cout << endl;
    levelOrderIter();
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
