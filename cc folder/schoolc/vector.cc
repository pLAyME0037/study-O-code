#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg) //& is used as a reference operator for "word".
    {
        cout << word << " ";
    }
    cout << endl;
}