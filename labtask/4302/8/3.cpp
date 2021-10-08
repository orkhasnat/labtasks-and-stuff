#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl;

template <typename T>
class Stack
{
private:
    std::vector<T> stack;
    int _size;

public:
    class EmptyStackException
    {
    };
    Stack() : _size(0) {}
    void push(T data)
    {
        stack.push_back(data);
        _size++;
    }
    T pop()
    {
        if (!_size)
            throw EmptyStackException();
        T i = stack.back();
        stack.pop_back();
        _size--;
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
    Stack<char> my_stack;
    try
    {
        my_stack.push('j');
        // my_stack.push('o');
        // my_stack.push('k');
        // my_stack.push('e');
        // my_stack.pop();
        cout << my_stack.peek();
        cout << my_stack.pop();
        my_stack.pop();
    }
    catch (Stack<char>::EmptyStackException e)
    {
        std::cerr << "Empty Stack!!!";
    }
}