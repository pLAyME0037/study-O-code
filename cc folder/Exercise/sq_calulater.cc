#include <iostream>

int calculateSquare(int number) {
    return number * number;
}

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    int squaredNumber = calculateSquare(num);

    std::cout << "The square of " << num << " is " <<
    squaredNumber << std::endl;

    return 0;
}