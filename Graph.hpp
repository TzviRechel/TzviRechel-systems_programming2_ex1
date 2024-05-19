// 316289495
// tzvirechel@gmail.com

#pragma once

#include <vector>
#include <iostream>

namespace ariel{

    class Graph{
        private:
            std::vector<std::vector<int>> _graph;
            bool _isDirected = false;

        public: 
            // Load the graph from the given adjacency matrix  
            void loadGraph(std::vector<std::vector<int>> graph);

            // Print the number of vertices and edges in the graph
            void printGraph();

            // Return the number of vertices in the graph
            int numOfVertices();

            // Get the adjacency matrix that represents the graph
            std::vector<std::vector<int>> getMatrix();

            // Check if the graph is directed
            bool isDirected();
    };
}
