#include <iostream>
using namespace std;
int main()
{
    int age;

    cout<<"Enter your age: ";
    cin>>age;

    if(age==100){
        cout<<"Congraturation? you lived for a cetury.";
    }
    else if(age==0){
        cout<<"Congraturation? you are zero year old.";
    }
    else if(age>=18){
        cout<<"You are more than 18 years old. You are "<<age<<" years old.";
        
    }
    else{
        cout<<"You are less than 18 years old. You are "<<age<<" year(s) old.";
    }
    return 0;
}