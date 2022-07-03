#include <iostream>
#include "Graph.h"

using namespace std;

const int node_count = 35;

int main() {
	Graph HustMap(node_count);

	HustMap.Graph_Show_Adj_Matrix();

	cout << "Hello";
}