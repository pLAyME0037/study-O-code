#include <iostream>
using namespace std;

void code(int a, int b, char c);

int main(){
    int a = 10;
    int b = 3;
    char c = 'b';    

    code(a, b, c);
    
    return 0;
}
void code(int a, int b, char c){
    a++;
    b--;
    c  = 'a';

    cout<<a<<" "<<b<<" "<<c;
}