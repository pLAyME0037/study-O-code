#include <iostream>

class triangle {
public:
   int width;
   int height;

};
class area: public triangle {
public:
   void getArea() {
      std::cout << "Area of triangle: " << (width * height) / 2 << std::endl;
   }
};
class dimension: public triangle {
public:
   void getDimension() {
      std::cout << "Dimension: " << width * height * 2 << std::endl;
   }
};
int main() {
   area a;
   a.width = 100;
   a.height = 150;
   a.getArea();

   dimension d;
   d.width = 5;
   d.height = 10;
   d.getDimension();

   return 0;
}
