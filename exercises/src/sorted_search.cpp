#include <vector>
#include <stdexcept>
#include <iostream>

#include <algorithm>
#include <iterator>

// Hint 1: For smaller arrays, we could iterate through the sorted elements and return once we find a match

class SortedSearch
{
  public:
    static int countNumbers(const std::vector<int>& sortedVector, int lessThan)
    {
        // Returns an iterator pointing to the first element in the array not greater than a value
        auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan);
        if (it == sortedVector.end() || *it != lessThan)
        {
            std::cout << "not found" << std::endl;
        }
        else
            return std::distance(sortedVector.begin(), it);



//         // find lessThan in vector
//         auto result1 = std::find(std::begin(sortedVector), std::end(sortedVector), lessThan);
// 
//         if(result1 != std::end(sortedVector))
//         {
//             // lessThan was found in vector, return its index
//             return result1 - sortedVector.begin();
//         }
//         // check first and last elements of the vector
//         else if(lessThan < sortedVector.front())
//         {
//             return 0;
//         }
//         else if(sortedVector.back() < lessThan)
//         {
//             return sortedVector.size();
//         }

        int count = 0;

//         for(auto it = sortedVector.begin(); it != sortedVector.end(); it++)
//         {
//             if(*it < lessThan)
//             {
//                 count++;
//             }
//             else
//             {
//                 return count;
//             }
//         }


        int size = sortedVector.size();

        for(int i = 0; i < size ; i++)
        {
            if(sortedVector[i] < lessThan)
            {
                count++;
            }
            else
            {
                return count;
            }
        }
        
        return count;
    }
};

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << SortedSearch::countNumbers(v, 9) << std::endl;
}
#endif
