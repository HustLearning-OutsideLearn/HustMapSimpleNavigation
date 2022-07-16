# include "Graph.h"

int min__Distance(double dist[], bool sptSet[], int V)
{
	// Initialize min value
	double min = 9999.0;
	int min_index = 0;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

vector<int> Graph::PathFindingAstarNonGrid(int start_node_index, int end_node_index) {
	//restore to base node start from 0
	int start = start_node_index - 1;
	int end = end_node_index - 1;

	//store path
	vector<int> store_path;

	dist = new double[vertice_count]; // The output array.  dist[i] will hold the shortest
	// distance from src to i

	sptSet = new bool[vertice_count]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	prev = new int[vertice_count]; //store the previous node prev[i] will be the previous node of i in that shortest path

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < vertice_count; i++)
		dist[i] = INT_MAX, sptSet[i] = false, prev[i] = -1;

	// Distance of source vertex from itself is always 0
	dist[start] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < vertice_count - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = min__Distance(dist, sptSet, vertice_count);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < vertice_count; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && adj_matrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + adj_matrix[u][v] < dist[v]) {
				dist[v] = dist[u] + adj_matrix[u][v];
				prev[v] = u;
			}
	}

	/*for (int i = 0; i < vertice_count; i++)
		if (i != start) {
			cout << start << " to " << i << ", Cost: " << dist[i] << " Previous: " << prev[i] << endl;
		}*/

	cout << " The path found by A star is: " << endl;
	int current = end_node_index;
	store_path.push_back(current);
	cout << current << " <- ";
	while (prev[current] != -1) {
		cout << prev[current] << " <- ";
		current = prev[current];
		store_path.push_back(current);
	}
	cout << "\n" << endl;

	return store_path;
}