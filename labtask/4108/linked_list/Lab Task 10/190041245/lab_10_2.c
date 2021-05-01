#include <stdio.h>
#include <stdlib.h>

struct club
{
    char nameofclub[30];
    int yearofformation;
    int yearlyrevenue;
    struct club *nextclub;
};

struct player
{
    char nameofplayer[30];
    int ageofplayer;
    int playerrating;
    int yearlysalary;
    char position[15];
};
