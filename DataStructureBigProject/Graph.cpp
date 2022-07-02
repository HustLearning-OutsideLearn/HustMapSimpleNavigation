#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

Graph::Graph(int V_count){
    Vertice_Count = V_count;

    //Initialize the Adjacency Matrix of Graph
    Graph_Adj_Matrix_Init();
}

void Graph::Graph_Adj_Matrix_Init(){
    vector<float> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
 
            stringstream str(line);
 
            while(getline(str, word, ','))
            row.push_back(stof(word));
            Adj_Matrix.push_back(row);
        }       
    } else cout<<"Could not open the file\n";
}

void Graph::Graph_Adj_List_Init(){
    
}

void Graph::Graph_Show_Adj_Matrix(){
    for(int i=0;i<Adj_Matrix.size();i++){
        for(int j=0;j<Adj_Matrix[i].size();j++){
            cout<<Adj_Matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Graph::Graph_Show_Adj_List(){

}

void Graph::AddEdge(int index, node * _node){

}