#include <iostream>

/*
    浅拷贝：带来的问题是，堆区内存的重复释放。


*/
using namespace std;
class Person{
    public:
        Person() {
            cout << "person 的默认构造函数" << endl;
        }
        Person(int age, int height):age_(age) {
            height_ = new int(height);
            cout << "person 的有参构造函数" << endl;
        }
        Person(const Person &p):age_(p.age_) {
            // height_ = p.height_   浅拷贝，编译器默认的操作。
            this->height_ = new int(*p.height_);
        }
        ~Person() { 
            if (height_ != nullptr) {
                delete height_;
                height_ = nullptr;
            }
            cout << "person 的默认析构函数" << endl;
        }


        void ShowPerson() {
            cout << "age = " << age_ << " height = " << *height_ << endl;
        }
    private: 
        int age_;
        int *height_;


};


int main() {

    Person p1(10, 185);
    p1.ShowPerson();
    Person p2(p1);
    p2.ShowPerson();

    return 0;
}