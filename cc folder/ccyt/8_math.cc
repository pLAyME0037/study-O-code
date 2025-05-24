#include <iostream>
#include <cmath>
int main()
{
    double x = 6.5;
    double y = 4;
    double a,b,c,d,e,f,g,h;

    a = std::max(x,y);
    std::cout<<"max is: "<<a<<'\n';

    b = std::min(x,y);
    std::cout<<"min is: "<<b<<'\n';

    c = pow(2,4);
    std::cout<<"pow is: "<<c<<'\n';

    d = sqrt(4);
    std::cout<<"sqrt is: "<<d<<'\n';

    e = abs(-4);
    std::cout<<"abs is: "<<e<<'\n';

    f = round(x);
    std::cout<<"round is: "<<f<<'\n';

    g = ceil(x);
    std::cout<<"ceil is: "<<g<<'\n';

    h = floor(x);
    std::cout<<"floor is: "<<h<<'\n';

    return 0;
}