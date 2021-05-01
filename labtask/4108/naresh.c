#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

typedef char *string;
//--------------------------------------------------------------------
typedef struct node
{
    struct node *prev;
    int key;
    struct node *next;
} Node;
Node *head;
void create()
{
    system("cls");
    Node *temp, *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    printf("\n\tEnter data in form of integer\t");
    scanf("%d", &new_node->key);
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        head->prev = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return 0;
}
void display()
{
    system("cls");
    Node *temp;
    int choice2;
    printf("\n\t1.From first");
    printf("\n\t2.From last\t");
    scanf("%d", &choice2);

    if (choice2 == 1)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ==> ", temp->key);
            temp = temp->next;
        }
    }
    else if (choice2 == 2)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            printf(" ==> %d", temp->key);
            temp = temp->prev;
        }
    }
    return 0;
}
void insert_at_any_position()
{
    system("cls");
    Node *temp, *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    int pos, i = 1;
    printf("Insert position number\t");
    scanf("%d", &pos);
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
    }
    ptr->prev = temp;
    temp->next->prev = ptr;
    ptr->next = temp->next;
    temp->next = ptr;

    printf("\n\tEnter key\t");
    scanf("%d", &ptr->key);
    return 1;
}

void print_reverse()
{
    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        printf(" %d ==> ", temp->key);
        temp = temp->prev;
    }
    printf(" %d", temp->key);
}

void reverse_list()
{
    system("cls");
    Node *temp, *p;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        p = temp->next;
        temp->next = temp->prev;
        temp->prev = p;
    }
    head = temp;
}

//------------------------------------------------------------------------
int main()
{
    int choice;
    do
    {
        printf("\n\t1.Create Double List");
        printf("\n\t2.Display lists");
        printf("\n\t3.Insert at any position");
        printf("\n\t4.Print reverse");
        printf("\n\t5.Reverse List");
        printf("\n\t6.Exit\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_at_any_position();
            break;
        case 6:
            exit(0);
            break;
        case 4:
            print_reverse();
            break;
        case 5:
            reverse_list();
            break;
        default:
            printf("\n\t\twrong choice.......");
        }

    } while (choice != 3);
    return 0;
}
