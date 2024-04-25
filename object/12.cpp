#include <iostream>
using namespace std;
/*
    多态：
        静态多态：函数重载和运算符重载。
        动态多态：派生类和虚函数实现运行时多态。
    
        区别：
        静态多态：在编译阶段确定函数地址。
        动态多态：在运行时确定函数地址。

    动态多态满足条件：
        1. 需要右继承。
        2. 子类需要重写父类的虚函数（重写 函数的返回值， 函数名， 参数列表， 完全相同）
    
    动态多态的使用：
        1.父类的指针或引用指向子类对象。
*/

class Animal{
    public:
        Animal(){};
        virtual void Speak() {
            cout << "动物在说话！！！" << endl;
        }
    private:

};

class Cat: public Animal{
    public: 
        void Speak() {
            cout << "小猫在说话！！！" << endl;
        }
};

class Dog: public Animal{
    public: 
        void Speak() {
            cout << "小狗在说话！！！" << endl;
        }
};

// 地址早绑定。
// 如果相执行猫说话，不能让其早绑定。
void DoSpeak(Animal &animal) {
    animal.Speak();
}




int main() {
    Cat cat;
    Dog dog;
    DoSpeak(cat);
    DoSpeak(dog);


    return 0;
}