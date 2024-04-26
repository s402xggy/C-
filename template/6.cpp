#include "6.hpp"

template <class NameType, class AgeType>
Person1<NameType, AgeType>::Person1(NameType name, AgeType age):name_(name), age_(age){};

template <class NameType, class AgeType>
void Person1<NameType, AgeType>::ShowPerson() {
    std::cout << "name = " << name_ << " age = " << age_ << std::endl;
}
