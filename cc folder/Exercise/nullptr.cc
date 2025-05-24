#include <iostream>

int main() {
    int * ptr = nullptr; // ptr is a null pointer

    if (ptr == nullptr) {
        std::cout << "ptr is a null pointer" <<ptr<< std::endl;
    }

    return 0;
}