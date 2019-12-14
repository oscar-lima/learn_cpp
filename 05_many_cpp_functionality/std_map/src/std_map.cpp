#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	cout << "std map example" << endl;
	std::map<int, std::string> test_map;

	test_map[0] = "hello";
	test_map[1] = "world";

	cout << test_map[0] << " " << test_map[1] << endl;
}
