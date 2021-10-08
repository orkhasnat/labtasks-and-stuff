#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl;

template <typename T>
class Stack
{
private:
    std::vector<T> stack;

public:
    void push(T data) { stack.push_back(data); }
    T pop()
    {
        T i = stack.back();
        stack.pop_back();
        return i;
    }
    T peek()
    {
        T i = stack.back();
        return i;
    }
};

int main()
{
    Stack<char> my_satck;
    my_satck.push('j');
    my_satck.push('o');
    my_satck.push('k');
    my_satck.push('e');
    my_satck.pop();
    cout << my_satck.peek();
}