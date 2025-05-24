#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;
    string name;

  public:
    void setSalary(int s) {
      salary = s;
    }
    void setName(string n) {
      name = n;
    }
    int getSalary() {
      return salary;
    }
    string getName() {
      return name;
    }
};

int main() {
  Employee myObj;
  myObj.setSalary(50000);
  myObj.setName("mean");
  cout << myObj.getSalary() << endl;
  cout << myObj.getName() << endl;
  
    Employee myObj2;
  myObj2.setSalary(40000);
  myObj2.setName("MEAN");
  cout << myObj2.getSalary() << endl;
  cout << myObj2.getName() << endl;
  return 0;
}
