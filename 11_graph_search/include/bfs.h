#include <iostream>
#include <vector>

class bFS
{
  public:

    bFS();
    
    void printStack(std::vector<int> stack);
    
    std::vector<int> searchPath(int target, int start, Graph &wikipedia_graph);
};
