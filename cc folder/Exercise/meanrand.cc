#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // For time()
using namespace std;

int num() {
    return (rand() % 2) + 1;
}

void printNumbers(int number1, int number2, int number3) {
    cout << "\t" << number1;
    cout << "\t" << number2;
    cout << "\t" << number3;
}

int main() {
    srand((time(0)));   //srand = number generator used by functions like rand().

    int number1 = num();
    int number2 = num();
    int number3 = num();

    printNumbers(number1, number2, number3);

    return 0;
}
