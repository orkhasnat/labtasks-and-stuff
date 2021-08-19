#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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