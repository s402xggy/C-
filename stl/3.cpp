#include <iostream>
#include <vector>

using namespace std;

/*
   1、 vector 容器构造函数
    vector<T> v;
    vector<T> v(v1.begin(), v1.end());
    vector<T> v(n, elem);
    vector<T> v(v2);
*/

void PrintVector(const vector<int> &v) {
    for (const auto &it : v)
        cout << it << " ";
    cout << endl;
}

/*
   2、 vector 的赋值方式
    vector & operator=(const vector &vec);
    assign(beg, end);
    assign(n, elem);

*/

/*
    3、vector 容器的容量和大小
    v.empty();
    v.size();
    v.capacity();
    v.resize(int n);
    v.resize(int n, elem);

*/

/*
    4.vector插入和删除
    push_back()
    pop_back();
    insert(const_iterator pos, ele);
    insert(const_iterator pos,int count, ele);
    erase(const_iterator pos);
    erase(const_iterator start, const_iterator end);
    clear();
*/

/*
    5、 vector 互换容器
    swap(v1, v2);
    用途：
        可以收缩内存空间
*/

/*
    6、预留空间
    reserve(int len); 预留位置不初始化，不能访问该空间。

*/


int main() {

    // 1、vector 容器构造函数
    vector<int> v;
    for (int i = 0; i < 10; i++) 
        v.push_back(i);
    PrintVector(v);

    vector<int> v2(v.begin(), v.end());
    PrintVector(v2);

    vector<int> v3(10, 6);
    PrintVector(v3);

    vector<int> v4(v3);
    PrintVector(v4);

    // 2、vector 的赋值方式
    vector<int> v5;
    v5 = v;
    PrintVector(v5);

    vector<int> v6;
    v6.assign(v5.begin(), v5.end());
    PrintVector(v6);
    
    vector<int> v7;
    v7.assign(10, 100);
    PrintVector(v7);

    // 5、 vector 互换容器
    swap(v, v3);
    PrintVector(v);
    PrintVector(v3);

    // 6、预留空间
    vector<int> v8;
    v8.reserve(100000);
    int num = 0;
    int *p = nullptr;
    for (int i = 0; i < 100000; i++) {
        v8.push_back(i);
        if (p != &v8[0]) {
            p = &v8[0];
            num++;
        }
    }
    cout << "num = " << num << endl;


    return 0;
}