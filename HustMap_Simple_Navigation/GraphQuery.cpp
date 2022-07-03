#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Graph::Graph_Show_Adj_Matrix() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::Graph_Show_Adj_List() {
    cout << "Got here";
    for (int i = 0; i < vertice_count; i++) {
        list<edge*> base_lst = adj_lst[i];
        for (list<edge*>::iterator it = base_lst.begin(); it != base_lst.end(); it++) {
            edge * edge_base = (*it);
            node* start_node = edge_base->inital_point;
            node* end_node = edge_base->final_point;
            float weight = edge_base->weight;
            cout 
                << "(" 
                << start_node->index 
                << "->" 
                << end_node->index 
                << ")";
        }
        cout << endl;
    }
}

void Graph::Graph_Show_MetaData() {
    for (int i = 0; i < meta_content.size(); i++) {
        for (int j = 0; j < meta_content[i].size(); j++) {
            cout << meta_content[i][j] << " ";
        }
        cout << "\n";
    }
}

int Graph::Vertice_Count() {
    return vertice_count;
}

void Graph::Node_Info_Query(int index) {

}

void Graph::Edge_Info_Query(int start_node_index, int end_node_index) {

}

void Graph::Graph_Show_Map(bool show_path, int expected_width, int expected_height, int thickness) {
    Mat resized_img;
    if (show_path) {
        DrawLinePath(Graph_Get_Test_Path(), thickness);
        resize(map_path_img, resized_img, Size(expected_width, expected_height), INTER_LINEAR);
        imshow("Hust Map", resized_img);
        waitKey(0);
    }
    else {
        resize(map_img, resized_img, Size(expected_width, expected_height), INTER_LINEAR);
        imshow("Hust Map", resized_img);
        waitKey(0);
    }
}

vector<int> Graph::Graph_Get_Test_Path() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 21, 20, 19, 18, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> output;
    for (int i = 0; i < size; i++) {
        output.push_back(arr[i]);
    }
    return output;
}