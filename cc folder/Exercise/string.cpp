#include <iostream>

using namespace std;

int main(){
//------------------------------------------------------------------------------------
//string.length() returns the length of a string
//------------------------------------------------------------------------------------
    string first_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    if (first_name.length() > 12) {
        cout << "Your name can't be over 12 characters long";
    }
    else {
        cout << "Welcome " << first_name;
    }

//------------------------------------------------------------------------------------
// string.empty(); returns true if string is empty
//------------------------------------------------------------------------------------
    string first_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    if (first_name.empty()) {
        cout << "You didn't enter a name! >:(";
    }
    else {
        cout << "Welcome " << first_name;
    }
//------------------------------------------------------------------------------------
// string.clear(); clears the contents of a string
//------------------------------------------------------------------------------------
    string first_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    cout << "Welcome " << first_name << endl;

    cout << "*Your name has been cleared*" << endl;

    first_name.clear();

    cout << "Welcome " << first_name << endl;

//------------------------------------------------------------------------------------
// string1.append(string2); adds one string onto another
//------------------------------------------------------------------------------------
    string user_name;

    cout << "Enter your username: ";
    getline(cin, user_name);

    string email = user_name.append("@gmail.com");

    cout << "Your email is now: " << email << endl;

//------------------------------------------------------------------------------------
// string.at(int x); returns character at a given index
//------------------------------------------------------------------------------------
    string first_name;
    string middle_name;
    string last_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);
    cout << "Enter your middle name: ";
    getline(cin, middle_name);
    cout << "Enter your last name: ";
    getline(cin, last_name);

    char letter1 = first_name.at(0);
    char letter2 = middle_name.at(0);
    char letter3 = last_name.at(0);
    cout << "Your initials are: " << letter1 << letter2 << letter3;
//------------------------------------------------------------------------------------
// string1.substr(int x, int y); returns a portion of a string
//------------------------------------------------------------------------------------
    string first_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    string nickname = first_name.substr(0,3);
   
    cout << "Your nickname is: " << nickname << endl;
    cout << "Hello " << nickname;

//------------------------------------------------------------------------------------
// string1.insert(int x,string2); Insert a character within a string at an index
//------------------------------------------------------------------------------------
    string user_name;
    cout << "Enter your user_name: ";
    getline(cin, user_name);

    user_name.insert(0,"@");

    cout << "reply: " << user_name;

//------------------------------------------------------------------------------------
// string1.find(string2); returns position of string2 within string1
//------------------------------------------------------------------------------------
 	string first_name;
    cout << "Enter your first name: ";
    getline(cin, first_name);

    string substring;
    cout << "Search for which character/s?: ";
    getline(cin, substring);

    int position = first_name.find(substring);

    cout << "Found character/s at position: " << position;

//------------------------------------------------------------------------------------
// string1.erase(int x, int y); erases a portion of a string
//------------------------------------------------------------------------------------
    string phone_number;
    cout << "Enter your phone number w/area code: ";
    getline(cin, phone_number);

    phone_number.erase(0, 4);

    cout << "phone number w/o area code: " << phone_number;
    return 0;
}