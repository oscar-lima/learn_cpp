#include <iostream>

using namespace std;

class test
{
  public:
    test() : count(0)
    {}
    
    test(int count) : count(0)
    {
        this->count = count;
    }
    
    void greet()
    {
        cout << "hello" << endl;
    }
    
    void show_count()
    {
        cout << "count : " << count << endl;
    }

  private:
    int count;
};

int main()
{
    cout << "class example" << endl;
    test hola = test(5);
    hola.greet();
    hola.show_count();
    return 0;
}
