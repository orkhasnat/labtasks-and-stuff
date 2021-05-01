#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HEAD_KEY -963
int s, t=1;
struct club
{
    char name[100];
    int year;
    double revenue;
    int posi;
    struct club *next;
};
void create_club(struct club *head, char name[100], int year, double revenue, int pos)
{
    struct club *temp;
    temp=(struct club*)malloc(sizeof(struct club));
    strcpy(temp->name,name);
    temp->year=year;
    temp->revenue=revenue;
    temp->next=NULL;
    for(s=0; s<t; s++)
    {
        if(s==pos-1)
        {
            t++;
            temp->next=head->next;
            head->next=temp;
            return;
        }
        head=head->next;
    }
    printf("There is no such position.\n");
}
void view(struct club *head)
{
    if(head->next==NULL)
    {
        printf("No clubs to show!\n");
        return;
    }
    else
    {
        printf("Showing Club List:\n");
        while(head->next!= NULL)
        {
            head=head->next;
            printf("%s\n",head->name);
            printf("%d\n",head->year);
            printf("%lf\n",head->revenue);
        }
    }
}
void delete_club(struct club *head, char name[100])
{
    struct club *prev;
    while(head->next!=NULL)
    {
        if(strcmp(head->name,name)==0)
        break;
        prev=head;
        head=head->next;
    }
    if(head->next==NULL && strcmp(head->name,name)!=0)
    {
        printf("There is no such club.\n");
        return;
    }
    prev->next=head->next;
    free(head);
}
int main()
{   int year;
    double revenue;
    int posi, choice;
    struct club *head;
    head=(struct club*)malloc(sizeof(struct club));
    head->year=HEAD_KEY;
    head->revenue=year;
    head->next=NULL;
    char name[100];
    printf("La Liga Database Initializing....\n");
    while(1)
    {
        printf("What do you want to do?\n");
        printf("1. Create Club\n");
        printf("2. Delete Club\n");
        printf("3. View Club info\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if(choice==1)
        {
            getchar();
            printf("Enter Name: ");
            gets(name);
            printf("Enter Year of Formation: ");
            scanf("%d",&year);
            printf("Enter Yearly revenue: ");
            scanf("%lf",&revenue);
            printf("Enter position in list: ");
            scanf("%d",&posi);
            create_club(head, name, year, revenue, posi);
        }
        else if(choice==2)
        {
            getchar();
            printf("Enter Name of The club to remove : ");
            gets(name);
            delete_club(head,name);
        }
        else if(choice==3)
        {
            view(head);
        }
        else
        {
            printf("La Liga Database Terminating....\n");
            break;
        }
        printf("............\n");
    }
    return 0;
}

//why does viewing not working for year and revenue??
//huh, it works now although i changed absolutely nothing.