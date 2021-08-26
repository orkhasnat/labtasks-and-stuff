#include <iostream>

class Base
{
private:
    int x;

public:
    Base()
    {
        std::cout << "Constructor\n";
    }
    Base(int p)
    {
        x = p;
        std::cout << "Parameterized Constructor\n";
    }
    Base(Base &a)
    {
        x = a.x;
        std::cout << "Copy Constructor\n";
    }
    void display()
    {
        std::cout << x << std::endl;
    }

    void operator=(Base &a)
    {
        x = a.x;
        std::cout << "Assignment operator.\n";
    }
};

int main()
{
    Base b1(5);

    Base b2;
    b2 = b1;
    b2.display();

    Base b3(b2);
    b3.display();
}
