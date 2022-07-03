#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

node* Graph::Node_Instantiation(int index, int pos_x, int pos_y) {
    //cout << "Got Node Creation" << endl;
    node* node_ptr = (node *)malloc(sizeof(node));
    node_ptr->index = index;
    node_ptr->x = pos_x;
    node_ptr->y = pos_y;
    return node_ptr;
}

edge* Graph::Edge_Instantiation(node* start_node, node* end_node, float weight) {
    //cout << "Got Edge Creation" << endl;
    edge* edge_ptr = (edge*)malloc(sizeof(edge));
    edge_ptr->inital_point = start_node;
    edge_ptr->final_point = end_node;
    edge_ptr->weight = weight;
    return edge_ptr;
}

void Graph::AddEdge(int index, edge* _edge) {
    //cout << "Got AddEdge" << endl;
    adj_lst[index].push_back(_edge);
}

void Graph::Graph_Load_Map() {
    map_img = imread(map_path, IMREAD_COLOR);
}

void Graph::DrawLinePath(vector<int> arr_index, int thickness) {
    //cout << "Got Here";
    Mat img_base = map_img;
    for (int i = 0; i < arr_index.size() - 1; i++) {
        int pos_X_initial = stoi(meta_content[arr_index[i]][1]);
        int pos_Y_initial = stoi(meta_content[arr_index[i]][2]);

        int pos_X_final = stoi(meta_content[arr_index[i+1]][1]);
        int pos_Y_final = stoi(meta_content[arr_index[i+1]][2]);

        Point start(pos_X_initial, pos_Y_initial);
        Point end(pos_X_final, pos_Y_final);
        line(img_base, start, end, Scalar(0, 0, 255), thickness, LINE_8);
    }
    map_path_img = img_base;
}

