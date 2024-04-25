#include <iostream>
/*
    成员变量和成员函数分开存储的。
    c++编译器会给每个空对象也分配一个字节空间，这是为了区分空对象占内存的位置。
    每个空对象也应该有一个独一无二的位置。
*/
using namespace std;
class Person1{


};

class Person2{
    int name;
    static int age_;           // 不属于某一个类的对象。

    void func() {};             // 不属于某一个类的对象。
    
    static void func2() {};     // 不属于某一个类的对象。
};

int Person2::age_ = 10;

int main() {

    Person1 p;
    cout << "size of p = " << sizeof(p) << endl;

    Person2 p1;
    cout << "size of p1 = " << sizeof(p1) << endl;


    return 0;
}