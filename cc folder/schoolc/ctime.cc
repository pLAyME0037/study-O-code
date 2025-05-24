#include <iostream>
#include <ctime>
    int main() {
    std::time_t currentTime = std::time(0); // Get current time
    std::cout << "Current time: " << std::ctime(&currentTime); // Display current time
    return 0;
}
