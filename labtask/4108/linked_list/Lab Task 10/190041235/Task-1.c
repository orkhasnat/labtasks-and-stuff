#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct playerinfo
{
    char name[31];
    int age;
    int rating;
    double salary;
    char pos[16];
};
struct clubinfo
{
    char name[31];
    int year;
    double revenue;
    struct clubinfo *next;
    struct playerinfo player;
}club;
int main()
{
    printf("Club Information\nName of Club:");
    gets(club.name);
    printf("Year of Formation:");
    scanf("%d", &club.year);
    printf("Yearly Revenue in Million Euros:");
    scanf("%lf", &club.revenue);
    getchar();
    printf("Player Information\nName of Player:");
    gets(club.player.name);
    printf("Age of Player:");
    scanf("%d", &club.player.age);
    printf("Player Rating:");
    scanf("%d", &club.player.rating);
    printf("Yearly Salary in Million Euros:");
    scanf("%lf", &club.player.salary);
    getchar();
    printf("Position:");
    gets(club.player.pos);
    return 0;
}

