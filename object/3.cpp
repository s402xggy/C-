#include <iostream>
/*
    构造函数： 用于类成员的初始化。
        分为有参构造和无参构造。
        普通构造和拷贝构造 
    析构函数： 进行清理操作
    
    特点：
        默认情况下，c++ 编译器将提供三个函数
        默认构造函数。
        默认析构函数。
        默认拷贝构造函数（对属性进行值拷贝）
        
        当自己写了构造函数后，系统将不再提供默认构造函数。但会提供默认拷贝函数。
        当写了拷贝构造函数， 系统将不在提供其他构造函数。
*/

using namespace std;
class Person{
    public:
        Person(){
            cout << "Person 无参构造函数的调用！！！" << endl;
        }
        Person(int a) {
            age_ = a;
            cout << "Person 有参构造函数的调用！！！" << endl;
 
        }
        ~Person() {
            cout << "Person 析构函数的调用！！！" << endl;
        }
        Person(const Person &p) {
            this->age_ = p.age_;
            cout << "Person 拷贝构造函数的调用！！！" << endl;

        }
    private:
        int age_;
};


int main() {
    Person p1;
    Person p2(10);
    Person p3(p2);

    return 0;
}