#include <iostream>

using namespace std;

/*
    继承：  作用： 减少重复代码。
    继承方式：
        public:             基类的成员和成员函数属性不变，基类的私有成员无法访问
        protected:          基类的成员和成员函数（公有），公有全部变为，protected, 其他不变，基类的私有成员无法访问
        private:            基类的成员和成员函数（公有和保护），全部变为，private, 其他不变，基类的私有成员无法访问
*/

class BasePage{
    public:
        void Header() {
            cout << "首页、公开课、登录、注册... (公共头部)" << endl;
        }
        void Footer() {
            cout << "帮助中心、交流合作、站内地图... (公共底部)" << endl;
        }
        void Left() {
            cout << "Java、Python、C++、...(公共分类列表)" << endl;
        }
};

class Java: public BasePage{
    public:
        void Content() {
            cout << "Java 学科视频" << endl;
        }
};

class Python: public BasePage{
    public:
        void Content() {
            cout << "Python 学科视频" << endl;
        }
};

class Cpp: public BasePage{
    public:
        void Content() {
            cout << "Cpp 学科视频" << endl;
        }
};


int main() {

    Java ja;
    ja.Header();
    ja.Content();
    ja.Footer();
    ja.Left();
    return 0;
}