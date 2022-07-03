#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

typedef struct node {
    int index;
    int x;
    int y;
} node;

typedef struct edge {
    node* inital_point;
    node* final_point;
    float weight;
} edge;

class Graph {
private:
    int vertice_count;
    list<edge* > * adj_lst;
    vector<vector<float>> adj_matrix; // Index of Node starts from 1
    vector<vector<string>> meta_content;
    string adj_matrix_path = "Graph\\Adjacency_Matrix_Preprocess.csv";
    string meta_path = "Graph\\Metadata.csv";
    
    //Graph Init with Adjacency Matrix
    void Graph_Adj_Matrix_Init();

    //Graph Init with Adjacency List
    void Graph_Adj_List_Init();

    //Graph init Metadata
    void Graph_Metadata_Init();

    //Node Instantiate
    node* Node_Instantiation(int index, int pos_x, int pos_y);

    //Edge Instantiate
    edge* Edge_Instantiation(node* start_node, node* end_node, float weight);

    //Function: Add Edge to Graph -- Use when init graph with Adjacency List
    void AddEdge(int index, edge* _edge);

public:
    //Graph Constructor
    Graph(int V_count);

    // Function: Get number of node
    int Vertice_Count();

    //Function: Get Information of node
    void Node_Info_Query(int index);

    //Function: Get Information of edge
    void Edge_Info_Query(int start_node_index, int end_node_index);

    // Function: Showing Adjacency Matrix
    void Graph_Show_Adj_Matrix();

    // Function: Showing Adjacency List
    void Graph_Show_Adj_List();
};

#endif