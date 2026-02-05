#include <iostream>
    
using namespace std;

struct Student{
    void student(string id, string name, const char* gender, int age, string place, string phNum, string email){
        cout << "=========================================Student==============================================\n";
        cout << "StuID:" << id << "Name:" << name << "Gender:" << gender << "Age:" << age << "Date of Place:" << place << "\nPhone Number:" << phNum << "E-Mail:" << email;
    }
};
struct Class{
    void class_1(string id, string name, string year){
        cout << "\n=========================================Class================================================\n";
        cout << "ClassID:" << id << "Class Name:" << name << "Year:" << year;
    }
};
struct Score{
    void score(int studentScore, string studentName){
        cout << "\n=========================================Grade================================================\n";

        if (studentScore >= 90) {
                std::cout << studentName << "'s grade: A" << std::endl;
              } else if (studentScore >= 80) {
                std::cout << studentName << "'s grade: B" << std::endl;
              } else if (studentScore >= 70) {
                std::cout << studentName << "'s grade: C" << std::endl;
              } else if (studentScore >= 60) {
                std::cout << studentName << "'s grade: D" << std::endl;
              } else {
                std::cout << studentName << "'s grade: F" << std::endl;
              }
    }
};
int main()
{
    

	Student detail1;
    Class detail2;
    Score detail3;

    detail1.student("001", "Sok Channy", "Female", 19, "Kartie", "017 354 786", "sokchanny@email.com");
    detail2.class_1("Calss_002", "M29", "Y2");
    detail3.score(58, "Sok Channy");
	
    return 0;
}