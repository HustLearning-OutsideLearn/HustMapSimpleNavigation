#include "Graph.h"

int isNotVisited(int x, vector<int>& path)
{
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return 0;
    return 1;
}

vector<int> Graph::PathFindingBFS(int start_node_index, int end_node_index) {
    //restore to base 
    int start = start_node_index - 1;
    int end = end_node_index - 1;

    vector<vector<int>> paths;
    queue<vector<int>> q;

    // path vector to store the current path
    vector<int> path;
    path.push_back(start);
    q.push(path);


    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        // if last vertex is the desired destination
        // then print the path
        if (last == end)
            paths.push_back(path);

        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        list<int>::iterator i;
        for (i = adj_lst[last].begin(); i != adj_lst[last].end(); i++) {
            if (isNotVisited((*i), path)) {
                vector<int> newpath(path);
                newpath.push_back((*i));
                q.push(newpath);
            }
        }
    }

    //Show all paths
    /*for (int i = 0; i < paths.size(); i++) {
        for (int j = 0; j < paths[i].size(); j++) {
            cout << paths[i][j] << " -> ";
        }
        cout << endl;
    }*/

    int min = 0;
    double min_sum = 1000;
    for (int i = 0; i < paths.size(); i++) {
        double sum = 0;
        for (int j = 0; j < paths[i].size() - 1; j++) {
            int curr = paths[i][j];
            int next = paths[i][j + 1];
            sum += adj_matrix[curr][next];
        }
        if (sum < min_sum) {
            min_sum = sum;
            min = i;
        }
    }

    vector<int> output_path = paths[min];
    
    // Show the shortest path
    cout << "The path found by BFS is: " << endl;
    for (int i = 0; i < output_path.size(); i++) {
        cout << output_path[i] << " <- ";
    }
    cout << "\n" << endl;

    return output_path;
}