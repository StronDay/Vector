//###########################################################################//
//#                                                                         #//
//#             Класс для тестирования основного класса MyVector.           #//
//#                                                                         #//
//###########################################################################//

#include "User.h"

User::User(const string& name, const unsigned int number)
    : _name(name), _number(number)
{}

void User::rename(const string& name) { _name = name; }

void User::rennumber(const unsigned int number) { _number = number; }

ostream& operator<<(ostream& os, const User& user)
{
    os << "Name: " << user._name << endl;
    os << "Number: " << user._number << endl;

    return os;
}