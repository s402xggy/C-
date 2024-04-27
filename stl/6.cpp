#include <iostream>
#include <set>

using namespace std;
/*
    关联式容器，底层实现为二叉树。
    set：不允许重复元素
    /multi_set：允许重复元素

    1、插入数据只有insert方式。
    2、find(key) 若存在，则返回该元素位置的迭代器， 不存在返回set.end();
        count(key) 统计key的个数。
*/

void print_set(const set<int> &s) {
    for (const auto &s1 : s)
        cout << s1 << " ";
    cout << endl;
}

int main() {
    set<int> s1;
    s1.insert(23);
    s1.insert(21);
    s1.insert(16);
    s1.insert(9);

    // 插入元素时会被自动排序， 并且不允许插入重复值。
    print_set(s1);
    s1.insert(9);
    print_set(s1);

    set<int> s2 = s1;
    print_set(s2);

    set<int> s3(s2);
    print_set(s3);

    auto it = s3.find(34);
    if (it != s3.end())
        cout << "找到该元素" << endl;
    else 
        cout << "未找到该元素" << endl;

    return 0;
}