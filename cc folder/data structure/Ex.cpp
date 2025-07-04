#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char **argv)
{
	int n;
	cout << "Input n:";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]:";
		cin >> arr[i];
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]:" << arr[i] << endl;
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]:" << &arr[i] << endl;
	}
	cout << "\n";
	for (int i = 0; i < n - 1; i++)
	{
		cout << "arr[" << i << "]:" << arr[i] << endl;
	}

	return 0;
}