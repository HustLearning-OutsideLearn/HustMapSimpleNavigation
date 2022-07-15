#include <iostream>
#include "Graph.h"

using namespace std;

const int node_count = 35;
bool program_active = true;

void Clear() {
	for (int n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

void Exit() {
	Clear();
	cout << "SEE YOU AGAIN";
	program_active = false;
}

void App() {
	Clear();

	Graph HustMap(node_count);
	HustMap.Graph_Show_MetaData(false);

	int starting_point_index, ending_point_index, choice;

	while (program_active) {
		cout << "Enter starting point(e.g 1,2,3): "; cin >> starting_point_index;
		cout << "Enter ending point(e.g 4,5,6): "; cin >> ending_point_index;

		HustMap.PathFindingDFS(starting_point_index, ending_point_index);
		Clear();
		cout << "Find another part(enter 1), do not(enter 0): "; cin >> choice;
		if (choice == 0) {
			Exit();
		}
		else if (choice == 1) {
			Clear();
			continue;
		}
		else {
			Exit();
		}
	}
}

int main() {
	Graph HustMap(node_count);

	// Show the Adjacency Matrix of the HustMap
	//HustMap.Graph_Show_Adj_Matrix();

	// Show Graph Metadata
	//HustMap.Graph_Show_MetaData();

	//Show Adjacency List
	//HustMap.Graph_Show_Adj_List();

	//Show Adjacency Node List
	//HustMap.Graph_Show_Node_Adj_List();

	// Show the Map of Hust
	//HustMap.Graph_Show_Map(false, 1000, 700);

	// Show path from Node to Node DFS
	//HustMap.PathFindingDFS(1, 18);

	// Show path from Node to Node BFS
	//HustMap.PathFindingBFS(1, 18);

	// Show path from Node to Node Dijkstra
	//HustMap.PathFindingDijkstra(1, 18);

	// Show path from Node to Node BelmanFord
	//HustMap.PathFindingBelmanFord(1, 18);

	//App();
}