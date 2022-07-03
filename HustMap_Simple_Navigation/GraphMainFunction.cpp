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

void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[vertice_count];

    // Create an array to store paths
    int* path = new int[vertice_count];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < vertice_count; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int& path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        vector<int> base = {};
        for (int i = 0; i < path_index; i++)
        {
            //cout << path[i] + 1 << " ";
            base.push_back(path[i] + 1);
        }
        current_path.push_back(base);
        //cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj_lst[u].begin(); i != adj_lst[u].end(); ++i)
            if (!visited[(*i)])
                printAllPathsUtil((*i), d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

void Graph::PathFindingDFS(int start_node_index, int end_node_index) {
    printAllPaths(start_node_index-1, end_node_index-1);

    int min = 0;
    float min_sum = 1000;
    for (int i = 0; i < current_path.size(); i++) {
        float sum = 0;
        for (int j = 0; j < current_path[i].size()-1; j++) {
            sum += adj_matrix[j][j+1];
            if (sum < min_sum) {
                min_sum = sum;
                min = i;
            }
        }
    }

    DrawLinePath(current_path[min], 40);
    Graph_Show_Map(true, 700, 500);
}







