#include <iostream>

int main()
{
    double x= (int) 3.14;
    std::cout<<x<<'\n';

    char y= 100;
    std::cout<<(char) y<<'\n';

    int correct = 20;
    int questions = 100;
    double score = correct/(double)questions*100;
    std::cout<<score<<"%";

    return 0;
}