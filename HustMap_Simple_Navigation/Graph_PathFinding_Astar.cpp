#include "Graph.h"

vector<int> Graph::PathFindingAstar(int start_node_index, int end_node_index) {
    // Restore real index
    int start = start_node_index - 1;
    int end = end_node_index - 1;

    // Mark all the vertices as not visited
    bool* visited = new bool[vertice_count];

    // Create an array to store paths
    int* path = new int[vertice_count];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < vertice_count; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    return AstarFindingMain(start, end, visited, path, path_index);
}

vector<int> Graph::AstarFindingMain(int u, int d, bool visited[], int path[], int& path_index) {
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        vector<int> base = {};
        cout << " The path found by A star is: " << endl;
        for (int i = 0; i < path_index; i++)
        {
            cout << path[i] + 1 << " -> ";
            base.push_back(path[i]);
            return base;
        }
        //current_path.push_back(base);
        //cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        double min_dis = INT_MAX;
        int next_node = 0;
        for (i = adj_lst[u].begin(); i != adj_lst[u].end(); ++i) {
            if (!visited[(*i)]) {
                double baseEuDis = EuclididanDistance((*i), d);
                if (baseEuDis < min_dis) {
                    min_dis = baseEuDis;
                    next_node = *i;
                }
            }
        }
        return AstarFindingMain(next_node, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

double Graph::EuclididanDistance(int first_node, int second_node) {
    stringstream convert;
    convert << meta_content[first_node + 1][1];
    int pos_X_initial;  convert >> pos_X_initial;

    stringstream convert_1;
    convert_1 << meta_content[first_node + 1][2];
    int pos_Y_initial;  convert_1 >> pos_Y_initial;

    stringstream convert_2;
    convert_2 << meta_content[second_node + 1][1];
    int pos_X_final;  convert_2 >> pos_X_final;

    stringstream convert_3;
    convert_3 << meta_content[second_node + 1][2];
    int pos_Y_final;  convert_3 >> pos_Y_final;

    int distance_x = pos_X_final - pos_X_initial;
    int distance_y = pos_Y_final - pos_Y_initial;
    return sqrt(distance_x * distance_x + distance_y * distance_y);
}