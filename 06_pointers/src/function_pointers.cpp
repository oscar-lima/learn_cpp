#include <iostream>

using namespace std;

void function_without_args()
{
    cout << "function without args called!" << endl;
}

void function_with_args(int number)
{
    cout << "function with args called! , arg : " << number << endl;
}

int main()
{
    cout << "function pointer program started" << endl;

    auto foo = function_without_args;

    foo();

    void (*bar)(int) = function_with_args;
    bar(8);

    return 0;
}
