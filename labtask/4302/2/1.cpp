#include <iostream>
using std::cin, std::cout, std::endl;

class Calculator
{
    int field;

public:
    Calculator()
    {
        field = 0;
    }
    Calculator(int val)
    {
        field = val;
    }
    ~Calculator()
    {
        field = 0;
        cout << "calculator object is destroyed.";
    }
    int getValue()
    {
        return field;
    }
    void setValue()
    {
    }
    void add(int val)
    {
        field += val;
    }
    void subtract(int val)
    {
        field -= val;
    }
    void multiply(int val)
    {
        field *= val;
    }
    void divide(int val)
    {
        if (!val)
            cout << "Divide by 0 is undefined";
        else
            field /= val;
    }
    void clear()
    {
        field = 0;
    }
    void display()
    {
        cout <<"Calculator display: "<< field << endl;
    }
};
void separator()
{
    cout << "------------------------------\n";
}

int main()
{
    Calculator calc;
    int x,y;
    while (1)
    {
        cout << "1.ADD\n2.Subtract\n3.Multiply\n4.Divide\n5.Clear\n";
        separator();
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            scanf("%d", &x);
            calc.add(x);
            break;
        case 2:
            scanf("%d", &x);
            calc.subtract(x);
            break;
        case 3:
            scanf("%d", &x);
            calc.multiply(x);
            break;
        case 4:
            scanf("%d", &x);
            calc.divide(x);
            break;
        case 5:
            calc.clear();
            break;
        default:
            break;
        }
        calc.display();
        if (y > 5)
            break;
    }
}