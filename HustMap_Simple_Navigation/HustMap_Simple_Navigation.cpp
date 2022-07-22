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

	int starting_point_index, ending_point_index, choice;
	string algo_choice;

	while (program_active) {
		HustMap.Graph_Show_MetaData(false);
		cout << "Enter starting point(e.g 1,2,3): "; cin >> starting_point_index;
		cout << "Enter ending point(e.g 4,5,6): "; cin >> ending_point_index;

		cout << "Deep First Seach (dfs)" << endl;
		cout << "Breadth First Search (bfs)" << endl;
		cout << "Belman Ford (bel)" << endl;
		cout << "Dijkstra (dij)" << endl;
		cout << "A - star (*)" << endl;
		cout << "ALL (all)" << endl;
		cout << "Auto (auto)" << endl;
		cout << "Enter type of algorithm you wanna use(e.g bfs, dfs): "; cin >> algo_choice;
		HustMap.PathFinding(starting_point_index, ending_point_index, algo_choice);		
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
	/*HustMap.Graph_Show_MetaData(true);
	HustMap.Graph_Show_MetaData(false);*/

	//Show Adjacency List
	//HustMap.Graph_Show_Adj_List();

	//Show Adjacency Node List
	//HustMap.Graph_Show_Node_Adj_List();

	// Show the Map of Hust
	//HustMap.Graph_Show_Map(false, 1000, 700);

	// SHow the Grid Map size
	//HustMap.Graph_Show_Grid_Map_Size();

	// Show path from Node to Node DFS
	//HustMap.PathFindingDFS(1, 18);
	//HustMap.PathFinding(18, 25, "dfs");

	// Show path from Node to Node BFS
	//HustMap.PathFindingBFS(1, 18);
	//HustMap.PathFinding(18, 25, "bfs");
	
	// Show path from Node to Node Dijkstra
	//HustMap.PathFindingDijkstra(18, 25);
	//HustMap.PathFinding(16, 34, "dij");

	// Show path from Node to Node BelmanFord
	//HustMap.PathFindingBelmanFord(1, 18);
	//HustMap.PathFinding(18, 34, "bel");

	// Show path from Node to Node Astar non-grid
	//HustMap.PathFindingAstarNonGrid(1, 18);
	//HustMap.PathFinding(25, 18, "*");

	// Show path from Node to Node Astar
	//HustMap.PathFindingAstar(1, 18);

	// Show auto path from Node to Node 
	//HustMap.PathFinding(1, 18, "auto");
	//HustMap.PathFinding(1, 18, " ");

	// Show all path created by all algo from Node to Node
	//HustMap.PathFinding(1, 18, "all");

	// Calculate the Average time of Execution by all Algo
	//HustMap.TimeExecution();

	App();
}