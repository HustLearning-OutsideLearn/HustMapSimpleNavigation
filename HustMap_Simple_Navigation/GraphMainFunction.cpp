#include "Graph.h"

using namespace std;

void Graph::AddEdge(int start_node_index, int end_node_index) {
    adj_lst[start_node_index].push_back(end_node_index);
}

void Graph::DrawLinePath(vector<int> arr_index, int thickness) {
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







