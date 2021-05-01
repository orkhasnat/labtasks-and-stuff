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
    
    while (head->nxt != NULL) //dont write !head->nxt !!!
        head = head->nxt;
    
    head->nxt = temp;
}

void print_list(Node *head)
{
    if (head->nxt == NULL )
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
    {
        scanf("%d", &key);
        append_node(key, head);
    }
    else if (toupper(a) == 'P')
        print_list(head);
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