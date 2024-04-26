#ifndef __6_HPP__
#define __6_HPP__
#include <iostream>
template <class NameType, class AgeType>
class Person1{
    public:
        Person1(NameType name, AgeType age);
        void ShowPerson();

    private:
        NameType name_;
        AgeType age_;
};









#endif