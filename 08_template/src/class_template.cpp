#include <iostream>

using namespace std;

template<class T1, class T2>
class Pair
{
  public:
    Pair(){}
  private:
    T1 hola;
};

int main()
{
    cout << "class template" << endl;
    
    Pair<int, Pair<int,int> > PairOfPair;
    
    return 0;
}
