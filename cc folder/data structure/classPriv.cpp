#include <iostream>
#include <string>

// Base Class
class car
{
	// Use protected so that derived classes (like toyota) can access them directly.
	// If no derived classes needed access, you would use private.
protected:
	std::string type;
	std::string color;
	std::string speed;
	int year;

public:
	// This is the CONSTRUCTOR for the car class.
	// It's called automatically when a car object is created.
	// We use a "member initializer list" (the part after the colon)
	// This is the preferred way to initialize members.
	car(const std::string &typ, const std::string &col, const std::string &spd, int yr) : type(typ),
																													  color(col),
																													  speed(spd),
																													  year(yr)
	{
		// The constructor body can be empty if all initialization is done in the list.
		// Or you could put other setup code here.
	}

	// A public method to display the car's details.
	// 'const' at the end means this method does not modify the object's data.
	void displayDetails() const
	{
		std::cout << "Car Name:  " << type << "\n";
		std::cout << "Car Color: " << color << "\n";
		std::cout << "Car Speed: " << speed << "\n";
		std::cout << "Car Year:  " << year << "\n"; // Corrected the label here
		std::cout << "+++++++++++++" << "\n";
	}

	// A virtual destructor is good practice for base classes
	// although not strictly necessary for this simple example.
	virtual ~car() = default;
};

// Derived Class
class toyota : public car
{
public:
	// This is the CONSTRUCTOR for the toyota class.
	// It takes the same arguments and passes them "up" to the car's constructor.
	toyota(const std::string &typ, const std::string &col, const std::string &spd, int yr)
		 : car(typ, col, spd, yr) // This line calls the base class (car) constructor
	{
		// The toyota constructor body is also empty.
		// All the work is done by the base class constructor.
	}
};

int main()
{
	// Now, we provide the details WHEN WE CREATE the object.
	// This calls the toyota constructor, which in turn calls the car constructor.
	toyota corolla("Corolla", "White", "220 km/h", 2023);
	toyota tacoma("Tacoma", "Blue", "180 km/h", 2024);

	// We call the public display method whenever we want to see the details.
	std::cout << "Details for the first car:\n";
	corolla.displayDetails();

	std::cout << "\nDetails for the second car:\n";
	tacoma.displayDetails();

	return 0;
}