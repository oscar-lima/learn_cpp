#include <iostream>
#include "graph.h"
#include "bfs.h"

bFS::bFS() {}

void bFS::printStack(std::vector<int> stack)
{
    std::cout << "stack : {";
    for(int node : stack)
    {
        std::cout << node << ", ";
    }

    std::cout << "}" << std::endl;
}

std::vector<int> bFS::searchPath(int target, int start, Graph &wikipedia_graph)
{
    std::cout << "Searching path from " << start << " to " << target << std::endl;

    std::vector<int> stack = {start};
    
    // while stack isn't empty
    while(stack.size() > 0 )
    {
        this->printStack(stack);
        
        // stack       
        int next_child = wikipedia_graph.getNextChildren(stack.back());
        
        std::cout << "visited : " << next_child << std::endl;
        
        if(next_child == -1)
        {
            stack.pop_back();
        }
        else
        {
            stack.push_back(next_child);
            
            // is goal achieved
            if(stack.back() == target)
            {
                std::cout << "goal achieved" << std::endl;
                return stack;
            }
        }
    }
    
    return stack;
}

int main()
{
    std::cout << "Started bfs graph search algorithm" << std::endl;

    // Create Graph
    Graph wikipedia_graph = Graph();
    std::set<int> nodes = std::set<int>({1, 2 , 3, 4, 5, 6});
    wikipedia_graph.makeNodes(nodes);
    wikipedia_graph.makeBidirectionalEdge(1, 2);
    wikipedia_graph.makeBidirectionalEdge(1, 5);
    wikipedia_graph.makeBidirectionalEdge(2, 5);
    wikipedia_graph.makeBidirectionalEdge(2, 3);
    wikipedia_graph.makeBidirectionalEdge(3, 4);
    wikipedia_graph.makeBidirectionalEdge(5, 4);
    wikipedia_graph.makeBidirectionalEdge(4, 6);
    wikipedia_graph.makeBidirectionalEdge(4, 5);
    wikipedia_graph.printGraph();
    
    // search!
    bFS myBfs = bFS();
    std::vector<int> path = myBfs.searchPath(1, 6, wikipedia_graph); // target, start
    if(path.size() > 0)
    {
        std::cout << "path:" << std::endl;
    }
    else
    {
        std::cout << "empty path! ... Error?" << std::endl;
    }
    for(int i : path)
    {
        std::cout << i << std::endl;
    }
    
    return 0;
}