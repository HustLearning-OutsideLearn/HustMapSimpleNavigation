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
	cout << "CUTTTTTTTTTTT";
	program_active = false;
}

void App() {
	Clear();

	Graph HustMap(node_count);
	HustMap.Graph_Show_MetaData(false);

	int starting_point_index, ending_point_index, choice;

	while (program_active) {
		cout << "Nhap cho ong chau dang bi nac deee: "; cin >> starting_point_index;
		cout << "Nhap cho ong chau muon ve di laoooo: "; cin >> ending_point_index;

		HustMap.PathFindingDFS(starting_point_index, ending_point_index);
		Clear();
		cout << "Ong chau co muon dung tiep hong laooo: , An 1 oke ma an 2 cung oke, nhap deee: "; cin >> choice;
		if (choice == 2) {
			Exit();
		}
		else if (choice == 1) {
			Exit();
		}
		else {
			Exit();
		}
	}
}

int main() {
	// Show the Adjacency Matrix of the HustMap
	//HustMap.Graph_Show_Adj_Matrix();

	// Show Graph Metadata
	//HustMap.Graph_Show_MetaData();

	//Show Adjacency List
	//HustMap.Graph_Show_Adj_List();

	// Show the Map of Hust
	//HustMap.Graph_Show_Map(true, 1000, 700);

	// Show path from Node to Node
	//HustMap.PathFindingDFS(1, 18);

	App();
}