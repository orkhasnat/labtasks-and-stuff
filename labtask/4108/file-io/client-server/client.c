#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//=================================================================
struct course
{
    float credit;
    char cname[9];
    char cfname[30];
};
struct course Course[10];
int i = 0;

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

float cgpa(int marks[], float credits[], int sub)
{
    float sum = 0;
    for (int k = 0; k < sub; k++)
    {
        float gpas = gpa_grade(marks[k], credits[k]);
        float sum = sum + gpas;
    }
    return sum / sub;
}

void cgpa_counter(char *std)
{
    FILE *fpm, *fpc;
    if (((fpm = fopen("marks.txt", "r")) == NULL) || ((fpc = fopen("course.txt", "r")) == NULL))
    {
        printf("cant open marks.txt or cant open course.txt");
        exit(1);
    }
    // if ((fpc = fopen("course.txt", "r")) == NULL)
    // {
    //     printf("cant open marks.txt or cant open course.txt");
    //     exit(1);
    // }

    while (!feof(fpc))
    {
        fgets(Course[i].cfname, 30, fpc);
        //fgets(Course[i].cname, 10, fpc);
        fgets(Course[i].cname, 10, fpc);
        fscanf(fpc, "%f", &Course[i].credit);
        printf("%s%s\n%f", Course[i].cfname, Course[i].cname, Course[i].credit);
        i++;
    }
    fclose(fpc);
    char id[10], course[10];
    int marks[i];
    float credits[i];
    while (!feof(fpm))
    {
        fgets(id, 10, fpm);
        if (strcmp(std, id) == 0)
        {
            //fgets(course, 9, fpm); //??
            fgets(course, 10, fpm);

            for (int j = 0; j < i; j++)
            {
                if (strcmp(Course[j].cname, course) == 0)
                {
                    fscanf(fpm, "%f", marks[j]);
                    credits[j] = Course[j].credit;
                }
            }
        }
    }

    float result = cgpa(marks, credits, i);
    printf("CGPA: %f\n", result);
    fclose(fpm);
    return;
}

void do_1(char *std)
{
    FILE *fpm;
    char id[10], course[10];
    if ((fpm = fopen("marks.txt", "r")) == NULL)
    {
        printf("cant open marks.txt or cant open course.txt");
        exit(1);
    }

    while (!feof(fpm))
    {
        fgets(id, 10, fpm);
        if (strcmp(std, id) == 0)
        {
            //fgets(course, 9, fpm); //??
            fgets(course, 10, fpm);

            for (int j = 0; j < i; j++)
            {
                int mark;
                float gpa;
                if (strcmp(Course[j].cname, course) == 0)
                {
                    printf("Course ID: %s\n", course);
                    printf("Course: %s\n", Course[j].cfname);
                    printf("Course Credit: %s\n", Course[j].credit);
                    fscanf(fpm, "%d", &mark);
                    printf("Obtained Marks: %d\n", mark);
                    gpa = gpa_grade(mark, Course[j].credit);
                    printf("Obtained Grade Point: %f\n", gpa);
                    printf("Obtained Grade: %c\n", grade(gpa));
                }
            }
        }
    }

    fclose(fpm);
    return;
}

int display_student(char *std)
{
    FILE *fps, *fpc, *fpm;
    int i = 0;
    if ((fps = fopen("students.txt", "r")) == NULL)
    {
        printf("cant open students.txt");
        exit(1);
    }
    char id[10], name[30], add[30];
    // while (!feof(fps))
    // {
    //     fgets(id, 10, fps);
    //     if (strcmp(std, id) == 0)
    //     {
    //         printf("Displaying Student Information\n");
    //         printf("Name: %sAddress: %sID: %s\n",fgets(name,30,fps),fgets(add,30,fps),id);
    //     }
    // } //why name is printing correctly whreas address is not but the oppsite was suppossed to happen
    while (!feof(fps))
    {
        fgets(id, 10, fps);
        if (strcmp(std, id) == 0)
        {
            printf("Displaying Student Information\n");
            fgets(name, 30, fps); // alternative for fgets ??
            fgets(name, 30, fps);
            fgets(add, 30, fps);
            printf("Name: %sAddress: %sID: %s\n", name, add, id);
            i++;
        }
    }
    fclose(fps);
    if (i == 0)
        return -5;
    return 0;
}

void display_st2(char *std)
{
    char a[3] = {std[0], std[1], '\0'};
    char y[5] = "20";
    printf("Year of Admission: %s\n", strcat(y, a));
    //----------------------------
    if (std[5] == '1')
        printf("Program: Bachelor of Science\n");
    else
        printf("Program: Higher Diploma\n");
    if (std[4] == '4')
        printf("Department: CSE");
    else if (std[4] == '1')
        printf("Department: MCE");
    else if (std[4] == '2')
        printf("Department: EEE");
    else if (std[4] == '3')
        printf("Department: TVE");
    //----------------------------
    printf("\nSection : %c\n", std[6]);
    return;
}

//======================================================


int main()
{
    char a;
    printf("Student Database System Initializing...\n");
    while (1)
    {
        char std[10];
        printf("Enter Your Student ID:");
        scanf("%s", std);
        // if (strcmp("0", std) == 0)
        //     break;
        // int check = display_student(std);
        // if (check == -5)
        // {
        //     printf("Student ID not found. Wrong ID!\n");
        //     continue;
        // }
        //display_st2(std);

        cgpa_counter(std);
        printf("Do you want to see your result in details?\n1.  Yes\n2.  No\n(Enter 0 to exit)\n");
        scanf(" %c", &a);
        if (a == '0')
            break;
        else if (a == '1')
            do_1(std);
        else if (a == '2')
            continue;
    }
    printf("Student Information System Terminating.");
    getch();
    return 0;
}

