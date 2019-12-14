#include <iostream>

int main()
{
    std::cout << "lambda demo" << std::endl;
    
    int a = 4;

    auto prints = [=](int b){ std::cout << "lambda function, a: " << a << ", b: " << b << std::endl; };

    prints(8);
    
    return 0;
}
