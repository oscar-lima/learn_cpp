#include "graph.h"

Graph::Graph()
{}

void Graph::makeNodes(std::set<int> &nodes)
{
    nodes_ = nodes;

    // make edge container for each node
    std::set<int> empty_set = {};
    for(auto node : nodes)
    {
        edges_out_.insert(std::make_pair(node, empty_set));
    }
}

void Graph::makeDirectedEdge(int source, int sink)
{
    if(edges_out_.find(source) != edges_out_.end())
    {
        // node found
        edges_out_.find(source)->second.insert(sink);
    }
    else
    {
        std::cerr << "Error while making edge: Node not found!" << std::endl;
    }
}

void Graph::makeBidirectionalEdge(int source, int sink)
{
    this->makeDirectedEdge(source, sink);
    this->makeDirectedEdge(sink, source);
}

void Graph::printGraph()
{
    std::cout << "Graph:\n======" << std::endl;

    // print nodes
    std::cout << "Nodes:" << std::endl;
    for(auto node : nodes_)
    {
        std::cout << node << std::endl;
    }
    
    // print edges
    std::cout << "Edges:" << std::endl;    
    for(auto node : nodes_)
    {
        std::stringstream sink_nodes_ss;
        
        if(edges_out_.find(node) != edges_out_.end())
        {
            std::set<int> sink_nodes = edges_out_.find(node)->second;
        
            for(int j : sink_nodes)
            {
                sink_nodes_ss << j << ", ";
            }
            
            std::cout << "Node (" << node << ")  has the following edges : [" << sink_nodes_ss.str() << "]" << std::endl;
        }
    }
}

/*
 * get next child given a parent node, if we have reached the end then return -1
 */
int Graph::getNextChildren(int parent_node)
{
    // mark parent node as visited
    visited_.push_back(parent_node);
    
    if(edges_out_.find(parent_node) != edges_out_.end())
    {
        std::set<int> sink_nodes = edges_out_.find(parent_node  )->second;
        
        for(int snode : sink_nodes)
        {
            // if snode not in visited_:
            std::vector<int>::iterator it = std::find(visited_.begin(), visited_.end(), snode);
            if (it == visited_.end())
            {
                // mark node as visited
                visited_.push_back(snode);
                return snode;
            }
        }
        
        return -1;
    }
}
