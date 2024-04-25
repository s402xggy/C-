#include <iostream>
#include <string>
using namespace std;

/*
    友元
        全局友元函数
        友元类
        友元成员函数

*/
class Building;
// class Goodgay1;
// 全局友元函数
class Goodgay1;
class Building{
    friend void GoodGay(Building *building);
    friend class Goodgay;
    // friend void Goodgay1::Visit();
    public:
        Building() {
            sitting_room_ = "仙桃";
            bed_room_ = "707";
        }

    public:
        std::string sitting_room_;
    private:
        std::string bed_room_;
};

void GoodGay(Building *building) {
    std::cout << "访问building 中 public :" << building->sitting_room_ << endl;
    std::cout << "访问building 中 private :" << building->bed_room_ << endl;
}

class Goodgay{
    public:
        Goodgay() {
            building_ = new Building;
        }
    public:
        void Visit() {
            cout << "访问building 中 public : "  << building_->sitting_room_ << endl;
            std::cout << "访问building 中 private :" << building_->bed_room_ << endl;

        };       // 访问building中的私有成员。

        Building *building_;
};

class Goodgay1{
    public:
        Goodgay1() {
            building_ = new Building;
        }
    public:
        void Visit();      // 访问building中的私有成员。

        Building *building_;
};

void Goodgay1::Visit(){
            cout << "访问building 中 public : "  << building_->sitting_room_ << endl;
            // std::cout << "访问building 中 private :" << building_->bed_room_ << endl;

};  


int main() {
    Building building;
    GoodGay(&building);
    Goodgay gay;
    gay.Visit();

    Goodgay1 gay1;
    gay1.Visit();
}