#include "Graph.h"

using namespace std;

void Graph::AddEdge(int start_node_index, int end_node_index, bool node_contain) {
    if (node_contain) {
        node newNode;
        newNode.dest = end_node_index;
        newNode.cost = adj_matrix[start_node_index][end_node_index];
        node_adj_lst[start_node_index].push_back(newNode);
    }
    else {
        adj_lst[start_node_index].push_back(end_node_index);
    }
}

void Graph::DrawLinePath(vector<int> arr_index, int thickness) {

    Mat img_base = map_img;
    for (int i = 0; i < arr_index.size() - 1; i++) {
        stringstream convert;
        convert << meta_content[arr_index[i]+1][1];
        int pos_X_initial;  convert >> pos_X_initial;
        
        stringstream convert_1;
        convert_1 << meta_content[arr_index[i]+1][2];
        int pos_Y_initial;  convert_1 >> pos_Y_initial;

        stringstream convert_2;
        convert_2 << meta_content[arr_index[i+1]+1][1];
        int pos_X_final;  convert_2 >> pos_X_final;

        stringstream convert_3;
        convert_3 << meta_content[arr_index[i+1]+1][2];
        int pos_Y_final;  convert_3 >> pos_Y_final;

        Point start(pos_X_initial, pos_Y_initial);
        Point end(pos_X_final, pos_Y_final);
        line(img_base, start, end, Scalar(0, 0, 255), thickness, LINE_8);
    }
    map_path_img = img_base;
}

void Graph::DrawLinePathAllAlgo(vector<vector<int>> arr_indices) {
    Mat img_base = map_img;
    int thickness[] = { 60, 50, 40, 30, 20 };
    Scalar color[] = { Scalar(0, 0, 255) , Scalar(255, 0, 0), Scalar(0, 255, 0) , Scalar(255,255,0) , Scalar(0,0,0)};
    for (int i = 0; i < arr_indices.size(); i++) {
        for (int j = 0; j < arr_indices[i].size() - 1; j++) {
            stringstream convert;
            convert << meta_content[arr_indices[i][j] + 1][1];
            int pos_X_initial;  convert >> pos_X_initial;

            stringstream convert_1;
            convert_1 << meta_content[arr_indices[i][j] + 1][2];
            int pos_Y_initial;  convert_1 >> pos_Y_initial;

            stringstream convert_2;
            convert_2 << meta_content[arr_indices[i][j + 1] + 1][1];
            int pos_X_final;  convert_2 >> pos_X_final;

            stringstream convert_3;
            convert_3 << meta_content[arr_indices[i][j + 1] + 1][2];
            int pos_Y_final;  convert_3 >> pos_Y_final;

            Point start(pos_X_initial, pos_Y_initial);
            Point end(pos_X_final, pos_Y_final);
            line(img_base, start, end, color[i], thickness[i], LINE_8);
        }
    }
    map_path_img = img_base;
}

void Graph::DrawLinePathAllAlgoMultipleImage(vector<vector<int>> arr_indices, int expected_width, int expected_height) {
    Mat all_mat[5];
    for (int i = 0; i < arr_indices.size(); i++) {
        DrawLinePath(arr_indices[i], 40);
        resize(map_path_img, all_mat[i], Size(expected_width, expected_height), INTER_LINEAR);
    }

    int dstWidth = all_mat[0].cols * 3;
    int dstHeight = all_mat[0].rows * 2;

    cout << "Width: " << dstWidth << endl;
    cout << "Height: " << dstHeight << endl;

    Mat dst = Mat(dstHeight, dstWidth, CV_8UC3, Scalar(0, 0, 0));

    Rect roi_1(Rect(0, 0, all_mat[0].cols, all_mat[0].rows));
    Rect roi_2(Rect(0, all_mat[0].rows, all_mat[0].cols, all_mat[0].rows*2));
    Rect roi_3(Rect(all_mat[0].cols, 0, all_mat[0].cols*2, all_mat[0].rows));
    Rect roi_4(Rect(all_mat[0].cols, all_mat[0].rows, all_mat[0].cols * 2, all_mat[0].rows*2));
    Rect roi_5(Rect(all_mat[0].cols*2, 0, all_mat[0].cols * 3, all_mat[0].rows));

    Rect full_rect[] = {roi_1, roi_2 , roi_3 , roi_4 , roi_5};
    for (int i = 0; i < 5; i++) {
        Mat targetROI = dst(full_rect[i]);
        all_mat[i].copyTo(targetROI);
    }

    /*namedWindow("FullPathWindow");
    imshow("FullPathWindow", dst);
    waitKey(0);*/
}

