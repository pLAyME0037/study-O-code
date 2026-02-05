#include <iostream>

class toyota
{
private:
	std::string car_name;
	std::string color;
	std::string speed;
	int price;

public:
	void toyotas(std::string car_n, std::string col, std::string sp, int pri)
	{
		car_name = car_n;
		color = col;
		speed = sp;
		price = pri;

		std::cout << "Car Name: " << car_name << "\n";
		std::cout << "Car Color: " << color << "\n";
		std::cout << "Car Speed: " << speed << "\n";
		std::cout << "Car Speed: " << price << "\n";
		std::cout << "+++++++++++++" << "\n\n";
	}
	int prices;
};
class phone
{
private:
	std::string name;
	std::string color;
	int price;

public:
	void phones(std::string n, std::string col, int pri)
	{
		name = n;
		color = col;
		price = pri;

		std::cout << "Phone Name: " << name << "\n";
		std::cout << "Phone Color: " << color << "\n";
		std::cout << "Phone Speed: " << price << "\n";
		std::cout << "+++++++++++++" << "\n\n";
	}
};
int main()
{

	toyota typeToyota;
	typeToyota.toyotas("rav4", "red", "240km/h", 400000);
	typeToyota.toyotas("rav3", "white", "220km/h", 300000);

	typeToyota.prices = 2323;
	typeToyota.prices = 2300;
	std::cout << "Prices: " << typeToyota.prices << "\n\n";

	phone typePhone;
	typePhone.phones("OPPO reno serie", "Grey", 660);
	typePhone.phones("Samsung Galaxy", "black", 750);

	return 0;
}
