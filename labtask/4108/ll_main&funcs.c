#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

typedef char *string;
//--------------------------------------------------------------------
#define HEAD_KEY -963
typedef struct node
{
    int key;
    Node *nxt;
} Node;

//-------------------------------------------------------------------
void append_node(int key, Node *head)
{
    // links at the end of the list
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->key = key;
    temp->nxt = NULL;
    //traversing the list
    while (head->nxt != NULL) //dont write !head->nxt !!!
        head = head->nxt;
    //append the new node
    head->nxt = temp;
}

int length_of_node(Node *head)
{
    //returns the length including the head(considering the head as a node)
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->nxt;
    }
    //for 2 nodes (excluding head) it goes like this,
    //head--1--head->nxt--2--node1->nxt--3--node2->nxt \=null\ i=3
    return i;
}

void add_node_at_front(int key, Node *head)
{
    //add a node at the beginning
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = key;
    temp->nxt = head->nxt;
    head->nxt = temp;
}

void insert_node(Node *head)
{
    int pos, key;
    scanf("%d %d", &pos, &key);
    if (pos == 1)
        add_node_at_front(key, head);
    else
    {
        int len = length_of_node(head);
        if (pos >= len)
            append_node(key, head);
        else // inserting at nth position(excluding head ofc) so pos =3 means head>node1>node2>new_node>node4
        {
            //inserting in the middle or the end (basically anywhere but the beginning.)
            //this logic also can also be applied to insert at the end of the list
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->key = key;

            for (int i = 0; i < pos - 1; i++) //head.nxt>node1>newnode>node2 i=2 pos =3
            {
                head = head->nxt; //traversing
            }
            temp->nxt = head->nxt;
            head->nxt = temp;
        }
    }
}

void delete_node(Node *head)
{
    //deletes nth node
    int pos;
    scanf("%d", &pos);
    int len = length_of_node(head);
    if (pos > len)
    {
        printf("There is no such node.\n");
        return;
    }
    Node *prev;
    for (int i = 0; i < pos - 1; i++)
    {
        head = head->nxt;
    }
    //now the head points to n-1 th node.
    prev = head->nxt;      //prev points to the nth node which is to be deleted.
    head->nxt = prev->nxt; //head->nxt pointing to n+1 th node.
    // head=>n-1,prev=>n,head->nxt=>n+1.
    free(prev);
}

void print_list(Node *head)
{
    //prints out the list
    if (head->nxt == NULL)
        printf("the linked list is empty!\n");
    int i = 0;
    while (head != NULL)
    {
        if (i != 0)
            printf("%d ", head->key);
        head = head->nxt;
        i++;
    }
    printf("\n");
}

void check(char a, Node *head)
{
    int key;
    if (toupper(a) == 'I')
        insert_node(head);
    else if (toupper(a) == 'P')
        print_list(head);
    else if (toupper(a) == 'D')
        delete_node(head);
    else
        printf("Error!");
}

//----------------------------------------------

int main()
{
    //creating the head
    Node *head; //head is already NULL;

    head = (Node *)malloc(sizeof(Node));
    head->key = HEAD_KEY;
    head->nxt = NULL;
    int n;
    char a;
    scanf("%d", &n);
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &a);
            check(a, head);
            //printf("%d",length_of_node(head));
        }
    }
    free(head);
    return 0;
}

//q: why are we not freeing the temp in insert but freeing prev in delete?