#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
	// [2] is row size, [3] is column size
	float twoDarray[2][3] = {
		{1, 2.2, 3.3},
		{4.4, 5.5, 6.6},
		
	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "2D array[" << i << "][" << j << "]:" << &twoDarray[i][j] << endl;
		}
	}

	return 0;
}