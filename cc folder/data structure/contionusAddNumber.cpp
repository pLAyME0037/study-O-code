#include <iostream>
#include <vector> // For std::vector
#include <limits> // For std::numeric_limits
#include <ios>		// For std::streamsize

using namespace std;

int main(int argc, char **argv)
{
	// int n;
	// cin >> n;
	// int arr[n];
	// for(int i=0; i < n; i++){
	// 	cout << "arr[" << i << "]:";
	// 	cin >> arr[i];
	// }
	// cout << "\n";
	// for(int i = 0; i < n; i++){
	// 	cout << "arr[" << i << "]:" << arr[i] << endl;
	// }
	// cout << "\n";
	// int arrs[n + 1];
	// for(int i = 0; i < n; i++){
	// 	arrs[i] = arr[i];
	// }

	// do{
	// 	cout << "New element:";
	// 	cin >> arrs[n];
	// 	for(int i = 0; i <= n; i++){
	// 	}
	// 	while (arrs[n] != int)
	// 	{
	// 		cout << "arrs[" << i << "]:" << arrs[i] << endl;
	// 	}

	// }

	int n;
	// Get the initial size of the array
	std::cout << "Enter the size of the array: ";
	while (!(std::cin >> n) || n <= 0)
	{
		std::cout << "Invalid input. Please enter a positive integer for the size: ";
		std::cin.clear();																	  // Clear error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
	}
	// Declare a vector of size n
	std::vector<int> arr(n);
	// Populate the vector with user input
	for (int i = 0; i < n; ++i)
	{
		std::cout << "arr[" << i << "]: ";
		while (!(std::cin >> arr[i]))
		{
			std::cout << "Invalid input. Please enter an integer for arr[" << i << "]: ";
			std::cin.clear();																	  // Clear error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		}
	}
	std::cout << "\n";
	// Display the elements of the vector
	std::cout << "Current elements in the array:\n";
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
	}
	std::cout << "\n";
	// Loop to continuously add new elements
	int newElement;
	char choice;
	do
	{
		std::cout << "Enter a new element to add (or 'q' to quit): ";
		// Attempt to read an integer
		if (std::cin >> newElement)
		{
			arr.push_back(newElement); // Add the new element to the end of the vector
			// Display all elements including the newly added one
			std::cout << "Elements after adding new element:\n";
			for (int i = 0; i < arr.size(); ++i)
			{
				std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
			}
			std::cout << "\n";
			std::cout << "Do you want to add another element? (y/n): ";
			std::cin >> choice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
		}
		else
		{
			// If input was not an integer, check if it's 'q' to quit
			std::cin.clear(); // Clear error flags
			std::string temp_input;
			std::cin >> temp_input;
			if (temp_input == "q" || temp_input == "Q")
			{
				choice = 'n'; // Set choice to 'n' to exit the loop
				std::cout << "Exiting input loop.\n";
			}
			else
			{
				std::cout << "Invalid input. Please enter an integer or 'q' to quit.\n";
				// Don't clear buffer here as std::cin >> temp_input already consumed it.
				choice = 'y'; // Continue the loop if it was just invalid input (not 'q')
			}
		}
	} while (choice == 'y' || choice == 'Y');

	return 0;
}