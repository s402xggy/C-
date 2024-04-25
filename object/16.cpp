#include <iostream>

using namespace std;

/*
    多态案例：
        计算机电脑组装
*/

class AbstrctCpu{
    public:
        virtual void Calculate() = 0;
        virtual ~AbstrctCpu(){};
};

class AbstrctCard{
    public:
        virtual void Display() = 0;
        virtual ~AbstrctCard() {};
};

class AbstrctMemory{
    public:
        virtual void Storage() = 0;
        virtual ~AbstrctMemory() {};
};

class InterCpu:public AbstrctCpu {
    public:
        virtual void Calculate() {
            cout << "Inter CPU 开始计算！！！" << endl;
        };
};

class NvidiaCard: public AbstrctCard{
    public:
        virtual void Display() {
            cout << "Nvidia 显卡开始显示！！！" << endl;

        }
};

class LenovoMemory: public AbstrctMemory{
    public:
        virtual void Storage() {
            cout << "Lenovo 内存条开始存储！！！" << endl;

        }
};



class Computer{
    public:
        Computer(AbstrctCpu *cpu, AbstrctCard *card, AbstrctMemory *memory):cpu_(cpu), card_(card), memory_(memory){
        };
        ~Computer() {
            if (cpu_ != nullptr) {
                delete cpu_;
                cpu_ = nullptr;
            }

            if (card_ != nullptr) {
                delete card_;
                card_ = nullptr;
            }

            if (memory_ != nullptr) {
                delete memory_;
                memory_ = nullptr;
            }
        }
        void Work(){
            cpu_->Calculate();
            card_->Display();
            memory_->Storage();
        }

    private:
        AbstrctCpu *cpu_;
        AbstrctCard *card_;
        AbstrctMemory *memory_;

};

int main() {
    InterCpu *cpu = new InterCpu;
    NvidiaCard *card = new NvidiaCard;
    LenovoMemory *memory = new LenovoMemory;

    Computer computer(cpu, card, memory);
    computer.Work();

    // delete cpu;
    // delete card;
    // delete memory;
    return 0;

}