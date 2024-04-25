#include <iostream>
using namespace std;

/*
    普通函数与函数模板的调用规则
    1、普通函数和模板函数都能实现时，优先调用普通函数。
    2、可以通过空模板参数列表 强制调用函数模板。
    3、函数模板可以重载。
    4、如果函数模板可以参生更好的匹配，优先调用函数模板。
*/

void MyPrint(int a, int b) {
    cout << "调用的普通函数" << endl;
}

template <class T> 
void MyPrint(T a, T b) {
    cout << "调用的模板" << endl;
}

template <class T> 
void MyPrint(T a, T b, T c) {
    cout << "调用的重载模板" << endl;
}

int main() {
    MyPrint(10, 30);
    MyPrint<>(30, 49);
    MyPrint(10, 20, 30);
    MyPrint('A', 'B');
    return 0;
}