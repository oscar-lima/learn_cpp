#include "esterel_plan.h"

std::pair<double, double> getBounds(int prenode, int node, Graph &esterel_plan)
{
	if(prenode == node)
		return std::make_pair(0.0, 0.0);

	// o: initialize bound default values to -inf, +inf
	// m: potentially no bounds
	std::pair<double, double> bounds = std::make_pair(-1000.0, 1000.0);

	// o: check all nodes ordered before prenode
	// m: check all nodes ordered after prenode

	// m: iterate over sink nodes derived from prenode (skip if none)
	for(size_t i = 0; i < esterel_plan.nodes[prenode].edges_out.size(); i++)
	{
		int edge_id = esterel_plan.nodes[prenode].edges_out[i];
		int sink_id = esterel_plan.edges[edge_id].sink_id;

		// m: get bounds from child
		std::pair<double, double> newbounds = getBounds(sink_id, node, esterel_plan);
		// m: update bounds
		if(bounds.first < newbounds.first + esterel_plan.edges[edge_id].edge_bounds.first)
			bounds.first = newbounds.first + esterel_plan.edges[edge_id].edge_bounds.first;
		if(bounds.second > newbounds.second + esterel_plan.edges[edge_id].edge_bounds.second)
			bounds.second = newbounds.second + esterel_plan.edges[edge_id].edge_bounds.second;
	}

	return bounds;
}

void print_bounds(std::pair<double, double> bounds)
{
	std::cout << "bounds : [" << bounds.first << ", " << bounds.second << "]" << std::endl;
}

int main()
{
	// create graph
	Graph esterel_plan;

	// Nodes
	esterel_plan.nodes.push_back(make_node(0, "initial_state", -1, -1, {0, 3}));
	esterel_plan.nodes.push_back(make_node(1, "light_match_start", -1, -1, {1}));
	esterel_plan.nodes.push_back(make_node(2, "light_match_end", -1, -1, {}));
	esterel_plan.nodes.push_back(make_node(3, "fix_fuse_start", -1, -1, {2}));
	esterel_plan.nodes.push_back(make_node(4, "fix_fuse_end", -1, -1, {4}));

	// Edges
	// esterel_plan.edges.push_back(make_edge(0, 0, 1, "condition", 0, 1000));
	esterel_plan.edges.push_back(make_edge(0, 0, 1, "condition", 0, 1000));
	esterel_plan.edges.push_back(make_edge(1, 1, 2, "start_end", 5, 5));
	esterel_plan.edges.push_back(make_edge(2, 3, 4, "start_end", 1, 1));
	esterel_plan.edges.push_back(make_edge(3, 0, 3, "condition", 0, 4));
	// esterel_plan.edges.push_back(make_edge(4, 4, 2, "condition", 0, 1000));
	esterel_plan.edges.push_back(make_edge(4, 4, 2, "interference", 0, 1000));
	esterel_plan.edges.push_back(make_edge(5, 1, 3, "condition", 0, 1000));

	// compute and print bounds
	print_bounds(getBounds(0, 0, esterel_plan));
	print_bounds(getBounds(0, 1, esterel_plan));
	print_bounds(getBounds(1, 2, esterel_plan));
	print_bounds(getBounds(2, 3, esterel_plan));
	print_bounds(getBounds(3, 4, esterel_plan));
	print_bounds(getBounds(1, 3, esterel_plan));
	return 0;
}
