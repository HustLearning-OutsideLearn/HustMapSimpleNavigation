#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

Graph::Graph(int v_count) {
    this->vertice_count = v_count;

    // Initialize the Adjacency Matrix of Graph
    Graph_Adj_Matrix_Init();

    // Initialize the Metadata_content
    Graph_Metadata_Init();

    // Initialize Map of Graph
    Graph_Load_Map();

    // Initialize the Adjacency List
    adj_lst = new list<edge*>[vertice_count]; // Re init the Adj_Lst
    //Graph_Adj_List_Init();
}