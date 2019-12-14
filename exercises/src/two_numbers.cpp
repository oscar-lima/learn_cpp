#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

// hint : Nested for loops can iterate over the list and calculate a sum in O(N^2) time

class TwoSum
{
  public:
    static std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
    {


        const int num = list.size();
        const int* ptr = (num > 0) ? list.data() : nullptr;

        for(int i = 0; i < num; i++)
        {
            for(int j = i + 1; j < num; j++)
            {
                if(i != j)
                {
                    if(ptr[i] + ptr[j] == sum)
                        return std::pair<int, int> (i, j);
                }
            }
        }



//         for(auto it = list.begin(), end = list.end(); it != end; ++it)
//         {
//             for(auto it2 = it + 1, end = list.end(); it2 != end; ++it2)
//             {
//                 if(it != it2)
//                 {
//                     if(*it + *it2 == sum)
//                        return std::pair<int, int> (it - list.begin(), it2 - list.begin());
//                 }
//             }
//         }

        
        
//         for(int i=0 ; i < list.size() ; i++)
//         {
//             for(int j=i+1 ; j < list.size() ; j++)
//             {
//                 if(i != j)
//                 {
//                     if(list.at(i) + list.at(j) == sum)
//                         return std::pair<int, int> (i, j);
//                 }
//             }
//         }

        
        return std::pair<int, int> (-1, -1);
    }
};

#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = TwoSum::findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second << std::endl;

    std::cout << "----" << std::endl;
    
    std::vector<int> list2 = {0, 5, 5, 6};
    std::pair<int, int> indices1 = TwoSum::findTwoSum(list2, 10);
    std::cout << indices1.first << '\n' << indices1.second << "\n----" << std::endl;
}
#endif
