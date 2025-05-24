#include <iostream>

using namespace std;

int main(){
    int n = 3;
    int cal[n];
    int arr[] = {3, 4, 5};
    int arrr[] = {9, 3, 8};

    for(int i = 0; i < n; i++){
        cal[i] = arr[i] + arrr[i];
        cout << cal[i] << ", ";
    }
    return 0;
}