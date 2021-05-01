struct club
{
    char club_name[31];
    int year;
    double revenue;
    struct club *next;
};

struct player
{
    char player_name[31];
    int age;
    int rating;
    double salary;
    char position[15];
};


