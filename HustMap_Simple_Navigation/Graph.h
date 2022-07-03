#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <list>
#include <stack>
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
    /*
    * vertice_count (int): store the number of vertice in graph
    * adj_lst:
    *   initial state: list of edge pointer
    *   final state (graph initialization): array of list of edge pointer
    * adj_matrix: 2D vector store the adjacency matrix
    * meta_conttent: 2D vector store the metadatas
    * adj_matrix_path (string): Adjacency Matrix CSV file path
    * meta_path (string): Metadata file path
    * map_path (string): Image of Hust Map file path
    * map_img (Mat): Store the image loaded by open-cv
    * map_path_img (Mat): Store the image contained path drawed by open-cv
    * test_path <vector>: list of index for test the line drawing
    */
    int vertice_count;
    list<edge*> * adj_lst;
    vector<vector<float>> adj_matrix; // Index of Node starts from 1
    vector<vector<string>> meta_content;
    string adj_matrix_path = "Graph\\Adjacency_Matrix_Preprocess.csv";
    string meta_path = "Graph\\Metadata.csv";
    string map_path = "Map\\BK Map.jpg";
    Mat map_img;
    Mat map_path_img;
    vector<int> test_path;
    
    //Graph Init with Adjacency Matrix
    void Graph_Adj_Matrix_Init();

    //Graph Init with Adjacency List
    void Graph_Adj_List_Init();

    //Graph init Metadata
    void Graph_Metadata_Init();

    //Graph load Map
    void Graph_Load_Map();

    //Node Instantiate
    node* Node_Instantiation(int index, int pos_x, int pos_y);

    //Edge Instantiate
    edge* Edge_Instantiation(node* start_node, node* end_node, float weight);

    //Function: Add Edge to Graph -- Use when init graph with Adjacency List
    void AddEdge(int index, edge* _edge);

    //Function: Draw path
    void DrawLinePath(vector<int> arr_index, int thickness);
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

    // Function: Showing Metadata
    void Graph_Show_MetaData();

    // Function: Showing Map
    void Graph_Show_Map(bool show_path, int expected_width, int expected_height, int thichkness);

    vector<int> Graph_Get_Test_Path();
};

#endif