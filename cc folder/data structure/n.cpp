#include <iostream>

// int main(){
//     int n;
//     int factor = 1;

//     std::cout << "n = ";
//     std::cin >> n;

//     for (int i = n; i <= 1; i++) {
//         int factor = factor * i;
//         std::cout << factor;
//     }

//     return 0;
// }

#include <iostream>

int main() {
    int n;
    // Use long long to handle potentially large factorial values
    long long factorial = 1;

    std::cout << "Enter a non-negative integer n = ";
    std::cin >> n;

    // Handle negative input
    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Calculate factorial (handle n=0 correctly as loop won't run, factorial remains 1)
        // Loop from 1 up to n
        for (int i = 1; i <= n; ++i) {
            // Update the original factorial variable
            factorial = factorial * i;
        }
        // Print the final result *after* the loop
        std::cout << "The factorial of " << n << " is " << factorial << std::endl;
    }

    return 0;
}