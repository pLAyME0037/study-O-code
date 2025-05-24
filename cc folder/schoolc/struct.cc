#include <iostream>

using namespace std;

struct Customer
{
    void customer(string name, string id, string product, const char* amount){
        cout <<"Name:"<< name << "ID:" << id << "Product:" << product << "Amount" << amount;
    }
};
struct Prices
{
    void price(string id, string product, int qty, int unitPrice){
        cout << "ID: " << id << "Product: " << product << "QTY: " << qty << "Unit Price: " << unitPrice;

        int total = qty * unitPrice, discount;

        if(total > 100){discount = total * 0.1;}
        else if(total > 50){discount = total * 0.05;}

        int grandTotal = total - discount;
    }
};
int main(){
    Customer detail1;
    Prices detail2;
    detail1.customer("mean", "012", "oranges", "88");
    detail2.price("002", "oranges", 12, 10);
    return 0;
}