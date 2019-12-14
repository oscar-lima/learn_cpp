/**
 * Floy-Warshall algorithm for computing minimum distance between nodes in a graph
 *
 */

#include<stdio.h>

// Number of nodes in the graph
#define number_of_nodes 4

/* Define Infinite as a large enough value. This value will be used
for vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][number_of_nodes]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall (int graph[][number_of_nodes])
{
	/* dist[][] will be the output matrix that will finally have the shortest
	distances between every pair of vertices */
	int dist[number_of_nodes][number_of_nodes], i, j, k;

	/* Initialize the solution matrix same as input graph matrix. Or
	we can say the initial values of shortest distances are based
	on shortest paths considering no intermediate vertex. */
	for (i = 0; i < number_of_nodes; i++)
		for (j = 0; j < number_of_nodes; j++)
			dist[i][j] = graph[i][j];

	/* Add all vertices one by one to the set of intermediate vertices.
	---> Before start of an iteration, we have shortest distances between all
	pairs of vertices such that the shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
	----> After the end of an iteration, vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < number_of_nodes; k++)
	{
		// Pick all vertices as source one by one
		for (i = 0; i < number_of_nodes; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < number_of_nodes; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][number_of_nodes])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < number_of_nodes; i++)
	{
		for (int j = 0; j < number_of_nodes; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int graph[number_of_nodes][number_of_nodes] = { {0, 5, INF, 10},
													{INF, 0, 3, INF},
													{INF, INF, 0, 1},
													{INF, INF, INF, 0} };

	// Print the solution
	floydWarshall(graph);
	return 0;
}
