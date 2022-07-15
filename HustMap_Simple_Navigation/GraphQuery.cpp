#include "Graph.h"

using namespace std;

void Graph::Graph_Show_Adj_Matrix() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::Graph_Show_MetaData(bool position_contain) {
    if (position_contain) {
        for (int i = 0; i < meta_content.size(); i++) {
            for (int j = 0; j < meta_content[i].size(); j++) {
                cout << meta_content[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < meta_content.size(); i++) {
            cout << "Position " << meta_content[i][0] << ": " << meta_content[i][3] << endl;
        }
    }
}

int Graph::Vertice_Count() {
    return vertice_count;
}

void Graph::Graph_Show_Map(bool show_path, int expected_width, int expected_height) {
    Mat resized_img;
    if (show_path) {
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

void Graph::Graph_Show_Adj_List() {
    for (int i = 0; i < vertice_count; i++) {
        cout << i + 1 << " -> [ ";
        list<int>::iterator it;
        list<int> base_lst = adj_lst[i];
        for (it = base_lst.begin(); it != base_lst.end(); it++) {
            cout << (*it) + 1 << " ";
        }
        cout << "]";
        if (i % 4 == 0) {
            cout << endl;
        }
        else {
            cout << "       ";
        }
    }
    cout << endl;
}

void Graph::Graph_Show_Node_Adj_List() {
    for (int i = 0; i < vertice_count; i++){
        cout << i + 1 << " -> ";
        list<node>::iterator it;
        list<node> base_lst = node_adj_lst[i];
        for (it = base_lst.begin(); it != base_lst.end(); it++) {
            cout << "[ " << (*it).dest + 1 << ", " << (*it).cost << "]  ";
        }
        cout << endl;
    }
}