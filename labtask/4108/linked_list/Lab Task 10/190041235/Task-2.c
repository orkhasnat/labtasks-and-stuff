#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct club
{
    char name[31];
    int year;
    double rev;
    struct club *nxt;
};

struct club *head=NULL;

void insert_club()
{
    char name[31];
    int year, pos;
    double rev;
    printf("Enter Name:");
    getchar();
    gets(name);
    printf("Enter Year of Formation:");
    scanf("%d", &year);
    printf("Enter Yearly Revenue:");
    scanf("%lf", &rev);
    printf("Enter Position in List:");
    scanf("%d", &pos);
    int cur_pos=1;
    int flag=0;
    while(head!=NULL)
    {
        if(cur_pos==pos-1)
        {
            flag=1;
            break;
        }
        cur_pos++;
        head=head->nxt;
    }
    if(flag && pos!=1)
    {
        struct club *temp;
        temp=(struct club*)malloc(sizeof(struct club));
        strcpy(temp->name, name);
        temp->year=year;
        temp->rev=rev;
        temp->nxt=NULL;
        temp->nxt=head->nxt;
        head->nxt=temp;
    }
    else
    {
        if(head==NULL && pos==1)
        {
            struct club *temp;
            temp=(struct club*)malloc(sizeof(struct club));
            strcpy(temp->name, name);
            temp->year=year;
            temp->rev=rev;
            temp->nxt=NULL;
            head=temp;
        }
        else if(pos==1)
        {
            struct club *temp;
            temp=(struct club*)malloc(sizeof(struct club));
            strcpy(temp->name, name);
            temp->year=year;
            temp->rev=rev;
            temp->nxt=NULL;
            temp->nxt=head;
            head=temp;
        }
        else
        {
            printf("No Clubs to Show!\n");
            return;
        }
    }
}

void delete_club()
{
    char name[31];
    printf("Enter Club to be Deleted:");
    getchar();
    gets(name);
    struct club *prev;
    while(head->nxt!=NULL)
    {
        if(strcmp(head->name, name)!=0)
            break;
        prev=head;
        head=head->nxt;
    }
    if(head->nxt==NULL && strcmp(head->name, name)!=0)
    {
        printf("No Clubs to Show!\n");
        return;
    }
    prev->nxt=head->nxt;
    free(head);
}

void print()
{
    if(head==NULL)
    {
        printf("No Clubs to Show!\n");
        return;
    }
    else
    {
        printf("Showing Club List:\n");
        while(head!=NULL)
        {
            printf("%s\n", head->name);
            printf("%d\n", head->year);
            printf("%lf\n", head->rev);
            head=head->nxt;
        }
    }
}

int main()
{
    int c;
    printf("La Liga Database Initializing....\n");
    while(1)
    {
        printf("What do you want to do?\n1. Create Club\n2. Delete Club\n3. View Club Info\n");
        printf("Choice:");
        scanf("%d", &c);

        if(c==1)
            insert_club();
        else if(c==2)
            delete_club();
        else if(c==3)
            print();
        else
        {
            printf("La Liga Database Terminating....\n");
            return 0;
        }
        printf("....................\n");
    }
}

