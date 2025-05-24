#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream file("data.txt");
    file << "Hello ! នេះគឺជាឯកសារ។";
    file.close();
    return 0;
}