void Graph::PathFinding(int start_node_index, int end_node_index, string algo) {
    /*
    * algo = "auto": Auto choose the algorithm
    * algo = "all": Using all algorithmn
    * algo = "dfs": Using dfs
    * algo = "bfs": Using bfs
    * algo = "dij": Using Dijkstra
    * algo = "bel": Using Belman Ford
    * algo = "*": Using A star
    */
    
    // Reset Map before draw
    //map_path_img = map_img;


    // Check Algorithm
    if (algo == "auto" || algo == " " || algo == "dij") {
        vector<int> storepath = PathFindingDijkstra(start_node_index, end_node_index);

        DrawLinePath(storepath, 40);
        Graph_Show_Map(true, 700, 500);
    }
    else if (algo == "all") {
        vector<int> storepath_dij = PathFindingDijkstra(start_node_index, end_node_index);
        vector<int> storepath_dfs = PathFindingDFS(start_node_index, end_node_index);
        vector<int> storepath_bfs = PathFindingBFS(start_node_index, end_node_index);
        vector<int> storepath_bel = PathFindingBelmanFord(start_node_index, end_node_index);
        vector<int> storepath_star = PathFindingAstarNonGrid(start_node_index, end_node_index);

        vector<vector<int>> all_paths_found; 
        all_paths_found.push_back(storepath_dij);
        all_paths_found.push_back(storepath_dfs);
        all_paths_found.push_back(storepath_bfs);
        all_paths_found.push_back(storepath_bel);
        all_paths_found.push_back(storepath_star);

        /*DrawLinePathAllAlgo(all_paths_found);
        Graph_Show_Map(true, 1000, 700);*/

        //DrawLinePathAllAlgoMultipleImage(all_paths_found, 700, 500);

        vector<string> window_name{ "Dijkstra", "Deep First Search", "Breadth First Search", "Belman Ford", "A star" };
        for (int i = 0; i < window_name.size(); i++) {
            DrawLinePath(all_paths_found[i], 40);
            Mat img_base;
            resize(map_path_img, img_base, Size(700, 500), INTER_LINEAR);
            imshow(window_name[i], img_base);
        }
        waitKey(0);
    }
    else if (algo == "dfs") {
        vector<int> storepath = PathFindingDFS(start_node_index, end_node_index);

        DrawLinePath(storepath, 40);
        Graph_Show_Map(true, 700, 500);
    }
    else if (algo == "bfs") {
        vector<int> storepath = PathFindingBFS(start_node_index, end_node_index);

        DrawLinePath(storepath, 40);
        Graph_Show_Map(true, 700, 500);
    }
    else if (algo == "bel") {
        vector<int> storepath = PathFindingBelmanFord(start_node_index, end_node_index);

        DrawLinePath(storepath, 40);
        Graph_Show_Map(true, 700, 500);
    }
    else if (algo == "*") {
        vector<int> storepath = PathFindingAstarNonGrid(start_node_index, end_node_index);

        DrawLinePath(storepath, 40);
        Graph_Show_Map(true, 700, 500);
    }
    else {
        cout << "Please type correctly the algo abbreviation in the (...)" << endl;
    }
}







