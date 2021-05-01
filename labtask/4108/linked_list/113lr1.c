#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct club
{
    char club_name[100];
    int year;
    double revenue;
    struct club *c;
};

struct player_info
{
    char name[100];
    int age;
    int rating;
    double salary;
    char position[20];
};


int main()
{
    struct club cl;
    struct player_info p;
    struct club *c;
    c = (struct club *)malloc(sizeof(struct club));
    char name[100];
    char position[20];
    printf("Club Information\n");
    printf("Name of club:");
    gets(name);
    printf("Year of Formation:");
    scanf("%d", &c->year);
    getchar();
    printf("Yearly revenue in million Euros:");
    scanf("%lf", &c->revenue);
    getchar();
    printf("Points to:");
    gets(name);
    printf("Player Information \n");
    printf("Player name: ");
    gets(p.name);
    printf("Age of Player:");
    scanf("%d", &p.age);
    getchar();
    printf("Player rating:");
    scanf("%d", &p.rating);
    getchar();
    printf("Yearly salary in million Euros:");
    scanf("%lf", &p.salary);
    printf("Position:");
    gets(position);
    getchar();

    return 0;
}


//what kind of problems can i face if i use char* instead of char[]  ?