#include <iostream>
#include <algorithm>

struct Student
{
    int ds;
    int nt;
    int ml;
    char name[20];
};

bool compare(const Student &st1,const Student &st2)
{
    if(st1.ml+st1.ds+st1.nt>st2.ml+st2.ds+st2.nt) return true;
    if(st1.ml+st1.ds+st1.nt<st2.ml+st2.ds+st2.nt) return false;

    if(st1.ml>st2.ml) return true;
    if(st1.ml<st2.ml) return false;

    if(st1.ds>st2.ds) return true;
    if(st1.ds<st2.ds) return false;

    if(st1.nt>st2.nt) return true;
    if(st1.nt<st2.nt) return false;

    return true;
}

int main()
{
    int n;
    std::cin >> n;
    Student student[n];
    for (int i = 0; i < n; i++)
    
        std::cin >> student[i].name >> student[i].ml >> student[i].ds >> student[i].nt;
    
    //std::cout<<std::endl;
    std::sort(student, student + n,compare);
     for (int i = 0; i < n; i++)
         std::cout<<i+1<<"   "<<student[i].name<<std::endl;
}
