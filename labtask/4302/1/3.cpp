#include <iostream>
using namespace std;

class Product
{
    string name;
    double discountPercent = 0.5;
    double unitPrice = 10.00;

public:
    void assignName(string name)
    {
        this->name = name;
    }
    void setPrice(double price)
    {
        unitPrice = price * (price > 0) + unitPrice * (price < 0);
    }
    void setDiscPercent(double percent)
    {
        bool flag = percent > 0 && percent <= 10;
        discountPercent = percent * (flag) + discountPercent * (!flag);
    }
    double getSellingPrice(int nos)
    {
        return nos * unitPrice * (100 - discountPercent) / 100;
    }
    void display()
    {
        cout << name << " has a unit price BDT " << unitPrice << ". Current discount " << discountPercent << "%\n";
    }
};

int main()
{
    Product p;
    p.assignName("Cocola Noodle");
    p.setPrice(40);
    p.setDiscPercent(9);
    p.display();
    cout << "Current Price of 15 items: BDT " << p.getSellingPrice(15) << endl;
}