#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Palindrome
{
public:
    static bool isPalindrome(const std::string& word)
    {
        // make word copy
        std::string word_lowecase = word;

        // transform string to lower case
        std::transform(word_lowecase.begin(), word_lowecase.end(), word_lowecase.begin(), ::tolower);
        
        // iterate over the words in word
        for(std::string::size_type i = 0; i < word_lowecase.size(); ++i)
        {
//             std::cout  << word_lowecase[i] << std::endl;
//             std::cout  << word_lowecase[word_lowecase.size() - i - 1] << std::endl;
//             std::cout << "-----" << std::endl;
            
            if(word_lowecase[i] != word_lowecase[word_lowecase.size() - i - 1])
            {
                std::cout << "not a palindrome" << std::endl;
                return false;
            }
        }
        return true;
    }
};

#ifndef RunTests
int main()
{
    std::cout << Palindrome::isPalindrome("Deleveled") << std::endl;
}
#endif
