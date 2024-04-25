#include <iostream>
using namespace std;

/*
    this 指针的作用：
        1、 解决命名的冲突。
        2、 返回对象本生使用*this

*/

class Person{
    public:
        Person(int age)  {
            // age = age;
            this->age =  age;
        };
        void ShowPerson() {
            cout << "age = " << age << endl;
        }

        Person& AddPerson(const Person &p) {
            this->age += p.age;
            return *this;
        }
    private:
        int age;

};

int main() {
    Person p(10);
    p.ShowPerson();
    Person p1(p);
    p1.AddPerson(p).AddPerson(p);
    p1.ShowPerson();
}