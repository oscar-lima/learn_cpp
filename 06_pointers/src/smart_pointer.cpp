#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class myClass
{
  public:
    myClass(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    
    ~myClass()
    {
        cout << "myClass object destroyed !" << endl;
    }

    double sum_numbers()
    {
        return a + b;
    }

  private:
      double a, b;
};

int main()
{
    cout << "Smart pointer program started" << endl;
    
    
    // ----- unique ptr 
    
    std::unique_ptr<myClass> single_pointer = std::make_unique<myClass>(5.6, 2.4); // need c++ 14 !
    
    cout << single_pointer->sum_numbers() << endl;
    
    // ----- shared pointer
    
    //std::shared_ptr<myClass> my_pointer(new myClass(3.0, 4.0)); // not recommended!
    
    std::shared_ptr<myClass> my_pointer = std::make_shared<myClass>(3.0, 4.0); // recommended! will ensure new is only called once
    
    // shared pointer is made so it can be copied, so lets copy it
    std::shared_ptr<myClass> my_pointer2 = my_pointer;
    
    cout << my_pointer->sum_numbers() << endl;
    
    cout << my_pointer2->sum_numbers() << endl;
    
    return 0;
}
