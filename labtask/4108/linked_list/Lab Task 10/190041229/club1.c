#include<Stdio.h>
#include<stdlib.h>
#include<string.h>
struct club
{
    char name[100];
    int year;
    int revenue;
    struct club *next;
    struct player *pfirst;
};
struct player
{
    char name[100];
    int age;
    float rating;
    int salary;
    char pos[100];
    struct player *next;
};
int main()
{
    struct club club;
    struct player player;


    printf("Club info:\n");

    printf("Name of club:");
    strcpy(club.name,"Barcelona");
    printf("%s\n",club.name);
    printf("year of formation:");
    club.year=1899;
    printf("%d\n",club.year);
    printf("Total revenue per year:");
    club.revenue=1131313;
    printf("%d\n",club.revenue);
    printf("Player info:\n");
    printf("Player name:");
    strcpy(player.name,"Messi");
    printf("%s\n",player.name);
    printf("Player's age:");
    player.age=33;
    printf("%d\n",player.age);
    printf("Player's salary:");
    player.salary=300000;
    printf("%d\n",player.salary);
    printf("Player's rating: ");
    player.rating=9.1;
    printf("%f\n",player.rating);
    printf("Player's Position:");
    strcpy(player.pos,"forward");
    printf("%s\n",player.pos);


}
