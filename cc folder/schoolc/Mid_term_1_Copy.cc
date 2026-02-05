#include <iostream>

using namespace std;

int main(){
        cout<<"------------------Carpet type and prices------------------\n";
    cout<<"\t1. Normal        cost: 5.5$ per square meter.\n";
    cout<<"\t2. VIP           cost: 9.5$ per square meter.\n";
    cout<<"\t3. Super VIP     cost: 14.5$ per square meter.\n";
    cout<<"----------------------------------------------------------\n\n";

    int roomSize, type=2;
    double width=21;
    double length=10;
    double cost;
    double pay;

    cout<<"Your Choice(1-3): ";
    //cin>>type;

    cout<<"\n";

    switch (type)
    {
    case 1:
        cout<<"-------------Room Size---------------\n";
        cout<<"\tRoom Length: ";
        cin>>length;
        cout<<"\tRoom Width: ";
        cin>>width;

        roomSize = length * width;
        cost = roomSize * 5.5;

        if(cost<200){
            pay = cost;
        }
        else if(cost>=200 && cost<500){
            pay = cost - (0.05 * cost);
        }
        else if(cost>=500 && cost<800){
            pay = cost - (0.10 * cost);
        }
        else if(cost>800){
            pay = cost - (0.15 * cost);
        }        
        break;

        case 2:
        cout<<"-------------Room Size---------------\n";
        cout<<"\tRoom Length: ";
        //cin>>length;
        cout<<"\tRoom Width: ";
        //cin>>width;

        roomSize = length * width;
        cost = roomSize * 9.5;

        if(cost<200){
            pay = cost;
        }
        else if(cost>=200 && cost<500){
            pay = cost - (0.05 * cost);
        }
        else if(cost>=500 && cost<800){
            pay = cost - (0.10 * cost);
        }
        else if(cost>800){
            pay = cost - (0.15 * cost);
        }        
        break;

        case 3:
        cout<<"-------------Room Size---------------\n";
        cout<<"\tRoom Length: ";
        cin>>length;
        cout<<"\tRoom Width: ";
        cin>>width;

        roomSize = length * width;
        cost = roomSize * 14.5;

        if(cost<200){
            pay = cost;
        }
        else if(cost>=200 && cost<500){
            pay = cost - (0.05 * cost);
        }
        else if(cost>=500 && cost<800){
            pay = cost - (0.10 * cost);
        }
        else if(cost>800){
            pay = cost - (0.15 * cost);
        }        
        break;

    default:
        cout<<"Not an option";
        break;
    }
    /*    
    cout<<"\n1/.Room sq: "<<roomSize<<endl;
    cout<<"2/.Carpet Type: "<<type<<endl;
    cout<<"3/.Cost: ("<<(type == 1 ? 5.5 : type == 2 ? 9.5 : 14.5)<<") $ per sq\n";
    cout<<"4/.Pay: "<<cost<<" $"<<endl;
    cout<<"5/.Discount(%): "<<(cost < 200 ? 0 : cost >= 200 && cost <500 ? 5 : cost >= 500 && cost <800 ? 10 : 15)<<" %\n";
    cout<<"6/.Pay Amount: "<<pay<<" $\n\n";

    cout<<"==============================================================================================================\n";
    cout<<"Room Sq\t\t"<<"Carpet Type\t\t"<<"Cost\t\t"<<"Pay($)\t\t"<<"Discount(%)\t\t"<<"Pay Amount($)\t\t\n\n";

    cout<<roomSize<<" m2\t\t"<<type<<"\t\t\t"<<(type == 1 ? 5.5 : type == 2 ? 9.5 : 14.5)<<"/m2\t\t"<<cost<<" $\t\t"<<
    (cost < 200 ? 0 : cost >= 200 && cost <500 ? 5 : cost >= 500 && cost <800 ? 10 : 15)<<"%"<<"\t\t\t"<<pay<<" $\n";
*/    
    cout<<"==============================================================================================================\n";
    printf("Room Sq\t\tCarpet Type\t\tCost\t\tPay($)\t\tDiscount(%)\t\tPay Amount($)\t\t\n\n");

    printf("%d m2\t\t", roomSize);
    printf("%d\t\t\t", type);
    printf("%.1f/m2\t\t", (type == 1 ? 5.5 : type == 2 ? 9.5 : 14.5));
    printf("%.2f $\t\t",cost);
    printf("%.0f%%\t\t\t", (cost < 200 ? 0 : cost >= 200 && cost < 500 ? 5 : cost >= 500 && cost < 800 ? 10 : 15));
    printf("%.2f $\n", pay);
    
    return 0;
}