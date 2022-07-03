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
    //adj_lst = new list<edge*>[vertice_count]; // Re init the Adj_Lst
    //Graph_Adj_List_Init();
}

//Graph::Graph() {
//
//}

Graph::~Graph() {

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
        node* temp_start_node = Node_Instantiation(// Work
            head_node_index,
            stoi(meta_content[head_node_index][1]),
            stoi(meta_content[head_node_index][2])
        );
        //cout << temp_start_node->index << " " << temp_start_node->x << " " << temp_start_node->y << endl;

        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] != 0) {
                int temp_final_node_index = j + 1;
                node* temp_final_node = Node_Instantiation( //Work
                    temp_final_node_index,
                    stoi(meta_content[temp_final_node_index][1]),
                    stoi(meta_content[temp_final_node_index][2])
                );
                temp_node = temp_final_node; //Work
                // cout << temp_node->index << " " << temp_node->x << " " << temp_node->y << endl;
                if (!head_contain) {
                    edge* edge_base = Edge_Instantiation(temp_start_node, temp_final_node, adj_matrix[i][j]); //Work
                    // cout << edge_base->final_point->index << " " << edge_base->inital_point->index << " " << endl;
                    AddEdge(head_node_index, edge_base);
                    /*cout << (*adj_lst[head_node_index].begin())->final_point->index
                        << " "
                        <<(*adj_lst[head_node_index].begin())->inital_point->index
                        << endl;*/
                    head_contain = true;
                }
                else {
                    edge* edge_base = Edge_Instantiation(temp_node, temp_final_node, adj_matrix[i][j]);
                    AddEdge(head_node_index, edge_base);
                    /*cout << (*adj_lst[head_node_index].begin())->final_point->index
                        << " "
                        << (*adj_lst[head_node_index].begin())->inital_point->index
                        << endl;*/
                }
            }
        }
        //cout << "Got End of Inner Loop of ADJ_LST Init" << endl;
    }
    cout << "Got End of ADJ_LST Init" << endl;
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