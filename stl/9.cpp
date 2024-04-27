#include <iostream>
#include <map>
using namespace std;

/*
    map和multimap
        底层实现仍然为二叉树
        map中的每一个元素为pair
        map会按照key的值排序。
        map中不允许有重复的key
*/


/*
    map容器中的排序

*/
class MyCompare{
    public:
        bool operator()(int v1, int v2) {
            return v1 < v2;
        }

};

void PrintCustom(map<int, int, MyCompare> p) {
    for (const auto &pi : p)
        // cout << pi.GetName() << " " << pi.GetAge() << " " << pi.GetHeight() << endl;
        cout << "first = " << pi.first << " " "second = " << pi.second << endl;
}


int main() {
    map<int, int, MyCompare> m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(10,10));
    m.insert(make_pair(9,10));
    m.insert(make_pair(8,10));
    m.insert(make_pair(7,10));
    m.insert(make_pair(6,10));
    PrintCustom(m);


    return 0;
}