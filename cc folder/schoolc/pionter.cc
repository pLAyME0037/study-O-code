#include <iostream>

int main()
{
    int a = 255;
    // int* : pointer | & : address
    int* A = &a;

    std::cout << *A << "\n" << &a;

    return 0;
}