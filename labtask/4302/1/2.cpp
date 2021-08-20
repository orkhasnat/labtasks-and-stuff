#include <iostream>
using namespace std;

class RationalNumber{
    int numerator=0;
    int denominator=1;
public:
    double convert(){
        return (double)numerator/denominator;
    }
    void assign(int numer, int denom){
        if (!denom)
        {
            cout<<"Error!! Denominator cant be 0\n";
            return;
        }
        numerator=numer;
        denominator=denom;
    }
    void print(){
        printf("The Rational Number is : %d/%d \n",numerator,denominator);
    }
    void invert(){
        if (!numerator)
        {
            cout<<"Error!! Denominator cant be 0\n";
            return;
        }
        int tmp=numerator;
        numerator=denominator;
        denominator=tmp;
    }
};

int main(){
    RationalNumber a;

    a.assign(3,2);
    cout<<a.convert()<<'\n';

    a.invert();
    a.print();
}