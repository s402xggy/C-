#include <iostream>
#include <vector>
using namespace std;

/*
    auto和decltype关键字，使用他们可以在编译期就推导出变量或者表达式的类型
    auto:
        1、auto的使用必须马上初始化，否则无法推导出类型
        2、auto在一行定义多个变量时，各个变量的推导不能产生二义性，否则编译失败
        3、auto不能用作函数参数
        4、在类中auto不能用作非静态成员变量
        5、auto不能定义数组，可以定义指针
        6、auto无法推导出模板参数
    decltype：auto用于推导变量类型，而decltype则用于推导表达式类型
        template<typename T, typename U>
        auto add(T t, U u) -> decltype(t + u) {
        return t + u;
}


*/

//  error，auto不能用作函数参数,编译通过，但是会产生编译警告c++ 20引入。
void fun(auto value) {
    cout << "value = " << value << endl;
}

class A{
    // 在类中auto不能用作非静态成员变量
    // auto a = 1;
    // static auto b; 
    static const auto c = 1;
};

void fun2() {
    int a[10] = {0};
    auto b = a;
    // auto不能定义数组，可以定义指针
    // auto c[10] = a;

    vector<int> d;
    // auto无法推导出模板参数
    // vector<auto> f = d;

}

int main() {
    auto a = 10;
    int i = 20;
    auto b = i;
    auto c = 2.0;
    auto &d = a;
    auto *e =  &a;
    // auto在一行定义多个变量时，各个变量的推导不能产生二义性，否则编译失败
    // auto d = 0, f = 1.0;
    // 必须初始化，否则不能完成推导。
    // auto e;

    fun(34);


    return 0;
}