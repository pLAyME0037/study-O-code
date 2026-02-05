#include <iostream>

int main()
{
   int a = 5, b = 10;
   int *pa = &a, *pb = &b;
   int sum = *pa + *pb;

   std::cout << "Value of a: " << a << "\n";
   std::cout << "Value of a using pointer: " << *pa << "\n";
   std::cout << "Address of a: " << &a << "\n";
   std::cout << "Address stored in pointer pa: " << pa << "\n";
   std::cout << "Sum of a and b using pointers: " << sum << "\n";
   std::cout << "Sum address: " << &sum << "\n";

   return 0;
}