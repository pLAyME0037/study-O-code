#include <iostream> // For input/output operations (cin, cout)
#include <cmath>    // For mathematical functions like sqrt()
#include <complex>  // For handling complex numbers if roots are complex

int main() {
    // Declare variables for coefficients a, b, c
    double a, b, c;

    // Prompt the user to enter the coefficients
    std::cout << "Enter coefficient a: ";
    std::cin >> a;
    std::cout << "Enter coefficient b: ";
    std::cin >> b;
    std::cout << "Enter coefficient c: ";
    std::cin >> c;

    std::cout << "\nSolving equation: " << a << "x^2 + " << b << "x + " << c << " = 0\n" << std::endl;

    // --- Handle edge case: a = 0 (Linear Equation) ---
    if (a == 0) {
        if (b == 0) {
            // Case: 0x^2 + 0x + c = 0  => c = 0
            if (c == 0) {
                std::cout << "The equation is 0 = 0, which is true for all x (infinite solutions)." << std::endl;
            } else {
                std::cout << "The equation is " << c << " = 0, which is false (no solution)." << std::endl;
            }
        } else {
            // Case: 0x^2 + bx + c = 0 => bx = -c => x = -c / b
            double x = -c / b;
            std::cout << "This is a linear equation (a=0)." << std::endl;
            std::cout << "The solution is x = " << x << std::endl;
        }
        return 0; // Exit after handling the linear case
    }

    // --- Calculate the discriminant ---
    double discriminant = b * b - 4 * a * c;

    // --- Determine the nature of roots based on the discriminant ---
    if (discriminant > 0) {
        // Two distinct real roots
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Discriminant is positive (" << discriminant << "), so there are two distinct real roots:" << std::endl;
        std::cout << "Root 1 = " << root1 << std::endl;
        std::cout << "Root 2 = " << root2 << std::endl;
    } else if (discriminant == 0) {
        // One real root (repeated)
        double root = -b / (2 * a);
        std::cout << "Discriminant is zero, so there is one real root (a repeated root):" << std::endl;
        std::cout << "Root = " << root << std::endl;
    } else {
        // Two complex conjugate roots
        // discriminant < 0
        // Roots are: (-b ± i * sqrt(-discriminant)) / (2a)
        // Real part = -b / (2a)
        // Imaginary part = ± sqrt(-discriminant) / (2a)

        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a); // -discriminant is positive

        // Using std::complex for cleaner output
        std::complex<double> root1(realPart, imaginaryPart);
        std::complex<double> root2(realPart, -imaginaryPart);

        std::cout << "Discriminant is negative (" << discriminant << "), so there are two complex conjugate roots:" << std::endl;
        // std::cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << std::endl;
        // std::cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
         std::cout << "Root 1 = " << root1 << std::endl;
         std::cout << "Root 2 = " << root2 << std::endl;
    }

    return 0; // Indicate successful execution
}
