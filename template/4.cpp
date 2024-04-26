#include <iostream>
using namespace std;

/*
    类模板：
        特点： 类模板没有自动类型推导的使用方式
              类模板在模板参数列表中可以有默认参数。
*/
template <class NameType, class AgeType>
class Person1{
    public:
        Person1(NameType name, AgeType age):name_(name), age_(age){};
        void ShowPerson() {
            cout << "name = " << name_ << " age = " << age_ << endl;
        }

    private:
        NameType name_;
        AgeType age_;
};

// 类模板在模板参数列表中可以有默认参数。
template <class NameType, class AgeType=int>
class Person2{
    public:
        Person2(NameType name, AgeType age):name_(name), age_(age){};
        void ShowPerson() {
            cout << "name = " << name_ << " age = " << age_ << endl;
        }

    private:
        NameType name_;
        AgeType age_;
};


/*
    类模板函数的创建时机：
        普通类函数在一开始就创建。
        类模板函数只有在调用时才创建，因为无法确定数据类型。

*/

/*
    类模板对象作为函数参数。
        1、指定传入的类型。 -- 直接显示对象的数据类型
        2、参数模板化       -- 将对象中的参数变为模板进行传递
        3、整个类模板化     -- 将这个对象类型 模板化进行传递。


*/

template <class T1, class T2>
class Person3{
    public:
        Person3(T1 name, T2 age):name_(name), age_(age) {};
        void ShowPerson() {
            cout << "name = " << name_ << " age = " << age_ << endl;
        }
    private:
        T1 name_;
        T2 age_;

};
//  1、指定传入的类型。 -- 直接显示对象的数据类型
void PrintPerson(Person3<string, int> &p){
    p.ShowPerson();
}
// 2、参数模板化       -- 将对象中的参数变为模板进行传递
template <class T1, class T2>
void PrintPerson(Person3<T1, T2> &p){
    p.ShowPerson();
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}
// 3、整个类模板化     -- 将这个对象类型 模板化进行传递。
template <class T>
void PrintPerson(T &p){
    p.ShowPerson();
    cout << typeid(T).name() << endl;
}


/*
    类模板与继承：
        必须直到父类中T的类型， 才能继承给子类。
        如果相灵活的指定父类中T的类型， 子类也需要变为类模板。

*/

template <class T>
class Base{
    T m;
};

class Son:public Base<int>{

};

template <class T, class T2>
class Son2:public Base<T2>{
    T name;
};



int main() {
    Person1<string, int> p("小明", 25);
    // 无法自动推导
    // Person1 p1("11",23);
    p.ShowPerson();
    Person2<string> p2("肖佳佳", 25);
    p2.ShowPerson();

    Person3<string, int> p3("小王", 1);
    PrintPerson(p3);

    return 0;
}