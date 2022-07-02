#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

#ifndef Graph_H
#define Graph_H

// struct node{
//     int index;
//     int x;
//     int y;
// };

class Graph{
private:
    int Vertice_Count;
    list<struct node> Adj_lst;
    vector<vector<float>> Adj_Matrix; // Index of Node starts from 1
    string fname = "Adjacency_Matrix_Preprocess.csv";

    //Graph Init with Adjacency Matrix
    void Graph_Adj_Matrix_Init();

    //Graph Init with Adjacency List
    void Graph_Adj_List_Init();

public:
    //Graph Constructor
    Graph(int V_count);

    //Function: Showing Adjacency Matrix
    void Graph_Show_Adj_Matrix();

    //Function: Showing Adjacency List
    void Graph_Show_Adj_List();

    //Function: Add Edge to Graph -- Use when init graph with Adjacency List
    void AddEdge(int index, struct node * _node);
};

#endif