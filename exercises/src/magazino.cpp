#include <iostream>
#include <list>
#include <string>
#include <locale>

class Node
{
  public:
    Node(std::string name, std::list<Node> children = {})
    {
        name_ = name;
        children_=children;
    };

    void count_recursive(std::string &needle, int &count, Node &node)
    {
        if(node.name_ == needle)
            count++;
        
        // iterate over its list
        std::list<Node>::iterator it;
        for (it = node.children_.begin(); it != node.children_.end(); ++it)
        {
            node.count_recursive(needle, count, *it);
        }
    }
    
    int count_nodes_containing_string(std::string needle)
    {
        int count = 0;
        
        // TODO: convert needle to lowercase
        
        this->count_recursive(needle, count, *this);
        
        return count;
    }

  private:
    std::string name_;
    std::list<Node> children_;
};

#ifndef RunTests
int main()
{
    //Create an example tree
    Node n("root",{
                     {"MagaZino",{
                        {"I"},
                          {"Love"},
                            {"magazino"}
                                        }},
        {"Hello",{
            {"Hello",{
                {"Hello",{
                    {"World"}
                }}
            }}
        }}
    });

    std::cout << n.count_nodes_containing_string("test") << std::endl;
    
    std::cout << n.count_nodes_containing_string("Hello") << std::endl;
}
#endif
