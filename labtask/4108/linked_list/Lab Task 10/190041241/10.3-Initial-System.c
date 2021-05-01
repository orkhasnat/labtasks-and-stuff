#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HEAD_KEY -333;

struct club
{
    char club_name[31];
    int year;
    double revenue;
    struct club *next;
};

int total_club=0;

void menu();
void create_club(struct club *head, char club_name[31], int year, double revenue, int serial);
void delete_club(struct club *head, char club_name[31]);
void view_club(struct club *head);

int main()
{
    struct club *head=malloc(sizeof(*head)); //traverse through clubs
    head->year=HEAD_KEY;
    head->next=NULL;

    int choice;
    char club_name[31];
    int year;
    double revenue;
    int serial;

    printf("La Liga Database Initializing....\n");
    while(1)
    {
        menu();
        scanf("%d", &choice);
        getchar();

        if(choice==1)
        {
            printf("Enter Name: ");
            gets(club_name);
            printf("Enter Year of Formation: ");
            scanf("%d", &year);
            printf("Enter Yearly revenue: ");
            scanf("%lf", &revenue);
            printf("Enter position in list: ");
            scanf("%d", &serial);

            if(serial<1 || serial>total_club+1)
                printf("Invalid position\n");
            else
                create_club(head, club_name, year, revenue, serial);

            printf("............\n");
        }

        else if(choice==2)
        {
            printf("Enter Club Name to delete: ");
            gets(club_name);
            delete_club(head, club_name);
            printf("............\n");
        }

        else if(choice==3)
        {
            view_club(head);
            printf("............\n");
        }

        else
        {
            printf("La Liga Database Terminating....\n");
            break;
        }
    }
    return 0;
}


void menu()
{

    printf("What to you want to do?\n");
    printf("1. Create Club\n");
    printf("2. Delete Club\n");
    printf("3. View Club info\n");
    printf("Choice: ");
}


void create_club(struct club *head, char club_name[31], int year, double revenue, int serial)
{
    struct club *new_club=malloc(sizeof(*new_club));
    strcpy(new_club->club_name, club_name);
    new_club->year=year;
    new_club->revenue=revenue;

    while(serial!=0)
    {
        serial--;
        if(serial==0)
        {
            new_club->next=head->next;
            head->next=new_club;
            total_club++;
            return;
        }
        head=head->next;
    }
}


void delete_club(struct club *head, char club_name[31])
{
    struct club *temp;

    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
        if(strcmp(head->club_name, club_name)==0)
        {
            temp->next=head->next;
            free(head);
            total_club--;
            return;
        }
    }

    printf("There is no such club.\n");
}


void view_club(struct club *head)
{
    if(head->next==NULL)
        printf("No clubs to show!\n");
    else
    {
        printf("Showing Club list: \n");
        while(head->next!=NULL)
        {
            head=head->next;
            printf("%s\n%d\n%.0lf\n", head->club_name, head->year, head->revenue);
        }
    }
}
