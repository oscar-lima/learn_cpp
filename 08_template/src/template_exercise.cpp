/*

Make the following code generic and non int specific using templates

template<int ARRAY_SIZE>
class IntArray
{
    int TheArray[ARRAY_SIZE];
public:
    template<typename T>
    void Copy(T target_array[ARRAY_SIZE])
    {
       for(int nIndex = 0; nIndex<ARRAY_SIZE; ++nIndex)
       {
            target_array[nIndex] = static_cast<T>(TheArray[nIndex]);
       }
    }
};

 */

#include <iostream>

using namespace std;

template<typename T, int ARRAY_SIZE>
class Array
{
    T TheArray[ARRAY_SIZE];
public:
    template<typename T1>
    void Copy(T1 target_array[ARRAY_SIZE])
    {
       for(int nIndex = 0; nIndex < ARRAY_SIZE; ++nIndex)
       {
            // target_array[nIndex] = static_cast<T>(TheArray[nIndex]);
            TheArray[nIndex] = static_cast<T>(target_array[nIndex]);
       }
    }
};

int main()
{
    cout << "template exercise" << endl;
    
    const int ARRAY_SIZE = 10;
    
    Array<double, ARRAY_SIZE> my_double_array;
    
    int array_to_copy[ARRAY_SIZE] = {1, 2, 3};
    
    my_double_array.Copy(array_to_copy)
    
    my_double_array.TheArray;
    
    return 0;
}
