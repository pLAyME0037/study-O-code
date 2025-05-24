#include <iostream>
namespace one{
    int x=1;
}
namespace two{
    int x=2;
}
int main()
{
    int x=0;
    std::cout<<x<<'\n';
    std::cout<<one::x<<'\n';
    std::cout<<two::x<<'\n';

    return 0;
}