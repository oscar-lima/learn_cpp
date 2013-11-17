#include <iostream>
//using std::cout;
using namespace std;

int main(int argc, char* argv[])
{
	cout << "hello world !!!\n";
	cout << "arguments : \n";
	
	for(int i = 0; i < argc ; i++)
	{
		cout << "argv[" << i << "] = " << argv[i] << "\n";
	}
	
	return 0;
}