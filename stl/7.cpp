#include <iostream>

using namespace std;

/*
    pair 成对出现，返回两个数据
*/

int main() {
    pair<string, int> p("tom", 45);
    pair<string, int> p1 = make_pair("xgg", 25);

    cout << p.first << " " << p.second << endl;
    cout << p1.first << " " << p1.second << endl;
    return 0;
}