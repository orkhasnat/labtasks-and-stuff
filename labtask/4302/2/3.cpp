#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;

class ZooAnimal
{
    std::string name;
    int birthYr;
    int cageNo;
    float weight;
    int height;

public:
    ZooAnimal() : name(""), birthYr(0), cageNo(0), weight(0.0f), height(0){};
    void setName(std::string _name)
    {
        name = _name;
    }
    void setCageNo(int val)
    {
        cageNo = val;
    }
    void setYr(int val = 2021)
    {
        if (val > 2021)
            cout << "Wow a Time Traveller!!!";
        else
            birthYr = val;
    }
    void setHeight(int val)
    {
        height = val;
    }
    void setWeight(float val)
    {
        weight = val;
    }

    std::string getName() { return name; }
    int getCageNo() { return cageNo; }
    int getHeight() { return height; }
    int getAge() { return 2021 - birthYr; }
    float getWeight() { return weight; }

    void getInfo()
    {
        cout << "Name: " << getName()
             << "\nAge: " << getAge()
             << "\nCage No:" << getCageNo()
             << "\nWeight: " << getWeight()
             << "\nHeight: " << getHeight() << endl;
    }

    ~ZooAnimal()
    {
        cout << name << " is sadly not with us anymore ;(\n";
    }
};

int main()
{
    ZooAnimal zebra;
    zebra.setName("Zebra");
    zebra.setYr(2019);
    zebra.setCageNo(5);
    zebra.setWeight(210.5f);
    zebra.setHeight(4);
    zebra.getInfo();
}