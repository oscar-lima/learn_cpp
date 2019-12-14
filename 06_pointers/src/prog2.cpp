#include "prog2.h"

Foo::Foo()
{
    cout << "prog2 object created" << endl;
}

void Foo::setupCB(void (*func)())
{
    // receive a function as a pointer
    function_ = func;
}

void Foo::callCB()
{
    function_();
}
