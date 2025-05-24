#include <iostream>

using namespace std;

void customer(string id, string name, char gender, string place, const char* phNum){
    cout << "==================================================Customers=====================================================\n";
    cout << "Customer ID:" << id <<"\tCustomer Name:"<< name << "\tGender:" << gender << "\tDate of Place" << place << "\tPhone Number" << phNum;
}
void product(string id, string product,string date, int qty, int unitPrice){
    cout << "\n==================================================Products======================================================\n";
    cout << "Product ID:" << id << "\tProduct Name:" << product << "\tDate:" << date << "\tQTY:" << qty << "\tUnit Price($):" << unitPrice;
    
    int total = qty * unitPrice, discount;

    cout << "\n==================================================Amount========================================================\n";
    cout << "Amount: " << total;

    if(total >= 2000){discount = total * 0.15;}
    else if(total >= 1000){discount = total * 0.1;}
    else if(total >= 700){discount = total * 0.05;}
    else if(total >= 1000){discount = total * 0.03;}

    int grandTotal = total - discount;
    
    cout << "\n==================================================Payments======================================================\n";  
    cout << "Discount: " << discount << "\n";
    cout << "Payment: " << grandTotal;
}

int main(){
    customer("Cus_001", "Sok chana", 'F', "Kandal", "099 567 666");
    product("Pro_101", "Vga", "10-03-25", 45, 100);
    return 0;
}