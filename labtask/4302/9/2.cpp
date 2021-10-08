#include <iostream>

namespace name1
{
    int i = 234;
}
namespace name2
{
    float i = 234.56f;
}
int main()
{
    std::cout << name1::i << " " << name2::i;
}
