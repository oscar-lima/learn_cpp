#include <iostream>

using namespace std;

class Foo
{
  public:

    Foo();
    void setupCB(void (*func)());
    void callCB();

  private:

    void (*function_)(); // declare function pointer with empty args

};
