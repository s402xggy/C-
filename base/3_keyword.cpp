#include <iostream>
using namespace std;


class ExampleClass {
    public:
        // 静态成员函数
        static void StaticFunction() {
            cout << "static function!!!" << endl;
        }
        // 静态成员变量
        // static int static_var = 10; //不可以在类中定义，只能在类外定义
        static int static_var; // 可以声明。
        const static int static_var_1 = 10; // 常亮静态变量可以类中定义。
};

class Age{
    public:
        Age & operator++() {
	        ++i;   
	        return *this;   
        }
        const Age operator++(int) {
            Age temp = *this;
            ++(*this);
            return temp;
        }
        
    
    private:
        int i;
};

int ExampleClass::static_var = 10; // 类外定义

int main() {

    // 关键字 static 
    static int count;
    cout << "count = " << count << endl; // 对于基本数据类型，默认赋值为0；
    ExampleClass::StaticFunction();


    return 0;
}