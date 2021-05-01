#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DUMMYNUM 205

struct club
{
    char nameofclub[30];
    int yearofformation;
    int yearlyrevenue;
    struct club *nextclub;
};

struct player
{
    char nameofplayer[30];
    int ageofplayer;
    int playerrating;
    int yearlysalary;
    char position[15];
};

int count=0;

void insertclub(struct club *head, char *nameofclub, int yearofformation, int yearlyrevenue, int pos);
void deleteclub(struct club *head, int pos);
void viewclubinfo(struct club *head);
void swap(struct club *head, int pos1, int pos2);

int main()
{
    int pos,yearofformation,yearlyrevenue,choice,pos1,pos2;
    char nameofclub[30];

    struct club *head;
    head = (struct club*)malloc(sizeof(struct club));
    strcpy(head->nameofclub,"aaa");
    head->yearofformation = DUMMYNUM;
    head->yearlyrevenue = DUMMYNUM;
    head->nextclub = NULL;

    printf("La Liga Database Initializing....\n");
    while(1)
    {
        printf("1. Create Club\n");
        printf("2. Delete Club\n");
        printf("3. View Club info\n");
        printf("4. Swap\n");
        printf("Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter Name: ");
            scanf(" %[^\n]s",&nameofclub);
            printf("Enter Year of Formation: ");
            scanf("%d",&yearofformation);
            printf("Enter Yearly revenue: ");
            scanf("%d",&yearlyrevenue);
            printf("Enter position in list: ");
            scanf("%d",&pos);
            insertclub(head,nameofclub,yearofformation,yearlyrevenue,pos);
            continue;
        }
        else if(choice==2)
        {
            printf("Enter position of club to be deleted: ");
            scanf(" %d",&pos);
            deleteclub(head,pos);
            continue;
        }
        else if(choice==3)
        {
            viewclubinfo(head);
            continue;
        }
        else if(choice==4)
        {
            printf("Which two positions do you want to swap\?\n");
            scanf(" %d %d", &pos1, &pos2);
            swap(head,pos1,pos2);
            continue;
        }
        else
        {
            printf("La Liga Database Terminating....");
            break;
        }
    }
    return 0;
}

void insertclub(struct club *head, char *nameofclub, int yearofformation, int yearlyrevenue, int pos)
{
    int j;
    struct club *temp;

    if(pos>count+1||pos<1)
    {
        printf("Invalid Position!\n............\n");
        return;
    }
    temp = (struct club*)malloc(sizeof(struct club));
    strcpy(temp->nameofclub,nameofclub);
    temp->yearofformation = yearofformation;
    temp->yearlyrevenue = yearlyrevenue;
    temp->nextclub = NULL;

    for(j=0; j<pos; j++)
    {
        if(j+1==pos)break;
        head = head->nextclub;
    }
    temp->nextclub = head->nextclub;
    head->nextclub = temp;
    count++;
    printf("............\n");
}

void deleteclub(struct club *head, int pos)
{
    int j;
    struct club *prev;
    if(pos>count||pos<1)
    {
        printf("Invalid Position!\n............\n");
        return;
    }
    for(j=0; j<pos; j++)
    {
        if(j==pos)break;
        prev = head;
        head = head->nextclub;
    }
    prev->nextclub = head->nextclub;
    free(head);
    count--;
    printf("............\n");
}

void viewclubinfo(struct club *head)
{
    int j;
    if(count==0)
    {
        printf("No clubs to show!\n");
        printf("............\n");
    }
    else
    {
        for(j=0; j<count; j++)
        {
            head=head->nextclub;
            printf("\n%s\n",head->nameofclub);
            printf("%d\n",head->yearofformation);
            printf("%d\n",head->yearlyrevenue);
        }
        printf("............\n");
    }
}

void swap(struct club *head, int pos1, int pos2)
{
    int j;
    if(pos1>count||pos2>count||pos1<1||pos2<1)
    {
        printf("Invalid Position\n............\n");
        return;
    }
    struct club *temp1, *temp2;

    temp1 = (struct club*)malloc(sizeof(struct club));
    temp2 = (struct club*)malloc(sizeof(struct club));
    temp1->nextclub = temp2->nextclub = NULL;

    for(j=0; j<=count; j++)
    {
         head=head->nextclub;
        if(j==pos1-1)
        {
            strcpy(temp1->nameofclub,head->nameofclub);
            temp1->yearofformation = head->yearofformation;
            temp1->yearlyrevenue = head->yearlyrevenue;
            continue;
        }
        if(j==pos2-1)
        {
            strcpy(temp2->nameofclub,head->nameofclub);
            temp2->yearofformation = head->yearofformation;
            temp2->yearlyrevenue = head->yearlyrevenue;
            continue;
        }
    }
    for(j=0; j<=count; j++)
    {
        head=head->nextclub;
        if(j==pos1-1)
        {
            strcpy(head->nameofclub,temp2->nameofclub);
            head->yearofformation = temp2->yearofformation;
            head->yearlyrevenue = temp2->yearlyrevenue;
            continue;
        }
        if(j==pos2-1)
        {
            strcpy(head->nameofclub,temp1->nameofclub);
            head->yearofformation = temp1->yearofformation;
            head->yearlyrevenue = temp1->yearlyrevenue;
            continue;
        }
    }
    free(temp1);
    free(temp2);
    printf("............\n");
}
