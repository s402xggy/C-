#include <iostream>
using namespace std;
/*
    多态案例：计算器类
    // 真实开发中，使用开闭原则：
        对拓展进行开发， 对修改进行关闭。
    优点：
        1、结构清晰。
        2、可读性强
        3、对于后期和后期扩展的维护性高。
*/
// 抽象类
class AbstractCalculator{
    public:
        virtual int GetResult(){
            return 0;
        };
    
        int num1_;
        int num2_;
    
};

class SubCalculator: public AbstractCalculator{
        virtual int GetResult(){
            return num1_ - num2_;
        };
};

class AddCalculator: public AbstractCalculator{
        virtual int GetResult(){
            return num1_ + num2_;
        };
};

class MulCalculator: public AbstractCalculator{
        virtual int GetResult(){
            return num1_ * num2_;
        };
};

int DoCalculator(AbstractCalculator * calculator) {
   return calculator->GetResult();
}



int main() {

    AddCalculator add;
    add.num1_ = 10;
    add.num2_ = 10;
    cout << "加法 = " << DoCalculator(&add) << endl;

    return 0;
}