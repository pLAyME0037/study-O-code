#include <iostream>
using namespace std;

double get_price() {
    double price;
    cout << "Enter the original price: ";
    cin >> price;
    return price;
}

double calculate_discount_percentage(double price) {
    if (price > 500) {
        return 50;
    }
    else if (price > 400)
    {
        return 40;
    }
    else if (price > 300)
    {
        return 30;
    }
    else if (price > 200)
    {
        return 20;
    }
    else if (price > 100)
    {
        return 10;
    }
    else {
        return 0;
    }
}

double calculate_price(double discount_percentage, double price) {
    return price * (1 - discount_percentage / 100.0);
}

int display_results(double discount_percentage, double final_price) {
    cout << "You have been given a " << discount_percentage << "% discount!" << endl;
    cout << "The final price is: $" << final_price << endl;
}

int main() {
    double price = get_price();
    double discount_percentage = calculate_discount_percentage(price);
    double final_price = calculate_price(discount_percentage, price);
    
    display_results(discount_percentage, final_price);
    
    return 0;
}
