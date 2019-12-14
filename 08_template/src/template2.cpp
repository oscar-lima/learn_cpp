#include <iostream>

using namespace std;

template <class number1, class number2>

number1 compute_smaller_number(number1 a, number2 b)
{
    return (a<b?a:b);
}

int main()
{
    cout << "template 2 example" << endl;
    
    int int_number = 4;
    double double_number = 6.5;
    
    cout << compute_smaller_number<int, double>(int_number, double_number) << endl;
    
    double_number = 3.5;
    
    cout << compute_smaller_number<int>(double_number, int_number) << endl;
    cout << compute_smaller_number<int>(int_number, double_number) << endl;
    
    return 0;
}
