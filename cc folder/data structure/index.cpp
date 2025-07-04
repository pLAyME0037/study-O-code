#include <iostream>

using namespace std;

int main(){

    int array[] = {3, 1, 2};
    int n = 3;
    int min = array[0];
    for (int i = 0; i < n; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    cout << "Min: " << min << "\n";

    return 0;

    // int array[] = {3, 1, 2};
    // int n = sizeof(array) / sizeof(array[0]);
    // int min = array[0];

    // for (int i = 0; i < n; i++) {
    //     if (min > array[i]) {
    //         min = array[i];
    //     }
    // }
    // cout << "Min: " << min << "\n";

    // return 0;
}
