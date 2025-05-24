#include <iostream>
int main(){

    char grade;
    std::cout<<"Enter a letter of ur grade: ";
    std::cin>>grade;

    switch(grade)
    {
        case 'A':
        std::cout<<("\nPerfect");
        break;

        case 'B':
        std::cout<<("\nGood");
        break;

        case 'C':
        std::cout<<("\nokay");
        break;

        case 'D':
        std::cout<<("\naverage");
        break;
        
        case 'E':
        std::cout<<("\nstill winning");
        break;

        case 'F':
        std::cout<<("\nYou fail");
        break;
        
        default:
        std::cout<<("Enter only valid grade");
    }
    return 0;
}