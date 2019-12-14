#include <iostream>

using namespace std;

int main()
{
    // declare pointer
    int *intptr;
    
    // allocate memory
    intptr = new int;
    
    // store value
    *intptr = 5;
    
    cout << *intptr << endl;
    
    // -----------------------
    
    // declare second pointer
    int *intptr2;
    
    // allocate memory
    intptr2 = new int;
    
    // make it point to the address of pointer 1
    intptr2 = intptr;
    
    // display its value (should be 5)
    cout << *intptr2 << endl;
    
    // -----------------------
    
    // declare normal non pointer integer
    int fish = 7;
    
    // make pointer 1 to point to fish
    intptr = &fish;
    
    // display value of pointer 1 (should be 7)
    cout << *intptr << endl;
    
    return 0;
}

// Passing parameters by reference.
// #include <iostream>
// using namespace std;
// 
// void Duplicate(int& a, int& b, int& c) {
//   a *= 2;
//   b *= 2;
//   c *= 2;
// }
// 
// int main() {
//   int x = 1, y = 3, z = 7;
//   Duplicate(x, y, z);
//   // The following outputs: x=2, y=6, z=14.
//   cout << c"x="<< x << ", y="<< y << ", z="<< z;
//   return 0;
// }
