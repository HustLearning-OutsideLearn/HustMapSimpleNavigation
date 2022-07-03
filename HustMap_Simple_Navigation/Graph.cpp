#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(int v_count) {
    vertice_count = v_count;

    // Initialize the Adjacency Matrix of Graph
    Graph_Adj_Matrix_Init();

    // Initialize the Metadata_content
    Graph_Metadata_Init();

    // Initialize the Adjacency List
    adj_lst = new list<edge*>[vertice_count]; // Re init the Adj_Lst
    Graph_Adj_List_Init();
}

void Graph::Graph_Adj_Matrix_Init() {
    vector<float> row;
    string line, word;

    fstream file(adj_matrix_path, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(stof(word));
            adj_matrix.push_back(row);
        }
    }
    else cout << "Could not open the file\n";
}

void Graph::Graph_Adj_List_Init() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        int head_node_index = i + 1; //index of the first node of row
        bool head_contain = false; //return True if the row contain the first node 
        node* temp_node; //store the final node of row tracked

        // Create the first node of row
        node* temp_start_node = Node_Instantiation(
            head_node_index, 
            stoi(meta_content[head_node_index][1]), 
            stoi(meta_content[head_node_index][2])
        );

        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] != 0) {
                int temp_final_node_index = j+1;
                node* temp_final_node = Node_Instantiation(
                    temp_final_node_index,
                    stoi(meta_content[temp_final_node_index][1]),
                    stoi(meta_content[temp_final_node_index][2])
                );
                if (!head_contain) {
                    edge* edge_base = Edge_Instantiation(temp_start_node, temp_final_node, adj_matrix[i][j]);
                    AddEdge(head_node_index, edge_base);
                    head_contain = true;
                }
                else {
                    edge* edge_base = Edge_Instantiation(temp_node, temp_final_node, adj_matrix[i][j]);
                    AddEdge(head_node_index, edge_base);
                }
                temp_node = &*temp_final_node;
            }
        }
    }
}

void Graph::Graph_Metadata_Init() {
    vector<string> row;
    string line, word;

    fstream file(meta_path, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
                meta_content.push_back(row);
        }
    }
    else cout << "Could not open the file\n";
}

node* Graph::Node_Instantiation(int index, int pos_x, int pos_y) {
    node node_base;
    node* node_ptr = &node_base;
    node_ptr->index = index;
    node_ptr->x = pos_x;
    node_ptr->y = pos_y;
    return node_ptr;
}

edge* Graph::Edge_Instantiation(node* start_node, node* end_node, float weight) {
    edge edge_base;
    edge* edge_ptr = &edge_base;
    edge_ptr->inital_point = start_node;
    edge_ptr->final_point = end_node;
    edge_ptr->weight = weight;
    return edge_ptr;
}

void Graph::AddEdge(int index, edge* _edge) {
    adj_lst[index].push_back(_edge);
}

