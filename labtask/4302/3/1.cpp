#include <iostream>
#include <cmath>
using std::endl;

class Coord
{
    float x, y;

public:
    Coord(float a=0, float b=0)
        : x(a), y(b) {}
    ~Coord() {}

    float getDistance(Coord &);
    float getDistance();
    void move_x(float);
    void move_y(float);
    void move(float);
    void display();

    Coord &operator++()
    {
        move(1);
        return *this;
    }
    Coord operator++(int)
    {
        Coord tmp = *this;
        ++*this;
        return tmp;
    }
    Coord &operator--()
    {
        move(-1);
        return *this;
    }
    Coord operator--(int)
    {
        Coord tmp = *this;
        --*this;
        return tmp;
    }
    friend std::ostream &operator<<(std::ostream &, Coord &);
};

// operator overloading
std::ostream &operator<<(std::ostream &os, Coord &c)
{
    os << '(' << c.x << ',' << c.y << ')';
    return os;
}
bool operator==(Coord &a, Coord &b)
{
    float q = a.getDistance();
    float w = b.getDistance();
    return q == w;
    //return a.getDistance() == b.getDistance(); // wtf!! why this is false but prev is true huh??
}
bool operator<(Coord &a, Coord &b)
{
    return a.getDistance() < b.getDistance();
}
bool operator<=(Coord &a, Coord &b)
{
    return a.getDistance() <= b.getDistance();
}
bool operator>=(Coord &a, Coord &b)
{
    return a.getDistance() >= b.getDistance();
}
bool operator!=(Coord &a, Coord &b)
{
    return a.getDistance() != b.getDistance();
}
bool operator>(Coord &a, Coord &b)
{
    return a.getDistance() > b.getDistance();
}

// public functions
void Coord::display()
{
    printf("(%f,%f)\n", x, y);
}

void Coord::move_x(float val)
{
    x += val;
}
void Coord::move_y(float val)
{
    y += val;
}
void Coord::move(float val)
{
    move_x(val);
    move_y(val);
}
float Coord::getDistance()
{
    return std::sqrt(x * x + y * y);
}

float Coord::getDistance(Coord &c)
{
    float a = (x - c.x), b = (y - c.y);
    return std::sqrt(a * a + b * b);
}

int main()
{
    Coord c1(1, 1), c2(-1, -1);
    Coord c3 = (c1 == c2) ? ++c1 : c1++;
    std::cout << c1 << " " << c3 << endl;
}
