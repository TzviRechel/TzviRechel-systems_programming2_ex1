// 316289495
// tzvirechel@gmail.com

#include "Graph.hpp"
#include <iostream>
using namespace std;

void ariel::Graph::loadGraph(vector<vector<int>> graph){
    this->_isDirected = false;
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() != n)
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

    }
    this->_graph = graph;

    // check if the graph is directed
    for (int i = 0; i < n; i++)
    {
        if(_graph[i][i]){_isDirected = true;} // Check for a self-loop at vertex i to determine if the graph is directed
        for (int j = i; j < n; j++){
            if(_graph[i][j]!=_graph[j][i]){
                _isDirected = true;
                break;
            }
        }
        if(_isDirected){break;}
    }
}
void ariel::Graph::printGraph()
{
    int v = _graph.size();
    int edges = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < _graph[i].size(); j++)
        {
            if (_graph[i][j])
            {
                edges++;
            }
        }
    }
    if(!_isDirected){
        edges = edges/2;
        cout << "Undirected graph with " << v << " vertices and " << edges << " edges" << endl;
    }
    else{
    cout << "Directed graph with " << v << " vertices and " << edges << " edges" << endl;
    }
}

int ariel::Graph::numOfVertices()
{
    return this->_graph.size();
}

vector<std::vector<int>> ariel::Graph::getMatrix()
{
    return this->_graph;
}

bool ariel::Graph::isDirected(){
    return this->_isDirected;
}