#include <iostream>
#include <list>


using namespace std;

/*
    list 构造函数


*/

void PrintList(const list<int> &lst) {
    for (const auto &ls : lst)
        cout << ls << " ";
    cout << endl;
}

bool compare(int v1, int v2) {
    return v1 > v2;
}

/*
自定义数据排序
    按照年龄进行排序，如果年龄相同，则按升高降序排序
*/

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

bool custom_compare(Person &p1, Person &p2) {
    if (p1.GetAge() == p2.GetAge() ) 
        return p1.GetHeight() > p2.GetHeight();
    return p1.GetAge() < p2.GetAge();
    
}

void PrintCustom(list<Person> p) {
    for (const auto &pi : p)
        cout << pi.GetName() << " " << pi.GetAge() << " " << pi.GetHeight() << endl;
}


int main() {

    list<int> l1;
    l1.push_back(12);
    l1.push_back(17);
    l1.push_back(2);
    l1.push_back(29);
    l1.push_back(8);
    PrintList(l1);
    list<int> l2(l1);
    PrintList(l2);
    list<int> l3(l2.begin(), l2.end());
    PrintList(l3);
    // 所有不支持随机访问迭代器的容器，不可以使用标准算法。 sort();
    l3.reverse();
    PrintList(l3);
    l3.sort();
    PrintList(l3);
    l3.sort(compare);
    PrintList(l3);


    list<Person> l;
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
    l.push_back(p0);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    l.push_back(p7);
    l.push_back(p8);
    l.push_back(p9);
    l.push_back(p10);

    l.sort(custom_compare);
    PrintCustom(l);


    return 0;
}