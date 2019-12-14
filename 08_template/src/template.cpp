#include <iostream>

using namespace std;

template <class number>

number add_numbers(number a, number b)
{
    return a + b;
}

int main()
{
    cout << "template example" << endl;
    
    int first_int_number = 3, second_int_number = 7;
    
    cout << add_numbers(first_int_number, second_int_number) << endl;
    
    double first_double_number = 5.5, second_double_number = 4.5;
    
    cout << add_numbers(first_double_number, second_double_number) << endl;
    
    return 0;
}
