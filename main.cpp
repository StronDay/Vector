#include "MyVector.h"
#include "User.h"
#include <vector>
#include <algorithm>

int main()
{
    User us1("Maks", 1);
    User us2("Orhan", 2);
    User us3("Julia", 3);
    User us4("Artem", 4);
    User us5("Margo", 5);
    User us6("NONE", 6);

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int f = 5;

    //cout << "!!!!!!!!!!" << endl;

    vector<User> arr;
    vector<int> v_arr_number;

    MyVector<User> aray;
    MyVector<int> arr_number;

    arr_number.PushBack(5);
    arr_number.PushBack(4);
    arr_number.PushBack(3);
    arr_number.PushBack(2);
    arr_number.PushBack(1);

    v_arr_number.push_back(5);
    v_arr_number.push_back(4);
    v_arr_number.push_back(3);
    v_arr_number.push_back(2);
    v_arr_number.push_back(1);

    aray.PushBack(us1);
    aray.PushBack(us2);
    aray.PushBack(us3);
    aray.PushBack(us4);
    aray.PushBack(us5);

    arr.push_back(us1);
    arr.push_back(us2);
    arr.push_back(us3);
    arr.push_back(us4);
    arr.push_back(us5);

    /*cout << aray << endl << endl;

    MyVector<User>::Iterator it(aray.End());
    MyVector<User>::Iterator ir(aray.Begin());

    sort(it, ir);

    cout << aray << endl << endl;*/

    cout << arr_number << endl << endl;

    MyVector<int>::Iterator begin(arr_number.Begin());
    MyVector<int>::Iterator end(arr_number.End());

    sort(begin, end);

    //cout << *(begin + 1) << endl;

    cout << arr_number << endl << endl;

    /*vector<int>::iterator begin(v_arr_number.begin());
    vector<int>::iterator end(v_arr_number.end());

    for (int i = 0; i < v_arr_number.size(); i++) {

        cout << *begin + i << endl;
    }

    sort(begin, end);

    cout << endl;

    for (int i = 0; i < v_arr_number.size(); i++) {

        cout << *begin + i << endl;
    }*/

    //vector<User>::iterator it(arr.begin());
    //vector<User>::iterator ir(arr.end());

    //sort(it, ir);

    return 0;
}