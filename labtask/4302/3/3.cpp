#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class ZooAnimal
{
    std::string name;
    int birthYr;
    int cageNo;
    float weight;
    int height;

public:
    ZooAnimal()
        : name(""), birthYr(0), cageNo(0), weight(0.0f), height(0) {}
    ZooAnimal(std::string _name, int By, int cg, float w, int h)
        : name(_name), birthYr(By), cageNo(cg), weight(w), height(h) {}
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

    bool operator==(int w)
    {
        return int(weight) == w;
    }
    void operator-=(int dec)
    {
        height -= dec;
    }
    void operator--()
    {
        height--;
    }
    void operator--(int)
    {
        height--;
    }
    friend std::ostream &operator<<(std::ostream &os, ZooAnimal &c)
    {
        c.getInfo();
        return os;
    }
};

int main()
{
    ZooAnimal zebra("Ralph", 2019, 132, 350.5, 4);
    (zebra == 350) ? zebra--: zebra-=5;
    std::cout << zebra;
}
