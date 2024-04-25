#include <iostream>
#include <string>
/*
    类对象作为类的成员。
    先调用其他类的构造函数，在调用自己的构造函数。
    析构函数则相反。

*/
using namespace std;
class Phone{
    public:
        Phone(std::string name):phone_name_(name) {
        }

    private:
        std::string phone_name_;
};

class Person{
    public:
        Person(string name, string phone_name): name_(name), phone_(phone_name){

        }

    private:
        std::string name_;
        Phone phone_;
    
        

};



int main() {
    Person p("杨清", "IPHONE_MAX");
}