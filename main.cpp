// 316289495
// tzvirechel@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <vector>
using ariel::Algorithms;
using namespace std;

int main() {
    // Create a graph object
    ariel::Graph graph;

    // Define an adjacency matrix representing a graph
    std::vector<std::vector<int>> adjMatrix1 = {
        {0, 2, 0},
        {1, 0, 3}, 
        {0, -4, 2}
        };

    // Load the graph into the object
    graph.loadGraph(adjMatrix1);

    // Print the graph details
    graph.printGraph();
    cout << "is connected: " << Algorithms::isConnected(graph) << endl;
    cout << "Shortest path: " << Algorithms::shortestPath(graph, 0, 2) << endl;
    cout << "isContainsCycle: " << Algorithms::isContainsCycle(graph) << endl; 
    cout << "isBipartite: " << Algorithms::isBipartite(graph) << endl;
    cout << "negativeCycle: " << Algorithms::negativeCycle(graph) << endl;

    std::vector<std::vector<int>> adjMatrix2 = {
            {0, 2, -1, 5},
            {0, 6, 0, -9},
            {2, 0, 6, 3}, 
            {5, 3, -9, 0}
            };

        // Load the graph into the object
        graph.loadGraph(adjMatrix2);

        // Print the graph details
        graph.printGraph();
        cout << "is connected: " << Algorithms::isConnected(graph) << endl;
        cout << "Shortest path: " << Algorithms::shortestPath(graph, 0, 2) << endl;
        cout << "isContainsCycle: " << Algorithms::isContainsCycle(graph) << endl; 
        cout << "isBipartite: " << Algorithms::isBipartite(graph) << endl;
       cout << "negativeCycle: " << Algorithms::negativeCycle(graph) << endl;

    std::vector<std::vector<int>> adjMatrix3 = {
            {0, -10, 0, 5, 0},
            {-10, 0, -2, 0, 0},
            {0, -2, 0, -1, 0}, 
            {5, 0, -1, 0, 0},
            {0, 0, 0, 0, 0}
            };

        // Load the graph into the object
        graph.loadGraph(adjMatrix3);

        // Print the graph details
        graph.printGraph();
        cout << "is connected: " << Algorithms::isConnected(graph) << endl;
        cout << "Shortest path: " << Algorithms::shortestPath(graph, 0, 2) << endl;
        cout << "isContainsCycle: " << Algorithms::isContainsCycle(graph) << endl; 
        cout << "isBipartite: " << Algorithms::isBipartite(graph) << endl;
       cout << "negativeCycle: " << Algorithms::negativeCycle(graph) << endl;




    return 0;
}