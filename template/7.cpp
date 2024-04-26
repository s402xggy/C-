#include <iostream>
using namespace std;

/*
    类模板与友元：
     
*/

// 通过全局函数 打印Person1的消息。
template <class NameType, class AgeType>
class Person1{
    // 全局函数类内实现
    friend void PrintPerson1(Person1<NameType, AgeType> p){
        cout << "name = " << name_ << " age = " << age_ << endl;
    }
    friend void PrintPerson2<>(Person1<NameType, AgeType> p);

    public:
        Person1(NameType name, AgeType age);
        void ShowPerson();


    private:
        NameType name_;
        AgeType age_;
};

template <class NameType, class AgeType>
Person1<NameType, AgeType>::Person1(NameType name, AgeType age):name_(name), age_(age){};

template <class NameType, class AgeType>
void Person1<NameType, AgeType>::ShowPerson() {
    cout << "name = " << name_ << " age = " << age_ << endl;
}

// 全局函数友元类外实现
template <class NameType, class AgeType>
void PrintPerson2(Person1<NameType, AgeType> p){
    cout << "name = " << name_ << " age = " << age_ << endl;

}


int main() {
    Person1<string, int> p("小明", 25);
    p.ShowPerson();

    return 0;
}