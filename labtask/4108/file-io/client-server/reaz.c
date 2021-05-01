#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void course_gpa(char course[], int marks, FILE *cp)
{
    fseek(cp, 0, SEEK_SET);
    char course_name[100], course_cmp[100], end[100];
    double total_marks;

    while (!feof(cp))
    {
        fgets(course_name, 100, cp);
        fgets(course_cmp, 100, cp);
        fscanf(cp, "%lf", &total_marks);
        fgetc(cp);
        fgets(end, 100, cp);
        //printf("%s%s%lf\n%s",course_name,course_cmp,total_marks,end);
        if (!strcmp(course_cmp, course))
        {
            char grade[10];
            double gp, course_gpa = (double)marks / total_marks;
            if (course_gpa >= 80)
            {
                strcpy(grade, "A+");
                gp = 4.00;
            }
            else if (course_gpa >= 70)
            {
                strcpy(grade, "A");
                gp = 3.50;
            }
            else if (course_gpa >= 60)
            {
                strcpy(grade, "B");
                gp = 3.00;
            }
            else if (course_gpa >= 50)
            {
                strcpy(grade, "C");
                gp = 2.50;
            }
            else if (course_gpa >= 40)
            {
                strcpy(grade, "D");
                gp = 2.00;
            }
            else
            {
                strcpy(grade, "F");
                gp = 0;
            }
            printf("Course:\t%sCourse ID:\t\t%sAttained Marks:\t\t%d\nAttained Grade:\t\t%s\nAttained Grade Point:\t%.2lf\n", course_name, course, marks, grade, gp);
            return;
        }
    }
}

void calc(char course[], int marks, double *gpa, FILE *cp)
{
    fseek(cp, 0, SEEK_SET);
    char course_name[100], course_cmp[100], end[100];
    double total_marks;
    while (!feof(cp))
    {
        fgets(course_name, 100, cp);
        fgets(course_cmp, 100, cp);
        fscanf(cp, "%lf", &total_marks);
        fgetc(cp);
        fgets(end, 100, cp);
        if (!strcmp(course_cmp, course))
        {
            double course_gpa = (double)marks / total_marks;
            //printf("%lf\n",course_gpa);
            if (course_gpa >= 80)
                *gpa += 4;
            else if (course_gpa >= 70)
                *gpa += 3.5;
            else if (course_gpa >= 60)
                *gpa += 3.0;
            else if (course_gpa >= 50)
                *gpa += 2.5;
            else if (course_gpa >= 40)
                *gpa += 2.0;
        }
    }
}

int option()
{
    char id[15];
    printf("\nEnter your student ID: ");
    scanf("%s", id);
    if (!strcmp(id, "0"))
    {
        printf("Student Information System Terminating.\n");
        return 0;
    }
    strcat(id, "\n");
    FILE *sp, *cp, *mp;
    bool found = false;
    if ((sp = fopen("student.txt", "r")) == NULL)
    {
        printf("Could not open student file.\n");
        return 1;
    }

    if ((cp = fopen("course.txt", "r")) == NULL)
    {
        printf("Could not open course file.\n");
        return 1;
    }

    if ((mp = fopen("marks.txt", "r")) == NULL)
    {
        printf("Could not open marks file.\n");
        return 1;
    }

    char id_new[15], name[100], residence[100], end[100];

    while (!feof(sp))
    {
        fgets(name, 100, sp);
        fgets(id_new, 15, sp);
        fgets(residence, 100, sp);
        fgets(end, 100, sp);
        //printf("%s%s%s%s\n",name,id_new,residence,end);
        if (!strcmp(id_new, id))
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("Student ID not found.\n");
        return 1;
    }

    int year = 2000;
    char program[100], department[50];
    double cgpa, gpa = 0;
    year += id[1] - '0' + 10 * (id[0] - '0');
    if (id[4] == '1')
        strcpy(department, "MCE\n");
    else if (id[4] == '2')
        strcpy(department, "EEE\n");
    else if (id[4] == '3')
        strcpy(department, "TVE\n");
    else if (id[4] == '4')
        strcpy(department, "CSE\n");
    else
        strcpy(department, "Invalid\n");
    if (id[5] == '1')
        strcpy(program, "Bachelor of Science\n");
    else if (id[5] == '2')
        strcpy(program, "Higher Diploma\n");
    else
        strcpy(program, "Invalid\n");

    char course[100];
    int marks, cnt = 0;
    char test[100];
    while (!feof(mp))
    {
        fgets(id_new, 15, mp);
        fgets(course, 100, mp);
        fscanf(mp, "%d", &marks);
        fgetc(mp);
        fgets(end, 100, mp);
        if (!strcmp(id_new, id))
        {
            calc(course, marks, &gpa, cp);
            cnt++;
        }
    }

    cgpa = (cnt) ? gpa / (double)cnt : 0;

    printf("Displaying Student Information:\nName:\t\t%sAddress:\t%sStudent ID:\t%sAdmission Year:\t%d\nProgram:\t%sDepartment:\t%sCGPA:\t\t%.2lf\n", name, residence, id, year, program, department, cgpa);
    printf("Do you want to see your result in details?\n1.\tYes\n2.\tNo\nEnter Choice:\t");
    int choice;
    scanf("%d", &choice);
    getchar();
    if (choice == 1)
    {
        fseek(mp, 0, SEEK_SET);
        while (!feof(mp))
        {
            fgets(id_new, 15, mp);
            fgets(course, 100, mp);
            fscanf(mp, "%d", &marks);
            fgetc(mp);
            fgets(end, 100, mp);
            if (!strcmp(id_new, id))
                course_gpa(course, marks, cp);
        }
    }
    fclose(mp);
    fclose(cp);
    fclose(sp);
    return 1;
}

int main()
{
    printf("Student Information System Initializing.");
    while (1)
        if (!option())
            return 0;
}