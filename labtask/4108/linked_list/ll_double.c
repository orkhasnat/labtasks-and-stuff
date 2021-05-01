#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char *string;
//========================================================================
#define HEAD_KEY -963
struct Node
{
    int key;
    struct Node *prev;
    struct Node *next;
};
//========================================================================
void bInsert(struct Node *current, int pos, int key)
{
    int i;
    for (i = 0; i < pos - 1; i++)
    {
        if (current->next == NULL)
        {
            printf("There is no such node.\n");
            return;
        }
        current = current->next;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = key;
    if (current->next == NULL)
        temp->next = NULL;
    else
    {
        current->next->prev = temp;
        temp->next = current->next;
    }
    current->next = temp;
    temp->prev = current;
}

void eInsert(struct Node *current, int pos, int key)
{
    int i;
    while (current->next != NULL)
        current = current->next;
    for (i = 0; i < pos - 1; i++)
    {
        if (current->prev == NULL)
        {
            printf("There is no such node.\n");
            return;
        }
        current = current->prev;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = key;
    if (current->next == NULL)
        temp->next = NULL;
    else
    {
        current->next->prev = temp;
        temp->next = current->next;
    }
    current->next = temp;
    temp->prev = current;
}

void bDelete(struct Node *current, int pos)
{
    int i;
    for (i = 0; i < pos; i++)
    {
        if (current->next == NULL)
        {
            printf("There is no such node.\n");
            return;
        }
        current = current->next;
    }
    if (current->next == NULL)
    {
        current->prev->next = NULL;
        free(current);
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void eDelete(struct Node *current, int pos)
{
    int i;
    while (current->next != NULL)
        current = current->next;
    for (i = 0; i < pos - 1; i++)
    {
        if (current->key == HEAD_KEY)
        {
            printf("There is no such node.\n");
            return;
        }
        current = current->prev;
    }
    if (current->next == NULL)
    {
        current->prev->next = NULL;
        free(current);
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void rPrint(struct Node *current)
{
    if (current == NULL)
        return;
    rPrint(current->next);
    printf("%d ", current->key);
}

void print(struct Node *current)
{
    if (current == NULL)
        return;
    printf("%d ", current->key);
    print(current->next);
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->key = HEAD_KEY;
    head->next = NULL;
    head->prev = NULL;

    int tc, pos, key, a;
    char choice;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf(" %c", &choice);
        if (toupper(choice) == 'I')
        {
            scanf("%d %d", &pos, &key);
            bInsert(head, pos, key);
        }
        else if (toupper(choice) == 'B')
        {
            scanf("%d %d", &pos, &key);
            eInsert(head, pos, key);
        }
        else if (toupper(choice) == 'D')
        {
            scanf("%d", &pos);
            if (head->next == NULL || pos < 1)
            {
                printf("There is no such node.\n");
                continue;
            }
            bDelete(head, pos);
        }
        else if (toupper(choice) == 'F')
        {
            scanf("%d", &pos);
            if (head->next == NULL || pos < 1)
            {
                printf("There is no such node.\n");
                continue;
            }
            eDelete(head, pos);
        }
        else if (toupper(choice) == 'R')
        {
            if (head->next == NULL)
            {
                printf("The linked list is empty.\n");
                continue;
            }
            rPrint(head->next);
            printf("\n");
        }
        else if (toupper(choice) == 'P')
        {
            if (head->next == NULL)
            {
                printf("The linked list is empty.\n");
                continue;
            }
            print(head->next);
            printf("\n");
        }
        else
        {
            printf("Error!");
        }
    }
    return 0;
}