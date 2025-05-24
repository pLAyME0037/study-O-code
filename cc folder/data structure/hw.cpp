#include <iostream>

int main() {
    int n;
    long productOfOdds = 1;
    long productOfEvens = 1;
    long result;

    std::cout << "Enter a positive Number n = ";
    std::cin >> n;

    if (n < 0) {

        std::cout << "n must be positive number." << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) productOfOdds *= i;
            else productOfEvens *= i;

            result = productOfOdds * productOfEvens;
            std::cout << productOfOdds << ", " << productOfEvens << "\n";
        }
        std::cout<< "The result " << n << "! is " << result << "\n";
    }

    return 0;
}