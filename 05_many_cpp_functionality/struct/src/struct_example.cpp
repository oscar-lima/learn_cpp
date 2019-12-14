#include <iostream>

using namespace std;

struct product
{
    string color;
    double weight;
};

int main()
{
    cout << "struct example" << endl;
    
    product orange;
    orange.color = "orange";
    orange.weight = 1.5;
    
    cout << orange.color.c_str() << endl;
    cout << orange.weight << endl;
    
    return 0;
}
