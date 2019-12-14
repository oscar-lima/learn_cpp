/*
 * with info from: https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1
 * 
 */

#include <iostream>

using namespace std;

// by default is type int, but you can override its value
template<class T = int, int SIZE=3>
class Array
{
  public:
    Array()
    {
        for(int i = 0; i < SIZE; i++)
        {
            TheArray[i] = T(); // TheArray[i] = 0
        }
    }
    
    void insert_element(int position, T value)
    {
        TheArray[position] = value;
    }
    
    void print_array()
    {
        for(int i = 0; i < SIZE; i++)
        {
            cout << TheArray[i] << endl;
        }
    }

  private:
    T TheArray[SIZE];
};

int main()
{
    cout << "template 5 example" << endl;
    
    // overriding default template parameters
    Array<float, 5> my_float_array;
    
    // using default template parameters
    Array<> my_int_array;
    
    cout << "-- float array --" << endl;
    
    my_float_array.insert_element(0, 3.4);
    my_float_array.insert_element(1, 4.4);
    my_float_array.insert_element(2, 5.4);
    my_float_array.insert_element(3, 6.4);
    my_float_array.print_array();
    
    cout << "-- int array --" << endl;
    
    my_int_array.insert_element(0, 2);
    my_int_array.insert_element(1, 4);
    my_int_array.print_array();
    
    return 0;
}
