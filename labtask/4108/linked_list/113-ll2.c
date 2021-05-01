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

    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->key = key;
    temp->nxt = NULL;

    while (head->nxt != NULL)
        head = head->nxt;

    head->nxt = temp;
}

int length_of_node(Node *head)
{

    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->nxt;
    }

    return i;
}

void add_node_at_front(int key, Node *head)
{

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
        else
        {

            Node *temp = (Node *)malloc(sizeof(Node));
            temp->key = key;

            for (int i = 0; i < pos - 1; i++)
            {
                head = head->nxt;
            }
            temp->nxt = head->nxt;
            head->nxt = temp;
        }
    }
}

void delete_node(Node *head)
{

    int pos;
    scanf("%d", &pos);
    int len = length_of_node(head);
    if (pos > len || len == 1)
    {
        printf("There is no such node.\n");
        return;
    }
    Node *prev;
    for (int i = 0; i < pos - 1; i++)
    {
        head = head->nxt;
    }

    prev = head->nxt;
    head->nxt = prev->nxt;

    free(prev);
}

void print_list(Node *head)
{

    if (head->nxt == NULL)
        printf("the linked list is empty!");
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

    Node *head;

    head = (Node *)malloc(sizeof(Node));
    head->key = HEAD_KEY;
    head->nxt = NULL;
    int n;
    char a;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &a);
        check(a, head);
    }

    free(head);
    return 0;
}

//q: why are we not freeing the temp in insert but freeing prev in delete?
//q: why didnt we use malloc for the prev in delete but used it everywhere?
//     |----I probably understand this . Or do I ?

 