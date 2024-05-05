#include <iostream>
using namespace std;

class List{
    struct Node{
    int data;
    Node *nxt;
};
    Node *head;
public:
    List()
    {
        head = NULL;
    }
    void insertFront(int key);
    void insertBack(int key);
    void insert_atNode(int key, int prevKey);
    void updateNode(int newVal, int old);
    void removeFront();
    void removeNode(int key);
    void removeEnd();
    void display();
};

void List::insertFront(int key){
    Node *newNode = new Node();
    newNode->data = key;
    if (head) // if head has something then insert new node
        newNode->nxt = head;
    head = newNode; 
}

void List::insertBack(int key){
    if(!head)
        return insertFront(key); // for empty list
    Node *newNode = new Node();
    newNode->data = key;
    Node *tmp=head;
    while(tmp->nxt)
        tmp=tmp->nxt;
    tmp->nxt=newNode;
}

void List::insert_atNode(int key, int prevKey){
    if(!head) return; // for empty list
    Node *newNode = new Node();
    newNode->data = key;
    Node *tmp=head;
    while (tmp->data!=prevKey){
        tmp=tmp->nxt;
        if(tmp==NULL){
            cout<<"Your given item doesnt exist!!\n";
            return;
        }
    }
    newNode->nxt=tmp->nxt;
    tmp->nxt=newNode;
}

void List::updateNode(int newVal,int old){ // if theres duplicate keys it finds the first one and returns
    if(!head) return; // for empty list
    Node *tmp=head;
    while (tmp->data!=old){
        tmp=tmp->nxt;
        if(tmp==NULL){
            cout<<"Your given item doesnt exist!!\n";
            return;
        }
    }
    tmp->data=newVal;
}

void List::removeFront(){
    if(!head) return; // for empty list
    Node *tmp=head;
    head=head->nxt;
    delete tmp;
}   

void List::removeNode(int key){
    if(!head) return; // for empty list
    Node *tmp=head,*prev;
    if(tmp->data==key) // ie first node needs to be deleted.
        return removeFront(); // if not handled, procudes garbage
    while (tmp->data!=key){
        prev=tmp;
        tmp=tmp->nxt;
        if(tmp->nxt==NULL){
            cout<<"Your given item doesnt exist!!\n";
            return;
        }
    } // if found then next steps
    prev->nxt=tmp->nxt; 
    delete tmp;
}

void List::removeEnd(){
    if(!head) return; // for empty list
    Node *tmp=head;
    if(!tmp->nxt){ //ie head is the last node left
        head=NULL;
        delete tmp;
        return;
    }
    while(tmp->nxt->nxt) // until tmp=last-1 th pos
        tmp=tmp->nxt;
    Node *t2=tmp->nxt;
    tmp->nxt=NULL;
    delete t2;
}

void List::display(){
    if (head != NULL){  // or if(!head) ;same thing   
        Node *tmp = head;
        cout<<"Items:\t";
        while (tmp) //untill temp is null
        {
            cout << tmp->data << " ";
            tmp = tmp->nxt;
        }
    }
    else
        cout << "Empty List";
    cout << endl;
}

void exec(List *list, int ch){
    int item,oldval;
    switch (ch){
    case 1:
        cout << "Give key:\t";
        cin >> item;
        list->insertFront(item);
        break;
    case 2:
        cout << "Give key:\t";
        cin >> item;
        list->insertBack(item);
        break;
    case 3:
        cout << "Give node:\t";
        cin >> oldval;
        cout << "Give newVal:\t";
        cin >> item;
        list->insert_atNode(item, oldval);
        break;
    case 4:
        cout << "Give old Value:\t";
        cin >> oldval;
        cout << "Give new value:\t";
        cin >> item;
        list->updateNode(item, oldval);
        break;
    case 5:
        cout << "Give key to remove:\t";
        cin >> item;
        list->removeNode(item);
        break;
    case 6:
        list->removeEnd();
        break;
    default:
        break;
    }
    list->display();
}

int main()
{
    int ch;
    List *list = new List();
    while (1)
    {
        cout << "Press 1 to inser at front\n"
             << "Press 2 to insert at back\n"
             << "Press 3 to insert after a node\n"
             << "Press 4 to update a node\n"
             << "Press 5 to remove a node\n"
             << "Press 6 to remove the last node\n"
             << "Press 7 to exit\n";
        scanf("%d", &ch);
        if (ch == 7)
            break;
        exec(list, ch);
    }
    delete list;
}
