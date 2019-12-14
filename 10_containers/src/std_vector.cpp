#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "std vector example" << endl;
    
    std::vector<int> my_vector = {1, 10};
    
    my_vector.push_back(20);
    
    cout << my_vector.at(1) << endl;
    
    // --- vector iteration
    
    cout << "simple iteration" << endl;
    for(int element : my_vector) // c++ 11 only
    {
        cout << element << endl;
    }
    
    cout << "iterating over vector" << endl;
    for(std::vector<int>::iterator it = my_vector.begin(); it != my_vector.end(); it++)
    {
        cout << *it << endl;
    }
    
    cout << "manual iteration over vector" << endl;
    for(int i = 0; i < my_vector.size() ; i++)
    {
        cout << my_vector.at(i) << endl;
    }
    
    cout << "using operator []" << endl;
    for(int i = 0; i < my_vector.size() ; i++)
    {
        cout << my_vector[i] << endl;
    }
    
    // reverse iterator
    cout << "reverse iterator" << endl;
    for(std::vector<int>::const_reverse_iterator it = my_vector.rbegin(); it != my_vector.rend(); it++)
	{
		cout << *it << endl;
	}
    
    // --- front, back
    
    cout << "first element of the vector : " << my_vector.front() << endl;
    cout << "first element of the vector : " << my_vector.back() << endl;
    
    // --- pop back
    
    // remove last element on the vector and resize it to one element less
    my_vector.pop_back();
    
    
    // --- resize
    
    cout << "vector size : " << my_vector.size() << endl;
    
    my_vector.resize(10);
    
    cout << "vector size (after being resized) : " << my_vector.size() << endl;
    
    return 0;
}
