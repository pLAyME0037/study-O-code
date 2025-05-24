#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int decimalNum;

    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    string binaryNum = bitset<sizeof(int) * 8>(decimalNum).to_string(); 

    size_t pos = binaryNum.find_first_not_of('0');
    if (pos != string::npos) {
        binaryNum.erase(0, pos);
    }

    cout << "Binary representation: " << binaryNum << endl;

    return 0;
}