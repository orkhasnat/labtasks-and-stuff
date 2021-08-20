#include "AVLtree.cpp"
using std::cin,std::cout,std::endl;
#define debug printf("debug\n")

// Node *LowestCommonAncestor(int p, int q)
//     { //iterative implementation
//         Node *tmp = root;
//         while (tmp)
//         {
//             if (tmp->data > p && tmp->data > q)
//                 tmp = tmp->left;
//             else if (tmp->data < p && tmp->data < q)
//                 tmp = root->right;
//             else
//                 break;
//         }
//         return tmp;
//     }

int main(){
    AVLtree tree;
    int input,n1,n2;
    while (cin>>input and input!=-1)
        tree.push(input);
    cout<<"Status: ";
    tree.print();
    cin>>input;
    while(input--){
        cin>>n1>>n2;
        tree.LCA(n1,n2);
    }
}
