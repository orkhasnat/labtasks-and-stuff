#include<iostream>
using namespace std;

class Counter{
    int count=0;
    int steps=1;
public:
    Counter(){
        //count=0;
        //steps=1;
    }
    void setIncrementStep(int step_val){
        steps=step_val;
    }
    void increment(){
        count+=steps;
    }
    void resetCount(){
        count=0;
    }
    int getCount(){
        return count;
    }
};

int main(){
    Counter c;
    c.setIncrementStep(5);

    c.increment();
    cout<<c.getCount()<<endl;

    c.resetCount();
    cout<<c.getCount()<<endl;
}