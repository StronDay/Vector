//###########################################################################//
//#                                                                         #//
//#             Класс для тестирования основного класса MyVector.           #//
//#                                                                         #//
//###########################################################################//

#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
public:

    User() {}
    User(const string& name, const unsigned int number);

    void rename(const string& name);
    void rennumber(const unsigned int number);

    friend ostream& operator<<(ostream& os, const User& user);

private:

    string _name = "NONE";
    unsigned int _number = 0;
};