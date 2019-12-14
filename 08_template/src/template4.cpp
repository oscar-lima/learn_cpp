/*
 * with info from: https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1
 * 
 */

#include <iostream>

using namespace std;

template <class T>

double getAverageArray(T tarray[], int number_of_elements)
{
    double sum = double(); // sum = 0.0
    
    for(int i = 0; i < number_of_elements; i++)
    {
        sum += tarray[i];
    }
    
    return sum / double(number_of_elements);
}

int main()
{
    double my_array[6] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0};
    int number_of_elements = 6;
    
    cout << "average : " << getAverageArray(my_array, number_of_elements) << endl;
    return 0;
}
