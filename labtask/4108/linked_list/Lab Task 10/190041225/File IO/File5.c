#include<stdio.h>
#include<string.h>
int main()
{
    FILE *bp1,*bp2,*fp1,*fp2;
    char ch1,ch2;
    int i;
    long x;
    unsigned char buff1,buff2;
    do
    {
        printf("Compare Files or Executables? :\n1.Files\n2.Executables\nAns: ");
        scanf("%d",i);
        if(i==1)
        {
            if((fp1=fopen("text1.txt","r"))==NULL)
            {
                printf("The file1 cannot be read.");
                exit(1);
            }
            if((fp2=fopen("text2.txt","r"))==NULL)
            {
                printf("The file2 cannot be read.");
                exit(1);
            }
            while((!feof(fp1))&&(!feof(fp2)))
            {
                ch1=fgetc(fp1);
                ch2=fgetc(fp2);
                if(ch1!=ch2)
                {
                    x=ftell(fp1);
                    printf("Position : %ld\t",x);
                }
            }
            fclose(fp1);fflush(stdin);
            fclose(fp2);fflush(stdout);
        }
        else  if(i==2)
        {
            if((bp1=fopen("prog1.exe","rb"))==NULL)
            {
                printf("The program1 cannot be read.");
                exit(1);
            }
            if((bp2=fopen("prog2.exe","rb"))==NULL)
            {
                printf("The program2 cannot be read.");
                exit(1);
            }
            fread(buff1,1,sizeof(buff1),bp1);
            fread(buff2,1,sizeof(buff2),bp2);
            if(buff1==buff2)
            {
                x=ftell(bp1);
                printf("Position : %ld\t",x);
            }
            fclose(bp1);fflush(stdin);
            fclose(bp2);fflush(stdout);
        }
    }
    while(i!=0);
    return 0;
}
