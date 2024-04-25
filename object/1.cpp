#include <iostream>
using namespace std;

const double PI = 3.1415926;
class Circle {
    public:
        int m_r_;
        double CalculateZC() {
            return 2 * PI * m_r_;
        }
};

class Student{

    private: 
        string name_;
        string id_;
    public:
        void SetName(string name) {
            name_ = name;
        }
        void SetId(string id) {
            id_ = id;
        }
        void ShowStudent() {
            cout << "name = " << name_ << endl;
            cout << "id = " << id_ << endl;
        }

};

int main() {

    Circle c1;
    c1.m_r_ = 10;
    cout << "圆的周长为 = " << c1.CalculateZC() << endl;
    Student s1;
    s1.SetName("杨清");
    s1.SetId("20000809");
    s1.ShowStudent();

}