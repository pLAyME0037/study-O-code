#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	
	cout << "\n=================Input n Value of Array================\n";
	cout << "Input n (Row): ";
	cin >> n;

	int Array[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Array [ " << i << " ]: ";
		cin >> Array[i];
	}
	
	cout << "\n==================Output Value of Array=================\n";

	for (int i = 0; i < n; i++)
	{
		cout << "Array [ " << i << " ]: " << Array[i] << endl;
	}

	int max = Array[0];
	for (int i = 0; i < n; i++)
	{
		if (max < Array[i])
		{
			max = Array[i];
		}
	}

	cout << "\n======================Max of Array======================\n";
	cout << "Max of Array: " << max;

	return 0;
}