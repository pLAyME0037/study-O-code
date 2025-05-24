#include <iostream>

int main()
{
    int a = 255;
    int * aa = &a;

    std::cout << *aa << "\n" << &a;

    return 0;
}