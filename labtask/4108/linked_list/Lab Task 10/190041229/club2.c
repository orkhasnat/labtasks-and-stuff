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
int pos=0,x=0,show=0;
int main()
{


    int n,position;
    char club[100];
    int year;
    int revenue;


    while(1)
    {
        printf("what do you want to do?\n1.create club\n2.view club\n3.delete club\n");
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
            show++;
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
    if(show==0)
    {
        printf("no club to show\n");
    }
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
        for(i=1;i<position && p ;i++)
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
