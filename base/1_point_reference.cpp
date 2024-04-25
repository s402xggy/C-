#include <iostream>

// 指针： 通常⽤于动态内存分配、数组操作以及函数参数传递。
// 引⽤： 通常⽤于函数参数传递、操作符重载以及创建别名。

using namespace std;
int main() {
    // 地址
    int x = 10;
    int *ptr = &x;
    
    cout << "x = " << x << endl;
    cout << "x address = " << &x << endl;
    cout << "ptr = " << ptr << endl;
    cout << "ptr address = " << &ptr << endl;

    // 引用
    int y = 20;
    int &ref = y;

    cout << "y = " << y << endl;
    cout << "ref = " << ref << endl;
    cout << "y address = " << &y << endl;
    cout << "ref address = " << &ref << endl;

    
    ref = x; // 无效， ref 仍然指向y;
    cout << "x address = " << &x << endl;
    cout << "ref address = " << &ref << endl;
    return 0;
}