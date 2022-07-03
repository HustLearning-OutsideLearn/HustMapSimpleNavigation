#include "Graph.h"

void Graph::Graph_Show_Adj_Matrix() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::Graph_Show_Adj_List() {
    cout << "Hello World" << endl;
}

int Graph::Vertice_Count() {
    return vertice_count;
}

void Graph::Node_Info_Query(int index) {

}

void Graph::Edge_Info_Query(int start_node_index, int end_node_index) {

}