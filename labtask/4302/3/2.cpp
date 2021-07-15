#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Create a class FLOAT that contains one float data member. Suppose f1,f2,f3,f4 are four objects of class FLOAT.Overload all the four arithmetic operators(+,-,*,/) so that they can operate on the objects of FLOAT.For example: FLOAT operator+(FLOAT f1) for (+) operator.

// Also implement an operator overloading function to achieve the following functionalities. (Learn from task 0)
// Float f1(5.052);
// int i = f1; // this will store value 5 in i

class Float
{
    float a;

public:
    Float(float _a = 0) : a(_a) {}
    ~Float() {}

    float operator+(Float b)
    {
        return a + b.a;
    }
    float operator-(Float b)
    {
        return a - b.a;
    }
    float operator*(Float b)
    {
        return a * b.a;
    }
    float operator/(Float b)
    {
        if (b.a == 0)
            cout << "Cant divide by zero\n";
        return a / b.a;
    }
    operator float()
    {
        return a;
    }
    operator Float()
    {
        return *this;
    }
    std::ostream &operator<<(std::ostream &os)
    {
        os << a;
        return os;
    }
};

int main()
{
    float a = 17.2568;
    Float f = a, f2 = 5;
    int f1 = f / f2;
    cout << f1 << endl;
}