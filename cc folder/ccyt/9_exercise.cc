#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double A;
    double B;
    double C;

    cout<<("Enter Triangle AB: ");
    cin>> A;

    cout<<("Enter Triangle BC: ");
    cin>>B;

    C = sqrt(A * A + B * B);

    cout<<"Triangle AB is: "<< C;

    return 0;
}