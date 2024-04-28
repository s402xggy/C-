#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
    谓词：
        范围值为bool类型的仿函数称为谓词。
            如果operator()接受一个参数，叫做一元谓词
            如果operator()接受两个参数，叫做二元谓词
*/

// 1、如果operator()接受一个参数，叫做一元谓词

class GreateFive{
    public:
        bool operator()(int val) {
            return val > 5;
        }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);


    auto it =  find_if(v.begin(), v.end(), GreateFive());
    if (it != v.end()) {
        cout << *it << endl;
    }
}

//2、 如果operator()接受两个参数，叫做二元谓词
class MyCompare{
    public:
        bool operator()(int val1, int val2){
            return val1 > val2;
        }
};
void test02() {
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(23);
    v.push_back(1);
    v.push_back(15);
    v.push_back(9);
    sort(v.begin(), v.end(), MyCompare());

}

/*
    算数仿函数：
        negate: 一元仿函数， 取反仿函数。
        plus : 二元仿函数, 加法。
*/
void test03() {
    negate<int>n;
    cout << n(50) << endl;
}


void test04() {
    plus<int> p;
    cout << p(10, 59) << endl;
}

int main() {

    return 0;
}