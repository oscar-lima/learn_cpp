#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

class Graph
{
  public:

    // constructor
    Graph();
    
    void makeNodes(std::set<int> &nodes);
    
    void makeDirectedEdge(int source, int sink);
    
    void makeBidirectionalEdge(int source, int sink);
    
    void printGraph();
    
    int getNextChildren(int parent_node);

  private:

    std::set<int> nodes_;
    std::map<int, std::set<int> > edges_out_;
    std::vector<int> visited_;
};
