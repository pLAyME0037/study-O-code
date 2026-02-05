#include <iostream>

using namespace std;

int main(){
        cout<<"------------------Carpet type and prices------------------\n";
    cout<<"\t1. Normal        cost: 5.5$ per square meter.\n";
    cout<<"\t2. VIP           cost: 9.5$ per square meter.\n";
    cout<<"\t3. Super VIP     cost: 14.5$ per square meter.\n";
    cout<<"----------------------------------------------------------\n\n";

    int type;
    double width;
    double length;
    double roomSize;
    double cost;
    double pay;

    cout<<"Your Choice(1-3): ";
    cin>>type;

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

        cout<<"Room sq: "<<roomSize<<endl;
        cout<<"Carpet Type: "<<type<<endl;
        cout<<"Cost: 5.5 $\n";
        cout<<"Pay: "<<cost<<" $"<<endl;

        if(cost<200){
            cout<<"Discount: 0%\n";
            pay = cost;
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=200 && cost<500){
            cout<<"Discount: 5%\n";
            pay = cost - (0.05 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=500 && cost<800){
            cout<<"Discount: 10%\n";
            pay = cost - (0.10 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>800){
            cout<<"Discount: 15%\n";
            pay = cost - (0.15 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }        
        break;

        case 2:
        cout<<"-------------Room Size---------------\n";
        cout<<"\tRoom Length: ";
        cin>>length;
        cout<<"\tRoom Width: ";
        cin>>width;

        roomSize = length * width;
        cost = roomSize * 9.5;

        cout<<"Room sq: "<<roomSize<<endl;
        cout<<"Carpet Type: "<<type<<endl;
        cout<<"Cost: 9.5 $\n";
        cout<<"Pay: "<<cost<<" $"<<endl;

        if(cost<200){
            cout<<"Discount: 0%\n";
            pay = cost;
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=200 && cost<500){
            cout<<"Discount: 5%\n";
            pay = cost - (0.05 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=500 && cost<800){
            cout<<"Discount: 10%\n";
            pay = cost - (0.10 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>800){
            cout<<"Discount: 15%\n";
            pay = cost - (0.15 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }        
        break;

        case 3:
        cout<<"-------------Room Size---------------\n";
        cout<<"\tRoom Length: ";
        cin>>length;
        cout<<"\tRoom Width: \n";
        cin>>width;

        roomSize = length * width;
        cost = roomSize * 14.5;

        cout<<"Room sq: "<<roomSize<<endl;
        cout<<"Carpet Type: "<<type<<endl;
        cout<<"Cost: 14.5 $\n";
        cout<<"Pay: "<<cost<<" $"<<endl;

        if(cost<200){
            cout<<"Discount: 0%\n";
            pay = cost;
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=200 && cost<500){
            cout<<"Discount: 5%\n";
            pay = cost - (0.05 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>=500 && cost<800){
            cout<<"Discount: 10%\n";
            pay = cost - (0.10 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }
        else if(cost>800){
            cout<<"Discount: 15%\n";
            pay = cost - (0.15 * cost);
            cout<<"Pay Amount($): "<<pay<<" $"<<endl;
        }    
        break;

    default:
        cout<<"Not an option";
        break;
    }

    return 0;
}