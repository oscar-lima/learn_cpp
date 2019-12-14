#include <iostream>
#include <map>

using namespace std;

int main()
{
	cout << "std multimap example" << endl;

	std::multimap<double, int> nodes;
	nodes.insert(std::pair<double, int>(5.0, 5));
	nodes.insert(std::pair<double, int>(3.0, 2));
	nodes.insert(std::pair<double, int>(10.0, 15));

	for(auto it = nodes.begin(); it != nodes.end(); it++)
    {
        cout << (*it).first << endl;
    }

    return 0;
}
