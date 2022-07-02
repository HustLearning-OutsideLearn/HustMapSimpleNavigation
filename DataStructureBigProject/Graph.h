#include <iostream>
#include <list>
#include <stack>
using namespace std;

#ifndef Graph_H
#define Graph_H

struct node{
    int x;
    int y;
    float weight;
};

class Graph
{
private:
    
    list<struct node> adj_lst;

public:
    Graph(int V_count);
    void AddEdge(int index, struct node * _node);
};

#endif