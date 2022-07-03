#include <iostream>
#include "Graph.h"

using namespace std;

const int node_count = 35;

int main() {
	Graph HustMap(node_count);

	// Show the Adjacency Matrix of the HustMap
	//HustMap.Graph_Show_Adj_Matrix();

	// Show the Adjacency List of the HustMap
	HustMap.Graph_Show_Adj_List();
}