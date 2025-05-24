#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int n, m;
	cout << "Enter n:";
	cin >> n;
	cout << "Enter m:";
	cin> > m;
	
	string array[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		cout << "array[" << i << "][" << j << "]=";
		cin >> array[i][j];
		}
	}
	cout << "\n";
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < m; j++){
		cout << "array["<< i <<"][" << j << "]=" << array[i][j] << endl;
		}
	}
	return 0;
}