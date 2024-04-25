#include <iostream> 
#include <climits>

using namespace std;

int main() {
    // 数据类型
    cout << "int is " << sizeof(int) << " bytes. \n";
    cout << "short is " << sizeof(short) << " bytes. \n";
    cout << "char is " << sizeof(char) << " bytes. \n";
    cout << "long is " << sizeof(long) << " bytes. \n";
    cout << "long long is " << sizeof(long long) << " bytes. \n";
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "INT_MIN = " << INT_MIN << endl;

    // 关键字 const
    int temp = 10;
    int temp2 = 3; 
    // 两种情况相同，都表示指针指向的内容不可更改。
    const int * a = &temp;
    int const * b = &temp2;
    a = &temp2;
    // *a = 20;
    // *b = 20;

    // 指针本身不可更改指向的对象.
    int * const c = &temp2;
    // c = &temp;s



    return 0;
}