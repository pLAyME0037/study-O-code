#include <iostream>

using namespace std;

int main(){
    int oldNum, newNum, use, payment;


    cout<<"\tInput Old Number: ";
    cin>>oldNum;
    cout<<"\tInput New Number: ";
    cin>>newNum;

    cout<<"------------------------USE--------------------------\n";
    use = newNum - oldNum;
    cout<<"\tUse: "<<use<<endl;
    cout<<"------------------------PAY--------------------------\n";

    if(use<50){
        payment = use * 350;
        cout<<"Payment: "<<payment<<"_R\n";
    }
        else if(use>=50 && use<100){
        payment = use * 400;
        cout<<"Payment: "<<payment<<"_R\n";
    }
        else if(use>=100 && use<150){
        payment = use * 500;
        cout<<"Payment: "<<payment<<"_R\n";
    }
        else if(use>=150 && use<200){
        payment = use * 600;
        cout<<"Payment: "<<payment<<"_R\n";
    }
        else if(use>=200){
        payment = use * 700;
        cout<<"Payment: "<<payment<<"_R\n";
    }
    return 0;
}