#include <iostream>
#include <set>
using namespace std;

/*
    set容器排序规则

*/

class MyCompare{
    public:
        bool operator()(int v1, int v2) {
            return v1 > v2;
        }

};

void print_set(const set<int> &s) {
    for (const auto &s1 : s)
        cout << s1 << " ";
    cout << endl;
}

void print_set(const set<int, MyCompare> &s) {
    for (const auto &s1 : s)
        cout << s1 << " ";
    cout << endl;
}


// 自定义数据类型排序；
class Person{
    public:
        Person(string name, int age, int height):name_(name), age_(age), height_(height) 
        {};
        int GetAge() const{
            return age_;
        }
        int GetHeight() const
        {
            return height_;
        }

        string GetName() const{
            return name_;
        }
    private:
        int age_;
        int height_;
        string name_;
};

class ComparePerson{
    public:
        bool operator()(const Person &p1, const Person &p2) {
               if (p1.GetAge() == p2.GetAge() ) 
                    return p1.GetHeight() > p2.GetHeight();
                return p1.GetAge() < p2.GetAge();
        }
};

void PrintCustom(set<Person, ComparePerson> p) {
    for (const auto &pi : p)
        cout << pi.GetName() << " " << pi.GetAge() << " " << pi.GetHeight() << endl;
}

int main() {
    set<int> s1;
    s1.insert(12);
    s1.insert(2);
    s1.insert(9);
    s1.insert(4);
    print_set(s1);

    set<int, MyCompare> s2;
    s2.insert(12);
    s2.insert(2);
    s2.insert(9);
    s2.insert(4);
    print_set(s2);

    set<Person, ComparePerson> s3;
    Person p1("a", 23, 185);
    Person p2("b", 23, 188);
    Person p3("c", 24, 185);
    Person p4("d", 1, 50);
    Person p5("e", 8, 135);
    Person p6("f", 18, 176);
    Person p7("g", 34, 168);
    Person p8("h", 6, 110);
    Person p9("i", 47, 165);
    Person p10("j", 14, 158);
    Person p0("k", 29, 159);

    s3.insert(p0);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    s3.insert(p5);
    s3.insert(p6);
    s3.insert(p7);
    s3.insert(p8);
    s3.insert(p9);
    s3.insert(p10);
    PrintCustom(s3);

    return 0;
}
