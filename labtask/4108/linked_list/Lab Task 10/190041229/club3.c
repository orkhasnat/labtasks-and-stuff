#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct club
{
    char club[100];
    int year;
    int revenue;
    struct club *next;
}*head;
int pos=0,x=0;
struct club *p,*prev,*py,*px,*prevx,*prevy,*tempu;
int main()
{


    int n,position,pos1,pos2;
    char club[100];
    int year;
    int revenue;


    while(1)
    {
        printf("what do you want to do?\n1.create club\n2.view club\n3.delete club\n4.swap club\n");
        scanf("%d",&n);
        if(n==1)
        {

            getchar();
            printf("Enter the name of club:\n");
            gets(club);
            printf("year of formation:\n");
            scanf("%d",&year);
            printf("Enter yearly revenue:\n");
            scanf("%d",&revenue);
            printf("enter the positon you want to enter");
            scanf("%d",&pos);
            if(pos==1)
            {

                createfirstclub(club,year,revenue,pos);
            }
            else if(pos!=1)
            {
                createotherclub(club,year,revenue,pos);
            }

        }

        else if(n==2)
        {
            veiw();
        }
        else if(n==3)
        {
            printf("enter the position you want to delete: ");
            scanf("%d",&position);
            delete(head,position);
        }
        else if(n==4)
        {
            printf("enter the positions you want to swap: ");
            scanf("%d%d",&pos1,&pos2);
            swap(pos1,pos2,head);
        }

    }
}
void createfirstclub(char club[100], int year,int revenue)
{


    if(x==0)
    {
        head=(struct club*)malloc(sizeof(struct club));

        strcpy(head->club,club);
        head->year=year;
        head->revenue=revenue;
        head->next=NULL;
        x++;
    }
    else if(x!=0)
    {
        struct club *temp;
        temp=(struct club*)malloc(sizeof(struct club));
        strcpy(temp->club,head->club);
        temp->year=head->year;
        temp->revenue=head->revenue;
        temp->next=head->next;
        strcpy(head->club,club);
        head->year=year;
        head->revenue=revenue;
        head->next=temp;


    }

}
void createotherclub(char club[100], int year,int revenue)
{
    int j;
    struct club *newnode,*temp;
    temp=head;
    newnode=(struct club*)malloc(sizeof(struct club));
    strcpy(newnode->club,club);
    newnode->year=year;
    newnode->revenue=revenue;
    newnode->next=NULL;
    for(j=2; j<=pos-1; j++)
    {
        temp = temp->next;
        if(temp == NULL)
            break;
    }
    if(temp!=NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }

}
void veiw()
{
    struct club *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->club);
        printf("%d\n",temp->year);
        printf("%d\n",temp->revenue);
        temp=temp->next;
    }
}
void delete(struct club *p,int position)
{
    struct club *prev;
    prev=NULL;
    if(position==1 && !head)
    {
        printf("There is no such node.\n");
    }
    else if(position==1 && head)
    {
        head=head->next;
        free(p);
    }
    else
    {
        int i;
        for(i=1; i<position && p ; i++)
        {
            prev=p;
            p=p->next;
        }
        if(p)
        {
            prev->next=p->next;
            free(p);
        }
        else
        {
            printf("There is no such node.\n");
        }
    }
}
int total(struct club *head)
{
    struct club *list;
    list=head;
    int nodes = 0;

    while (list != NULL)
    {
        nodes++;
        list = list->next;
    }

    return nodes;
}



int swap(int pos1, int pos2,struct node *list)
{
    struct club *node1, *node2, *prev1, *prev2, *temp;
    int i;


    const int maxPos = (pos1 > pos2) ? pos1 : pos2;


    const int totalNodes = total(head);
    i = 1;
    temp  = list;
    prev1 = NULL;
    prev2 = NULL;


    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }


    if (node1 != NULL && node2 != NULL)
    {

        if (prev1 != NULL)
            prev1->next = node2;


        if (prev2 != NULL)
            prev2->next = node1;

        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;


        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

    return 1;
}




