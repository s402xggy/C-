#include <iostream>
using namespace std;
/*
    虚析构和纯虚析构：
        父类指针在析构的时候，不会调用子类的析构函数，导致子类如果的堆类属性，将无法释放堆类数据。
        利用虚析构可以解决父类指针释放子类对象时不干净的问题。
        虚析构和纯虚构都是需要去 实现的。
        拥有纯虚析构的类也是抽象类。
*/

class Animal{
    public:
        Animal(){
            cout << "动物的构造函数！！！" << endl;

        };
        virtual ~Animal() = 0;
        virtual void Speak() = 0;
    private:

};


Animal::~Animal() {
    cout << "动物的析构函数！！！" << endl;
}

class Cat: public Animal{
    public: 
        Cat(string name) {
            name_ = new string(name);
            cout << "小猫的构造函数！！！" << endl;
        }
        ~Cat() {
            if (name_ != nullptr) {
                delete name_;
                name_ = nullptr;
            }
            cout << "小猫的析构函数！！！" << endl;

        }
        void Speak() {
            cout << "小猫在说话！！！" << endl;
        }
    private:
        string *name_;
};

class Dog: public Animal{
    public: 
        void Speak() {
            cout << "小狗在说话！！！" << endl;
        }
};


void DoSpeak(Animal &animal) {
    animal.Speak();
}




int main() {
    Animal *animal = new Cat("gg");
    // Dog dog;
    // DoSpeak(cat);
    // DoSpeak(dog);
    animal->Speak();
    delete animal;

    return 0;
}