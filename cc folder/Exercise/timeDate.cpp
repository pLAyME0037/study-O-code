#include <iostream>
#include <ctime>

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "Current Local Date and Time is: " << asctime(ltm);
    return 0;
}
