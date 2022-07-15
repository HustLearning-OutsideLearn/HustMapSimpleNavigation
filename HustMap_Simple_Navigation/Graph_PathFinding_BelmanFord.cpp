#include "Graph.h"

void Graph::PathFindingBelmanFord(int start_node_index, int end_node_index) {
	//restore to base node start from 0
	int start = start_node_index - 1;
	int end = end_node_index - 1;

	bool negative_w_loop = false;

	for (int u = 0; u < vertice_count; u++) {
		dist[u] = 10;   //set as infinity
		prev[u] = -1;    //undefined previous
	}

	dist[start] = 0;   //distance of start is 0
	set<int> S;       //create empty set S
	list<int> Q;

	for (int u = 0; u < vertice_count; u++) {
		Q.push_back(u);    //add each node into queue
	}

	while (!Q.empty()) {
		list<int> ::iterator i;
		i = min_element(Q.begin(), Q.end());
		int u = *i; //the minimum element from queue
		Q.remove(u);
		S.insert(u); //add u in the set
		list<node>::iterator it;

		for (it = node_adj_lst[u].begin(); it != node_adj_lst[u].end(); it++) {
			if ((dist[u] + (it->cost)) < dist[it->dest]) { //relax (u,v)
				dist[it->dest] = (dist[u] + (it->cost));
				prev[it->dest] = u;
			}
		}
	}

	for (int u = 0; u < vertice_count; u++) {
		Q.push_back(u);    //add each node into queue
	}

	while (!Q.empty()) {
		list<int> ::iterator i;
		i = min_element(Q.begin(), Q.end());
		int u = *i; //the minimum element from queue
		Q.remove(u);
		//S.insert(u); //add u in the set
		list<node>::iterator it;

		for (it = node_adj_lst[u].begin(); it != node_adj_lst[u].end(); it++) {
			if ((dist[u] + (it->cost)) < dist[it->dest]) { //relax (u,v)
				negative_w_loop = true;
			}
		}
	}

	if (negative_w_loop) {
		cout << "Belman Ford detected negative weigth circle" << endl;
	}
	else {
		/*for (int i = 0; i < vertice_count; i++)
		if (i != start) {
			cout << start << " to " << i << ", Cost: " << dist[i] << " Previous: " << prev[i] << endl;
		}*/

		cout << " The path is: " << endl;
		int current = end_node_index;
		cout << current << " -> ";
		while (prev[current] != -1) {
			cout << prev[current] << " -> ";
			current = prev[current];
		}
	}
}