#include <iostream>
#include <string>

using namespace std;

string decimalToBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    int decimalNum;
    string binaryNum;

    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    binaryNum = decimalToBinary(decimalNum);

    cout << "Binary equivalent: " << binaryNum << endl;

    return 0;
}
/* 
Explanation:

Include Header:

iostream: Provides standard input/output objects like cin and cout.
string: Allows working with strings in C++.
Function decimalToBinary(int n):

Takes an integer n as input.
Initializes an empty string binary to store the binary representation.
While loop: Continues as long as n is greater than 0.
Calculates the remainder of n divided by 2 using n % 2.
Converts the remainder to a string using to_string() and appends it to the beginning of the binary string.
Performs integer division of n by 2 using n /= 2.
Returns the binary string.
Main Function:

Declares an integer variable decimalNum to store the user input.
Prompts the user to enter a decimal number and reads it using cin.
Calls the decimalToBinary() function to convert the decimal number to its binary equivalent.
Prints the binary representation to the console.
This program effectively converts a given decimal number to its binary representation using the repeated division and remainder method.
*/