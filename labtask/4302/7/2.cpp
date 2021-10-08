#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;
const int LEN = 32;
const int MAXEM = 100;
enum Student_type
{
    honors,
    masters,
    diploma
};
////////////////////////////////////////////////////////////////
class Student
{
private:
    char name[LEN];
    unsigned long number;
    static int n;
    static Student *arrap[]; //array of ptrs to emps
public:
    virtual void getdata()
    {
        std::cin.ignore(10, '\n');
        std::cout << " Enter last name : ";
        std::cin >> name;
        std::cout << " Enter number : ";
        std::cin >> number;
    }
    virtual void putdata()
    {
        std::cout << "\nName : " << name;
        std::cout << "\nNumber : " << number;
    }
    virtual Student_type get_type(); //get type
    static void add();
    static void display(); //display all Students
    static void read();
    static void write();
};
//--------------------------------------------------------------
int Student::n;
Student *Student::arrap[MAXEM]; //array of ptrs to emps
//--------------------------------------------------------------
class Honors : public Student
{
private:
    char title[LEN];
    double dues;

public:
    void getdata()
    {
        Student::getdata();
        std::cout << " Enter title : ";
        std::cin >> title;
        std::cout << " Enter golf club dues : ";
        std::cin >> dues;
    }
    void putdata()
    {
        Student::putdata();
        std::cout << "\nTitle : " << title;
        std::cout << "\nGolf club dues : " << dues;
    }
};
class Masters : public Student
{
private:
    int pubs;

public:
    void getdata()
    {
        Student::getdata();
        std::cout << " Enter number of pubs : ";
        std::cin >> pubs;
    }
    void putdata()
    {
        Student::putdata();
        std::cout << "\nNumber of publications : " << pubs;
    }
};
////////////////////////////////////////////////////////////////
class Diploma : public Student
{
};
////////////////////////////////////////////////////////////////
void Student::add()
{
    char ch;
    std::cout << "'h' to add a Honors"
                 "\n'm' to add a Masters"
                 "\n'd' to add a Diploma"
                 "\nEnter selection : ";
    std::cin >> ch;
    switch (ch)
    {
    case 'h':
        arrap[n] = new Honors;
        break;
    case 'm':
        arrap[n] = new Masters;
        break;
    case 'd':
        arrap[n] = new Diploma;
        break;
    default:
        std::cout << "\nUnknown Student type\n";
        return;
    }
    arrap[n++]->getdata();
}
//--------------------------------------------------------------
void Student::display()
{
    for (int j = 0; j < n; j++)
    {
        std::cout << (j + 1);
        switch (arrap[j]->get_type())
        {
        case honors:
            std::cout << ".Type : Honors";
            break;
        case masters:
            std::cout << ".Type : Masters";
            break;
        case diploma:
            std::cout << ".Type : Diploma";
            break;
        default:
            std::cout << ".Unknown type";
        }
        arrap[j]->putdata();
        std::cout << std::endl;
    }
}
//--------------------------------------------------------------
Student_type Student::get_type()
{
    if (typeid(*this) == typeid(Honors))
        return honors;
    else if (typeid(*this) == typeid(Masters))
        return masters;
    else if (typeid(*this) == typeid(Diploma))
        return diploma;
    else
    {
        std::cerr << "\nBad Student type";
        exit(1);
    }
    return honors;
}
//--------------------------------------------------------------
void Student::write()
{
    int size;
    std::cout << "Writing " << n << " Students.\n";
    std::ofstream ouf;
    Student_type etype;
    ouf.open("STUDENT.DAT", std::ios::trunc | std::ios::binary);
    if (!ouf)
    {
        std::cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++)
    {
        etype = arrap[j]->get_type();
        ouf.write((char *)&etype, sizeof(etype));
        switch (etype)
        {
        case honors:
            size = sizeof(Honors);
            break;
        case masters:
            size = sizeof(Masters);
            break;
        case diploma:
            size = sizeof(Diploma);
            break;
        }
        ouf.write((char *)(arrap[j]), size);
        if (!ouf)
        {
            std::cout << "\nCan't write to file\n";
            return;
        }
    }
}
//--------------------------------------------------------------
void Student::read()
{
    int size;
    Student_type etype;
    std::ifstream inf;
    inf.open("STUDENT.DAT", std::ios::binary);
    if (!inf)
    {
        std::cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    {
        inf.read((char *)&etype, sizeof(etype));
        if (inf.eof())
            break;
        if (!inf)
        {
            std::cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype)
        {
        case honors:
            arrap[n] = new Honors;
            size = sizeof(Honors);
            break;
        case masters:
            arrap[n] = new Masters;
            size = sizeof(Masters);
            break;
        case diploma:
            arrap[n] = new Diploma;
            size = sizeof(Diploma);
            break;
        default:
            std::cout << "\nUnknown type in file\n";
            return;
        }
        inf.read((char *)arrap[n], size);
        if (!inf)
        {
            std::cout << "\nCan't read data from file\n";
            return;
        }
        n++;
    }
    std::cout << "Reading " << n << " Students\n";
}
////////////////////////////////////////////////////////////////
int main()
{
    char ch;
    while (true)
    {
        std::cout << "'a' -- add data for an Student"
                     "\n'd' -- display data for all Students"
                     "\n'w' -- write all Student data to file"
                     "\n'r' -- read all Student data from file"
                     "\n'x' -- exit"
                     "\nEnter selection: ";
        std::cin >> ch;
        switch (ch)
        {
        case 'a':
            Student::add();
            break;
        case 'd':
            Student::display();
            break;
        case 'w':
            Student::write();
            break;
        case 'r':
            Student::read();
            break;
        case 'x':
            exit(0);
        default:
            std::cout << "\nUnknown command";
        }
    }
    return 0;
}