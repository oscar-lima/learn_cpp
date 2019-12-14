#include <iostream>
#include <vector>
#include <limits>
#include <utility>

struct Node
{
	int nodeid;
	std::string node_name;
	std::pair<double, double> node_bounds;
	std::vector<int> edges_out;
};

struct Edge
{
	int edgeid;
	int nodeid; // parent node from where this edge comes from
	int sink_id; // child node to where this edge goes
	std::string edge_type; // conditional, interference or start end
	std::pair<double, double> edge_bounds; // action duration
};

struct Graph
{
	std::vector<Node> nodes;
	std::vector<Edge> edges;
};

Node make_node(int nodeid, std::string node_name, double node_lower_bound, double node_upper_bound, std::vector<int> edges_out)
{
	Node temp_node;

	temp_node.nodeid = nodeid;
	temp_node.node_name = node_name;
	temp_node.node_bounds = std::make_pair(node_lower_bound, node_upper_bound);
	temp_node.edges_out = edges_out;

	return temp_node;
}

Edge make_edge(int edgeid, int nodeid, int sink_id, std::string edge_type, double edge_lower_bound, double edge_upper_bound)
{
	Edge temp_edge;

	temp_edge.edgeid = edgeid;
	temp_edge.nodeid = nodeid;
	temp_edge.sink_id = sink_id;
	temp_edge.edge_type = edge_type;
	// temp_edge.edge_type = temp_edge.START_END
	// temp_edge.edge_type = temp_edge.CONDITION;
	// temp_edge.edge_type = temp_edge.INTERFERENCE;
	temp_edge.edge_bounds = std::make_pair(edge_lower_bound, edge_upper_bound);
	
	return temp_edge;
}
