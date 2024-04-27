#include <iostream>
#include <vector>
#include <algorithm>
/*
    vector 存储自定义数据类型。
*/
using namespace std;

class Person{
    public:
        Person(string name, int age):name_(name), age_(age) {

        }

        string name_;
        int age_;
};

/*
    容器中嵌套容器

*/
void test1() {
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;

    for (int i = 0; i < 5; i++) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
        v5.push_back(i+5);

    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    for (const auto &vec : v) {
        for (const auto &vec1 : vec) 
            cout << vec1 << " ";
        cout << endl;
    }
}


int main() {
    vector<Person> v;
    Person p1("yq", 11);
    Person p2("yq", 12);
    Person p3("yq", 13);
    Person p4("yq", 14);
    Person p5("yq", 15);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (const auto & begin : v) {
        cout << begin.name_ << " " << begin.age_ << endl;
    }

    test1();
    return 0;
}