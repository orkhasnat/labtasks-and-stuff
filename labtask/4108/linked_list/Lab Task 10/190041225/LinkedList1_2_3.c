#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contract{
char playername[40];
int age;
int rating;
float salary;
char position[20];
};
struct node{
char clubname[40];
int year;
float revenue;
struct node* next;
int position;
};
struct node* head=NULL;
int len()
{
    int count=0;
    struct node* temp;
    temp=head;
   while(temp!=NULL)
   {
       ++count;
       temp=temp->next;
   }
   return count;
}
void create()
{
    fflush(stdin);
    int count=0;
    struct node* club;
    club=(struct node*)malloc(sizeof(struct node));
    club->next=NULL;
    printf("Enter Club name : ");
    gets(club->clubname);
    printf("Enter the Year of its formation : ");
    scanf("%d",&club->year);
    printf("Enter the Revenue of the club : ");
    scanf("%f",&club->revenue);
    printf("Enter the position you want to enter it to : ");
    scanf("%d",&club->position);
    if((club->position==1)&&(head==NULL))
    {
        head=club;
        return;
    }
   else if((club->position==1)&&(head!=NULL))
   {
       club->next=head;
       head=club;
       return;
   }
   struct node* temp;
   temp=head;
   while(count!=(club->position-2))
   {
       temp=temp->next;
       ++count;
       if(temp==NULL)
       {
           printf("Invalid Position\n");
           return;
       }
   }
   club->next=temp->next;
   temp->next=club;
   return;
}
void view()
{
    struct node* temp;
    temp=head;
    do
    {
        if(temp==NULL)
        {
            printf("There is no club to show");
            return;
        }
        printf("Club Name : %s\n",temp->clubname);
        printf("Formation Year : %d\n",temp->year);
        printf("Revenue : %f\n",temp->revenue);
        printf("Position in the list : %d\n",temp->position);
        printf("\n");
        temp=temp->next;
    }
    while(temp!=NULL);
    return;
}
void del()
{
    fflush(stdin);
    int pos,count=0;
    printf("Enter the position : ");
    scanf("%d",&pos);
    struct node* temp1;
    struct node* temp;
    temp=head;
    while(count!=pos-1)
    {
        temp1=temp;
        temp=temp->next;
        if(temp=NULL)
        {
            printf("Invalid postition");
            return;
        }
    }
    temp1=temp->next;
    free(temp);
    return;
}
void clubswap()
{
    fflush(stdin);
    int length=len();
    int pos1,pos2,pos=1;
    struct node *temp1, *temp2, *prev1, *prev2;
    struct node *temp=head;
    printf("Enter the position of the clubs to be swapped : ");
    scanf("%d %d",&pos1,&pos2);
    if(pos1>length||pos2>length)
    {
        printf("Invalid position");
        return;
    }
    else if(pos1==pos2)
    {
        printf("Invalid position");
        return;
    }
    if(pos1>pos2)
    {
        int tempo;
        tempo=pos1;
        pos1=pos2;
        pos2=tempo;
    }
    while((temp!=NULL)&&(pos<=pos2))
    {
        if(pos=pos1-1)
            prev1=temp;
        if(pos=pos1)
            temp1=temp;
        if(pos=pos2-1)
            prev2=temp;
        if(pos=pos2)
            temp2=temp;
        temp=temp->next;
        pos++;
    }
    if((temp1!=NULL)&&(temp2!=NULL))
    {
        if(prev1!=NULL)
            prev1->next=temp2;
        if(prev2!=NULL)
            prev2->next=temp1;
        temp=temp1->next;
        temp1->next=temp2->next;
        temp2->next=temp;
        if(prev1==NULL)
            head=temp2;
    }
    return;
}
int main()
{
    int i;
    while(1)
    {
        printf("\nEnter a choice :\n");
        printf("1. Create club\n");
        printf("2. View clubs\n");
        printf("3. Delete club\n");
        printf("4. Club swap\n");
        printf("0. Exit\n");
        printf("Answer : ");
        scanf("%d",&i);
        if(i==1)
            create();
        else  if(i==2)
            view();
        else if(i==3)
            del();
        else if(i==4)
            clubswap();
        else if(i==0)
            return 0;
    }
}

