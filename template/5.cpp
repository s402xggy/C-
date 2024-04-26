#include <iostream>
using namespace std;

/*
    类模板函数的类外实现：
     
*/
template <class NameType, class AgeType>
class Person1{
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



int main() {
    Person1<string, int> p("小明", 25);
    p.ShowPerson();

    return 0;
}