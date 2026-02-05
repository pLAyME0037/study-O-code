#include <iostream>

class car
{
private:
   /* data */
public:
   std::string type, color, speed;
   int year;
};

class toyota : public car
{
public:
   void toyotas(std::string typ, std::string col, std::string speeds, int years)
   {
      type = typ;
      color = col;
      speed = speeds;
      int year = years;

      std::cout << "Car Name: " << type << "\n";
      std::cout << "Car Color: " << color << "\n";
      std::cout << "Car Speed: " << speed << "\n";
      std::cout << "Car Speed: " << year << "\n";
      std::cout << "+++++++++++++" << "\n";
   }
};

int main()
{

   toyota type;

   type.toyotas("Corolla", "White", "220 km/h", 2023);
   type.toyotas("tacoma", "blue", "220 km/h", 2024);
   return 0;
}