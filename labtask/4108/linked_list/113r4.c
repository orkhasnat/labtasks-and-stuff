#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HEAD_KEY -963
int s, t=1;
struct club
{
    char name[100];
    int year;
    float revenue;
    int posi;
    struct club *next;
};
void create_club(struct club *head, char name[100], int year, float revenue, int posi)
{
    struct club *temp;
    temp=(struct club*)malloc(sizeof(struct club));
    strcpy(temp->name,name);
    temp->year=year;
    temp->revenue=revenue;
    temp->next=NULL;
    for(s=0; s<t; s++)
    {
        if(s==posi-1)
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
            printf("%f\n",head->revenue);
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
void club_swap(struct club *head,int pos1,int pos2)
{
    int temp, cnt1=0, cnt2=0;
    struct club *club1=head;
    struct club *prev1=NULL;
    struct club *club2=head;
    struct club *prev2=NULL;
    if(head==NULL || head->next==NULL)
    {
        printf("Not enough clubs to swap\n");
        return head;
    }
    else if(pos1==pos2)
    {
        printf("Swapping is not necessary\n");
        return head;
    }
    else
    {
        if(pos1>pos2)
        {
            temp=pos1;
            pos1=pos2;
            pos2=temp;
        }
        while(club1!=NULL && cnt1<pos1)
        {
            prev1=club1;
            club1=club1->next;
            cnt1++;
        }
        if(club1==NULL)
        {
            printf("First position is invalid\n");
            return head;
        }
        while(club2!=NULL && cnt2<pos2)
        {
            prev2 = club2;
            club2 = club2->next;
            cnt2++;
        }
        if(club2 == NULL)
        {
            printf("Second position is invalid\n");
            return head;
        }
        if(prev1==NULL)
        {
            if(club1->next==club2)
            {
                club1->next = club2->next;
                club2->next = club1;
                head=club2;
                return head;
            }
            else
            {
                struct Club *next1 = club1->next;
                club1->next = club2->next;
                prev2->next = club1;
                club2->next =  next1;
                head  = club2;
                return head;
             }
        }
        else
        {
            if(club1->next==club2)
            {
                club1->next=club2->next;
                club2->next=club1;
                prev1->next=club2;
                return head;
            }
            else
            {
                struct Club *next1=club1->next;
                club1->next=club2->next;
                prev2->next=club1;
                club2->next=next1;
                prev1->next=club2;
                return head;
            }
        }
    }
}
int main()
{   int year;
    float revenue;
    int posi,pos1,pos2,choice;
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
        printf("4. Swap Clubs\n");
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
            scanf("%f",&revenue);
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
        else if(choice==4)
        {
            struct player *temp=head->next;
            printf("Which two positions do you want to swap?\n");
            scanf("%d %d", &pos1, &pos2);
             club_swap(head, pos1, pos2);
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

