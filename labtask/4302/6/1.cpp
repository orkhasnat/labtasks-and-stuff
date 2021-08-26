#include <iostream>

class Pet
{
protected:
    int a;

public:
    virtual void say()
    {
        std::cout << ":0\n";
    }
};

class Pet2
{
protected:
    int a;

public:
    virtual void say2() = 0; ///Pure virtual function, hence this class can't have any object
};

class Cat : public Pet
{
public:
    void say()
    {
        std::cout << "Mew\n"; ///Overrides the say function
    }
};

class Dog : public Pet2
{
public:
    void say2()
    {
        std::cout << "Woof\n"; ///Overrides the say2 function though the function
    }
};

int main()
{
    Pet p;
    //Pet2 p2; // p2 object can't exist because abstract class ;can only be created with pointers
    Cat c;
    Dog d;

    p.say();
    
    c.say();  
    d.say2();
}
