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
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		// cout<<arr[i]<<endl;
	}
	cout << "Min of arr:" << min;
	// cout<<arr[i]<<endl;

	return 0;
}