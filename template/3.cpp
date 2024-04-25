#include <iostream>
using namespace std;

/*
    模板的局限性：模板并不是万能的。
        有一些特定的数据类型需要用具体化的方式做特殊的实现。

*/

class Person{
    public:
        string name_;
        int age_;
};

template <class T>
bool Compare(T &a, T &b) {
    if (a == b)
        return true;
    else 
        return false;
}

template<> bool Compare(const Person &a, const Person &b) {
    if (a.name_ == b.name_ && a.age_ == b.age_)
        return true;
    else 
        return false;
}

int main() {
    
    return 0;
}