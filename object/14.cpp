#include <iostream>
using namespace std;

/*
    纯虚函数：
        virtual 返回值类型 函数名 （参数列表） = 0；
    只要有一个纯虚函数的类叫做抽象类。
        抽象类特点：
            无法实例化对象。
            子类必须重写抽象类的虚函数， 否则也属于抽象类。

*/

/*
    多态案列：
        制作饮品。
    
*/

class AbstractDrinking{
    public:
        virtual void Boil() = 0;

        virtual void Brew() = 0;

        virtual void PourInCup() = 0;

        virtual void PutSomething() = 0;

        void MakeDrinking() {
            Boil();
            Brew();
            PourInCup();
            PutSomething();
        }
};


class Coffee: public AbstractDrinking {
    public:
        virtual void Boil() {cout << "煮农夫三拳！！！" << endl;};

        virtual void Brew() {cout << "加入咖啡冲泡！！！" << endl;};

        virtual void PourInCup() {cout << "将咖啡放入咖啡杯！！！" << endl;};

        virtual void PutSomething() {cout << "加入牛奶和糖！！！" << endl;};
};


class Tea: public AbstractDrinking {
    public:
        virtual void Boil() {cout << "煮白开水！！！" << endl;};

        virtual void Brew() {cout << "加入茶叶冲泡！！！" << endl;};

        virtual void PourInCup() {cout << "将茶水放入茶杯！！！" << endl;};

        virtual void PutSomething() {cout << "加入牛奶和糖！！！" << endl;};
};



int main() {
    AbstractDrinking *make;
    Coffee coffee;
    make = &coffee;
    make->MakeDrinking();
    Tea tea;
    make = &tea;
    tea.MakeDrinking();

    return 0;
}