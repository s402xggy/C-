#include <iostream>
using namespace std;

// 访问权限
/*
    public :    成员 类中可以访问 类外可以访问 
    protected:  成员 类中可以访问 类外不可以访问  儿子可以访问父亲中的保护成员
    private:    成员 类中可以访问 类外不可以访问  儿子不可以访问父亲中的私有成员

*/
class Person {
    public:
        string name_;
    protected:
        string car_;
    private:
        string password_;
    private: 
        void ShowPerson1(){
            cout << "name = " << name_ << endl;
            cout << "car = " << car_ << endl;
            cout << "password = " << password_ << endl;
        }
    public: 
        void ShowPerson2(){
            cout << "name = " << name_ << endl;
            cout << "car = " << car_ << endl;
            cout << "password = " << password_ << endl;
        }


};



int main() {
    Person p1;
    p1.name_ = "杨清";
    // 无法访问；
    // p1.car_ = "M5";
    // p1.password_ = "2000";
    // p1.ShowPerson1();
    p1.ShowPerson2();

    return 0;
}