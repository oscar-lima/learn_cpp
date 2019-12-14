#include "prog2.h"

using namespace std;

void prog1CB()
{
    cout << "prog1 callback called from prog2" << endl;
}

int main()
{
    cout << "prog1 started..." << endl;

    Foo my_object = Foo();

    // setup callback
    my_object.setupCB(prog1CB);

    // calling CB of prog1 from a method in prog2
    my_object.callCB();

    return 0;
}
