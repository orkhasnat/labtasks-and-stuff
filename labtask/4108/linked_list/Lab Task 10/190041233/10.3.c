//CODED BY SHOAIB
#include<stdio.h>
#include<stdlib.h>

struct node
{
   char name[30];
   int yof;
   double yrevenue;
   //int loc;
// struct Player_contract pc;
    struct node *nxt;
}club_info;
struct node *head;
struct node *list;




void create()
{
        int loc;
        int len;
        len=length();
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->nxt=NULL;
        printf("Enter club information:\n");
        printf("Name of club: ");
        fflush(stdin);
        gets(temp->name);
        printf("Year of formation: ");
        scanf("%d",&temp->yof);
        getchar();
        printf("Yearly revenue in millions: ");
        scanf("%lf",&temp->yrevenue);
        printf("Enter position in list: ");
        scanf("%d",&loc);

        if(head==NULL)
        head=temp;
        else
    {
        if(loc>(len+1)) {
            printf("Cannot add club. Enter valid position\n");
        }
        else if(loc==(len+1))
        {
            struct node *p;
            p=head;
            while(p->nxt!=NULL){
                p=p->nxt;
            }
            p->nxt=temp;
        }

        else if(loc==1){
            temp->nxt=head;
            head=temp;
        }
        else{
            struct node *p;
            p=head;
            int i=1;
            while(i<loc){
                p=p->nxt;
                i++;
            }
            temp->nxt=p->nxt;
            p->nxt=temp;
        }
    }

}


void delete_club()

{
    char name[30];
    struct node *temp,*p;
p=(struct node*)malloc(sizeof(struct node));
    printf("Enter name of club to be deleted:");
    getchar();
 //   printf("%s",&name);
    temp=head;

    gets(name);
    if(head->nxt == NULL && strcmp(head->name,name)!=0)
    {
        printf("Club doesn't exist!\n");
    }
    else if(strcmp(temp->name,name)==0&&temp->nxt==NULL)
    {
        temp=head;
        head=temp->nxt;
        temp->nxt=NULL;
        free(temp);
    }
    else
    {

        while(temp->nxt!=NULL)
        {

        if(strcmp(temp,name)==0){
            break;
        }
        p=temp;
            temp=temp->nxt;
        }
        if(temp==head){
            head=temp->nxt;
        }
        else{
        p->nxt=temp->nxt;
        }

       free(temp);
    }
}

view()
{
    struct node *temp;
    temp = head;
    if(temp==NULL)
    {
        printf("List is empty.\n");
    }
    while(temp!=NULL)
    {
        printf("\n\nClub information:\n");
    printf("Name of club: %s\n",temp->name);
    printf("Year of formation: %d\n",temp->yof);
    printf("Yearly revenue in millions: %lf\n",temp->yrevenue);
    printf("\n");
        temp=temp->nxt;
    }
    printf("\n");
}






int length()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->nxt;
    }
    return count;
}


struct node *head=NULL;

int main()
{
    char name;
    int yof;
    double yrevenue;
    struct node club_info;
    int choice,key,loc,rank,x,y;

    while(1)
    {

    printf("La liga Database Initializing...\n");
    printf("What do you want to do?\n1.Create Club\n2.Delete Club\n3.View Club\n");
    printf("Choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
       // printf("H");
        create(name,yof,yrevenue);
    }
    else if(choice==2)
    {
       delete_club();
    }
    else if(choice==3)
    {
        //printf("l");
        view();
    }

    else
    {
        exit(1);
    }
    }
}
