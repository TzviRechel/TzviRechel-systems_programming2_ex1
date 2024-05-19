# Graphs
This project involves the implementation of a class for representing graphs and various algorithms on graphs. The main files are:

- `graph.cpp` - A class representing a graph using an adjacency matrix. The graph can be directed or undirected, and can also have weights. An undirected graph is represented by a symmetric matrix with zeros along the diagonal.
- `Algorithms.cpp` - A class containing implementations of various algorithms on graphs.
- `main.cpp` - Different examples of input and output of the algorithms.

## Algorithms and Implementation

- `isConnected(g)` - The algorithm takes a graph and returns 1 if the graph is connected (strongly connected for directed graphs). Implemented using breadth-first search.
- `shortestPath(g, start, end)` - The algorithm takes a graph, a starting vertex, and an ending vertex. It returns a string containing the shortest/minimum weight path between the two vertices. If no such path exists, the algorithm returns -1. Implemented using the Floyd-Warshall algorithm.
- `isContainsCycle(g)` - The algorithm takes a graph and returns a string containing any cycle in the graph. If no cycle exists, the algorithm returns 0. Implemented using depth-first search.
- `isBipartite(g)` - The algorithm takes a graph and returns a string containing the bipartition of the graph into a bipartite graph. If the graph cannot be partitioned, the algorithm returns 0. Implemented using breadth-first search.
- `negativeCycle(g)` - The algorithm takes a graph and returns a string containing a negative cycle. If no such cycle exists, the algorithm returns 0. Implemented using the Bellman-Ford algorithm.
