#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=================================================================

void cgpa_counter(char *std)
{
    FILE *fpm, *fpc;
    if (((fpm = fopen("marks.txt", "r")) == NULL) && ((fpc = fopen("course.txt", "r")) == NULL))
    {
        printf("cant open marks.txt or cant open course.txt");
        exit(1);
    }
    struct course
    {
        float credit;
        char cname[9];
        char cfname[30];
    };
    struct student
    {
        struct course course;
        int marks;
    };
    struct course Course[3];
    struct student STD;
    int i = 0;
    while (!feof(fpc))
    {
        fgets(Course[i].cfname, 30, fpc);
        fgets(Course[i].cname, 9, fpc);
        fgets(Course[i].cname, 9, fpc);
        fscanf(fpc, "%f", &Course[i].credit);
        printf("%s %s %f\n", Course[i].cfname, Course[i].cname, Course[i].credit);
        i++;
    }
    int j = i;
    //printf("%d %d\n", i, j);
    char id[10], course[9];
    while (!feof(fpm))
    {
        fgets(id, 10, fpm);
        if (strcmp(std, id) == 0)
        {
            fgets(course, 9, fpm);
            fgets(course, 9, fpm);
            while (i--)
            {
                if (strcmp(Course[i].cname, course) == 0)
                {
                    fscanf(fpm, "%f", STD.marks);
                    strcpy(STD.course.cname, course);
                    strcpy(STD.course.cfname, Course[i].cfname);
                    STD.course.credit = Course[i].credit;
                    //=============
                    puts(STD.course.cname);
                    puts(STD.course.cfname);
                    printf("%f\n", STD.course.credit);
                    printf("%f\n", STD.marks);
                }
            }
        }
    }
    fclose(fpc);
    fclose(fpm);
    return;
}

float gpa_grade(int marks, float credit)
{
    //int total_marks= credit*100;
    int percentage = marks / credit; //total_marks*100;
    float gpa;
    if (percentage < 40)
        gpa = 0.0;
    else if (percentage >= 40 && percentage < 50)
        gpa = 2.00;
    else if (percentage >= 50 && percentage < 60)
        gpa = 2.50;
    else if (percentage >= 60 && percentage < 70)
        gpa = 3.00;
    else if (percentage >= 70 && percentage < 80)
        gpa = 3.50;
    else if (percentage >= 80)
        gpa = 4.0;

    return gpa;
}

char grade(float gpa)
{
    if (gpa == 0.0)
        return 'F';
    else if (gpa == 2.00)
        return 'E';
    else if (gpa == 2.50)
        return 'D';
    else if (gpa == 3.00)
        return 'C';
    else if (gpa == 3.50)
        return 'B';
    else if (gpa == 4.00)
        return 'A';
}

int main()
{

    char a;
    printf("Student Database System Initializing...\n");
    while (1)
    {
        char std[10];
        printf("Enter Your Student ID:");
        scanf("%s", std);
        puts(std);
        cgpa_counter(std);

        break;
    }
    return 0;
}