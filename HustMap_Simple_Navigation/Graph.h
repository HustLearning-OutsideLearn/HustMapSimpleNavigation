#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;
using namespace std;

typedef struct node {
    int dest;
    double cost;
}node;

class Graph {
private:
    /*
    * vertice_count (int): store the number of vertice in graph
    * adj_lst:
    *   initial state: list of edge pointer
    *   final state (graph initialization): array of list of edge pointer
    * node_adj_lst
    *   initial state: list of edge pointer
    *   final state (graph initialization): array of list of node and its edge pointer
    * adj_matrix (vector<vector>): 2D vector store the adjacency matrix
    * meta_conttent (vector<vector>): 2D vector store the metadatas
    * adj_matrix_path (string): Adjacency Matrix CSV file path
    * meta_path (string): Metadata file path
    * map_path (string): Image of Hust Map file path
    * map_img (Mat): Store the image loaded by open-cv
    * map_path_img (Mat): Store the image contained path drawed by open-cv
    * test_path (vector): list of index for test the line drawing
    * current_path (vector): List of path found used by DFS
    * dist (double):
    *   define: array of distance from a node to others, index is other node, value is cost
    *   used: Dijkstra, Belman Ford
    * prev (int): array of previous node
    *   define: array of previous node of a node, index is a node, value is previous node which has the lowest cost
    *   used: Dijkstra, Belman Ford
    */
    int vertice_count;
    list<int> * adj_lst;
    list<node>* node_adj_lst;
    vector<vector<double>> adj_matrix; // Index of Node starts from 1
    vector<vector<string>> meta_content;
    string adj_matrix_path = "Graph\\Adjacency_Matrix_Preprocess.csv";
    string meta_path = "Graph\\Metadata.csv";
    string map_path = "Map\\BK Map.jpg";
    Mat map_img;
    Mat map_path_img;
    vector<vector<int>> grid_map_img;
    vector<int> test_path;
    vector<vector<int>> current_path;
    double * dist;
    int * prev;
    
    //Graph Init with Adjacency Matrix
    void Graph_Adj_Matrix_Init();

    //Graph Init with Adjacency List
    void Graph_Adj_List_Init();

    //Graph Init with Node Adjacency List
    void Graph_Node_Adj_List_Init();

    //Graph Init with Grid Map
    void Graph_Grid_Map_Init();

    //Graph init Metadata
    void Graph_Metadata_Init();

    //Graph load Map
    void Graph_Load_Map();

    //Function: Get all path
    void printAllPaths(int s, int d);

    //Function: Get all path utils
    void printAllPathsUtil(int u, int d, bool visited[], int path[], int& path_index);

    //Function: Add Edge to Graph -- Use when init graph with Adjacency List
    void AddEdge(int start_node_index, int end_node_index, bool node);

    //Function: Draw path
    void DrawLinePath(vector<int> arr_index, int thickness);

public:
    //Graph Constructor
    Graph(int V_count);

    //Graph Default Constructor
    Graph();

    //Graph Destruction
    ~Graph();

    // Function: Get number of node
    int Vertice_Count();

    // Function: Showing Adjacency Matrix
    void Graph_Show_Adj_Matrix();

    // Function: Showing Metadata
    void Graph_Show_MetaData(bool position_contain);

    // Function: Showing Adjacency List
    void Graph_Show_Adj_List();

    // Function: Showing Node Adjacency List
    void Graph_Show_Node_Adj_List();

    // Function: Showing Map
    void Graph_Show_Map(bool show_path, int expected_width, int expected_height);

    // Take path test
    vector<int> Graph_Get_Test_Path();

    // Function: PathFinding DFS
    void PathFindingDFS(int start_node_index, int end_node_index);

    // Function: PathFinding BFS
    void PathFindingBFS(int start_node_index, int end_node_index);

    // Function: PathFinding Dijkstra
    void PathFindingDijkstra(int start_node_index, int end_node_index);

    // Function: PathFinding BelmanFord
    void PathFindingBelmanFord(int start_node_index, int end_node_index);
};

#endif