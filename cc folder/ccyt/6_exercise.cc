#include <iostream>

int main()
{
    const double PI = 3.14159;
    double radious;
    double circumference;

    std::cout<<("\nEnter the radious of a circle: ");
    std::cin>>(radious);

    circumference = 2 * PI * radious;

    std::cout<<"\nCircumference: "<< circumference;

    return 0;
}