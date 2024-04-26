#include <iostream>
#include <vector>
#include <algorithm>
/*
    容器：
        序列式容器
        关联式容器。
    算法：
        质变算法：元素的拷贝、删除、替换
        非质变算法：不会修改容器中元素，如查找最大值。

    案列：
        容器：vector
        算法：for_each
        迭代器：vector<int>::interator.
*/
using namespace std;


int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(12);
    v.push_back(32);
    v.push_back(2);
    v.push_back(9);
    v.push_back(77);

    // 指向第一个元素的位置。
    vector<int>::iterator it_begin = v.begin();
    // 指向容器最后一个元素的下一个位置
    auto it_end = v.end();

    while(it_begin != it_end) {
        cout << *it_begin << " ";
        it_begin++;
    }
    cout << endl;
    for (const auto &begin : v)
        cout  << begin << " ";
    cout << endl;
    

    return 0;
}