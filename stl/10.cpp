#include <iostream>
using namespace std;

/*
    函数对象：
        是类中重载的函数运算符（）,可以像函数一样使用对象。
        1、可以有参数，有返回值。
        2、可以有自己的状态，
        3、函数对象可以作为参数传递。

*/

class MyAdd{
    public:
        bool operator()(int v1, int v2) {
            return v1 + v2;
        }

};

// 2、可以有自己的状态，
class MyPrint{
    void operator()(string str) {
        cout << str << endl;
    }
};

int main() {


    return 0;
}