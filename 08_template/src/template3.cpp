/*
 * with info from: https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1
 * 
 */

#include <iostream>

using namespace std;

template <typename T>

T square(T number)
{
    return number*number;
}

int main()
{
    cout << "template 3 example" << endl;

    int int_number = 2;
    double double_number = 4.5;

    cout << square<int>(int_number) << endl;
    cout << square<double>(double_number) << endl;

    return 0;
}
