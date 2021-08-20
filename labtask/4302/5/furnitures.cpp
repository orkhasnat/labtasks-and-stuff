#include <iostream>
#include <string>
using namespace std;
enum class Material
{
    Wood,
    Board,
    Steel,
    Foam
};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string name; //task 3

public:
    Furniture(double p, double d, Material m) : price(0), discount(0), madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if (val > 0)
            price = val;
    }
    void setDiscount(double val)
    {
        if (val <= price)
            discount = val;
    }
    void setDiscountPercentage(double val) // New function added
    {
        if (val <= 100)
            discount = price * val / 100;
    }
    void setMadeof(Material val)
    {
        madeof = val;
    }
    void setName(string str) //task 3
    {
        name = str;
    }
    string getMadeof()
    {
        if (madeof == Material::Wood)
            return string("Wood");
        else if (madeof == Material::Board)
            return string("Board");
        else if (madeof == Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails() = 0;
    double getDiscountedPrice() const // New function added
    {
        return price - discount;
    }
};

enum class BedSize
{
    Single,
    SemiDouble,
    Double
};

class Bed : public Furniture
{
private:
    BedSize type;

public:
    Bed(double p, double d, Material m, BedSize bsize) : Furniture(p, d, m), type(bsize)
    {
    }

    void productDetails()
    {
        for (int i = 0; i < 48; i++)
            cout << "-";
        cout << endl;
        cout << "Product Name: " << name << endl; //task3
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << getDiscountedPrice() << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Bed Size: ";
        switch (type)
        {
        case BedSize::Single:
            cout << "Single\n";
            break;
        case BedSize::SemiDouble:
            cout << "SemiDouble\n";
            break;
        case BedSize::Double:
            cout << "Double\n";
        }
        for (int i = 0; i < 48; i++)
            cout << "#";
        cout << endl;
    }
};

enum class SeatNumber
{
    One = 1,
    Two,
    Three,
    Four,
    Five
};

class Sofa : public Furniture
{
private:
    SeatNumber seat;

public:
    Sofa(double p, double d, Material m, SeatNumber num) : Furniture(p, d, m), seat(num)
    {
    }

    void productDetails()
    {
        for (int i = 0; i < 48; i++)
            cout << "-";
        cout << endl;
        /*For Task 3*/ cout << "Product Name: " << name << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Number of Seats: ";
        switch (seat)
        {
        //case 1:
        case SeatNumber::One:
            cout << "One\n";
            break;
        case SeatNumber::Two:
            cout << "Two\n";
            break;
        case SeatNumber::Three:
            cout << "Three\n";
            break;
        case SeatNumber::Four:
            cout << "Four\n";
            break;
        case SeatNumber::Five:
            cout << "Five\n";
        }
        for (int i = 0; i < 48; i++)
            cout << "#";
        cout << endl;
    }
};

enum class DoorNumber
{
    Two = 2,
    Three,
    Four
};

class Almirah : public Furniture
{
private:
    DoorNumber door;

public:
    Almirah(double p, double d, Material m, DoorNumber num) : Furniture(p, d, m), door(num)
    {
    }

    void productDetails()
    {
        for (int i = 0; i < 48; i++)
            cout << "-";
        cout << endl;
        cout << "Product Name: " << name << endl; //task3
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Number of Seats: ";
        switch (door)
        {
        case DoorNumber::Two:
            cout << "Two\n";
            break;
        case DoorNumber::Three:
            cout << "Three\n";
            break;
        case DoorNumber::Four:
            cout << "Four\n";
        }
        for (int i = 0; i < 48; i++)
            cout << "#";
        cout << endl;
    }
};

void sort_furniture_discount(Furniture **furnitures, int no_of_furnitures)
{
    for (int i = 0; i < no_of_furnitures; i++)
        for (int j = i + 1; j < no_of_furnitures; j++)
            if (furnitures[i]->getDiscountedPrice() < furnitures[j]->getDiscountedPrice())
                swap(furnitures[i], furnitures[j]);
}

int main()
{
    Furniture *f_list[100];

    f_list[0] = new Bed(10000, 123, Material::Wood, BedSize::Single);
    f_list[1] = new Sofa(11000, 234, Material::Steel, SeatNumber::Five);
    f_list[2] = new Almirah(13000, 345, Material::Wood, DoorNumber::Two);
    f_list[3] = new Bed(10090, 123, Material::Wood, BedSize::Single);

    f_list[2]->setDiscountPercentage(30);
    f_list[0]->setName("Bahari Bed");
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
    }
    cout << endl;
    for (int i = 0; i < 48; i++)
        cout << "=";
    cout << endl;
    for (int i = 0; i < 48; i++)
        cout << "=";
    cout << endl << endl;
    //std::sort();
    sort_furniture_discount(f_list, 4);
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
    }
}