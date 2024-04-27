#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
    deuqe:
        双端数组。
        可以对头部进行插入和删除。
        头部尾部插入数据快。
        访问数据没有vector速度快。
    1、构造函数

    2、赋值操作
        operator=
        dq.assign(d1.begin(), d1.end())
        d1.assign(int n, elem);

    3、deque大小的操作。
    deque.empty()
    deque.resize(int);
    deque.resize(int n, elem);

    4、插入删除
    push_back();
    push_front();
    pop_back();
    pop_front();

    指定位置插入删除
    insert（const_iteror pos, val）；
    insert（const_iteror pos,int n,  val）；
    insert（const_iteror pos1, const_iteror pos2, val）；

    5、deuqe排序
    sort(iterator 1, iterator 2)；


*/

void PrintDeque(const std::deque<int> &dq) {
    for (const auto & begin : dq) 
        cout << begin << " ";
    cout << endl;
}


int main() {

    // 1、构造函数
    deque<int> d1;
    for (int i = 0; i < 10; i++) 
        d1.push_back(i);
    PrintDeque(d1);
    deque<int> d2(d1.begin(), d1.end());
    PrintDeque(d2);

    deque<int> d3(10, 100);
    PrintDeque(d3);

    deque<int> d4(d2);
    PrintDeque(d4);

    // 2、赋值操作。
    deque<int> d5;
    d5 = d4;
    PrintDeque(d4);

    deque<int> d6;
    d6.assign(d5.begin(), d5.end());
    PrintDeque(d4);

    deque<int> d7;
    d7.assign(10, 66);
    PrintDeque(d7);

//   5、deuqe排序
    sort(d1.begin(), d1.end());
    PrintDeque(d1);

    return 0;
}