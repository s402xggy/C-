#include <iostream>

using namespace std;

/*
    子类和父类同名对象处理。
    如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中的所有同名函数。
    如果想要访问父类中的同名函数，需要使用作用于运算符。


*/
class Base{
    public:
        Base(int age): age_(age){};
    private: 
        int age_;
};

class Child:public Base{
    public: 
     Child(int age):Base(age + 10), age_(age) {}; 
     void ShowChild() {
        // cout << "base age = " << thisBase::age_ << std::endl;
        cout << "child age = " << age_ << std::endl;
     }
    private:
        int age_;
};

class Animal{
    public:
        int age_;

};

class Sheep:virtual public Animal{

};

class Dog:virtual public Animal{


};

// 菱形继承
/*
    菱形继承导致pig中右两份age_数据, 造成资源浪费。
    使用虚继承解决菱形继承的资源浪费。 此时公共的基类叫做虚基类。
*/
class Pig: public Sheep, public Dog{

};


int main() {



    return 0;
}