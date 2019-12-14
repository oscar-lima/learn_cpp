#include <iostream>
#include <string>

class TextInput
{
  public:
    virtual void add(char c)
    {
        // adds the current character to the current value
        value += c;
    }

    std::string getValue() // returns the current value
    {
        return value;
    }

  protected:
    std::string value;
};

class NumericInput : public TextInput
{
   public:
    NumericInput()
    {
        for(int i = 0; i < 10; i++)
        {
            numeric_value += std::to_string(i);
        }
    }
       
    void add(char c)
    {
        // ignore non numeric value
        if(numeric_value.find(c) != -1)
        {
            value += c;
        }
    }

  private:
      std::string numeric_value;
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue() << std::endl;
}
#endif
