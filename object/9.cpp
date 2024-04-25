#include <iostream>
using namespace std;

/*
    加号运算符重载
        全局函数重载
        成员函数重载。

*/

class Person{
    // 不加友元则需要成员变量为public
    friend Person operator+(const Person &p1, const Person &p2);
    friend Person operator+(const Person &p1, int n);
    friend ostream& operator<<(ostream & os, const Person &p);
    public:
    Person(){};
    Person(int age, int phone): age_(age), phone_(phone) { };
    void ShowPerson() {
        std::cout << "age = " << age_ << " phone_ = " << phone_ << endl;
    }
    // 成员函数重载。
    // Person operator+(const Person & p) {
    //     Person p2;
    //     p2.age_ = p.age_ + this->age_;
    //     p2.phone_ = this->phone_ + p.phone_;
    //     return p2;
    // }

    // 一般不会使用成员函数重载<< 运算符，因为无法实现 cout 在左侧。
    // ostream & operator<<(cout) {
    //     std::ostream os;
    //     os << p.age_ << " " << p.phone_ << endl;
    //     return os;
    // }

    private:
        int age_;
        int phone_;

};
//     全局函数重载
Person operator+(const Person &p1, const Person &p2) {
    Person temp;
    temp.age_ = p1.age_ + p2.age_;
    temp.phone_ = p1.phone_ + p2.phone_;    
    return temp;
}

//     全局函数重载版本
Person operator+(const Person &p1, int n) {
    Person temp;
    temp.age_ = p1.age_ + n;
    temp.phone_ = p1.phone_ + n;    
    return temp;
}

/*
    左移运算符重载， 可以输出自定义数据类型

*/

ostream& operator<<(ostream &os, const Person &p) {
    os << p.age_ << " " << p.phone_;
    return os;
}


/*
    递增运算符重载。
*/

class MyInteger{
    friend ostream& operator<<(ostream &os, const MyInteger &p);
    public:
        MyInteger(){
            num_ = 0;
        }   
    // 重载前置++运算符
    MyInteger & operator++() {
        num_++;
        return *this;
    }
    // 重载后置++运算符
    MyInteger operator++(int){ // 其中int 为占位
        MyInteger temp = *this;
        num_++;
        return temp;
    }


    private: 
        int num_;
};


ostream& operator<<(ostream &os, const MyInteger &p) {
    os << p.num_;
    return os;
}

/*
    c++编译器至少给一个类添加4个函数
        默认构造函数。
        默认析构函数。
        默认拷贝构造函数（对属性进行值拷贝）
        赋值运算符operator=对属性进行拷贝。

*/

/*
    赋值运算符重载
*/

class People{
    public:
        People() {
            age_ = new int(0);
        }
        People(int n) {
            age_ = new int(n);
        }
        // 赋值运算符重载
        People &operator=(const People &p) {
            if (age_ != nullptr) {
                delete age_;
                age_ = nullptr;
            }
                age_ = new int(*p.age_);
            return *this;
        }

        ~People() {
            if (age_ != nullptr) {
                delete age_;
                age_ = nullptr;
            }
        }
    private:
        int *age_;
};

/*
    关系运算符重载
*/

class People1{
    public: 
        People1(std::string name, int age):name_(name), age_(age){};
        bool operator==(const People1 &p){
            return (this->name_ == p.name_ && this->age_ == p.age_);
        }

        bool operator!=(const People1 &p){
            return (this->name_ != p.name_ || this->age_ != p.age_);
        }

    private:
        std::string name_;
        int age_;
};

/*
    仿函数：
        重载函数调用运算符（）
*/

class MyPrint {

    public:
        void operator()(string str) {
            cout << str << endl;
        }
};


int main() {
    Person p1(10, 10);
    Person p2(10, 20);
    Person p3 = p1 + p2;
    Person p4 = p1 + 50;
    p3.ShowPerson();
    p4.ShowPerson();

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p4 << endl;

    MyInteger my_integr;
    cout << "my_inter " << ++(++my_integr) << endl;
    cout << "my_inter " << (my_integr++) << endl;
    cout << "my_inter " << my_integr << endl;
    

    People p5(20);

    People1 p6("杨清", 20);
    People1 p7("杨清", 29);
    if (p6 == p7) 
        cout << "两个人为同一个" << endl;
    else 
        cout << "两个人不是同一个人" << endl;
    MyPrint myprint;
    myprint("Hello World!!!");
    
    return 0;
}
