// 316289495
// tzvirechel@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"


using namespace std;
    TEST_CASE("Test LoadGraph and GetMatrix") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};   
        g.loadGraph(graph)
        CHECK(g.numOfVertices() == 3);
        auto matrix = g.getMatrix();
        CHECK(matrix.size() == 3);
        CHECK(matrix[0] == std::vector<int>{0, 1, 0});
        CHECK(matrix[1] == std::vector<int>{1, 0, 1});
        CHECK(matrix[2] == std::vector<int>{0, 1, 0});
    }

    TEST_CASE("Test invalid graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0}
    };
    CHECK_THROWS(g.loadGraph(graph));
}

    TEST_CASE("Test Directed Graph") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 2, -5},
        {2, 0, 3}, 
        {-5, 3, 0}}; 
        g.loadGraph(graph);
        CHECK(g.isDirected() == false);
        graph = {
        {0, 2, -5},
        {2, 0, 3}, 
        {4, 3, 0}}; 
        g.loadGraph(graph);
        CHECK(g.isDirected() == true);
    }

    TEST_CASE("Test isConnected") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 1);
        graph = {
        {0, 1, 0},
        {0, 0, 1}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 0);
    }

    TEST_CASE("Test shortestPath") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {0, 0, -3, 2}, 
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        };
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
        CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "-1");
        CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 4));
    }

    TEST_CASE("Test isContainsCycle") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1}, 
        {1, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");
    }    

    TEST_CASE("cycles in directed and undirected graphs"){
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 3}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");
        graph = {
        {0, 1, 0},
        {1, 0, 0}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    }

    TEST_CASE("Test isBipartite") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1}, 
        {0, 1, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
        graph = {
        {0, 1, 1},
        {1, 0, 1}, 
        {1, 1, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isBipartite(g) == "0");
    }

    TEST_CASE("Test negativeCycle") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, -1, 0},
        {0, 0, -1}, 
        {-1, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::negativeCycle(g) == "0->1->2->0");
      
    }

    TEST_CASE("negative cycles in directed and undirected graphs"){
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, -2, 0},
        {-1, 0, 2}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::negativeCycle(g) == "1->0->1");
        graph = {
        {0, -2, 0},
        {-2, 0, 0}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::negativeCycle(g) == "0");
    }

    //Testing Algorithms Class Edge Cases"

    TEST_CASE("unload Graph") {
        ariel::Graph g;
        CHECK_THROWS(ariel::Algorithms::isConnected(g));
        CHECK_THROWS(ariel::Algorithms::isContainsCycle(g));
        CHECK_THROWS(ariel::Algorithms::isBipartite(g));
        CHECK_THROWS(ariel::Algorithms::negativeCycle(g));
    }

    TEST_CASE("Single Vertex Graph") {
        ariel::Graph g;
        vector<vector<int>> graph = {{0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 1);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
        CHECK(ariel::Algorithms::isBipartite(g) == "0");
        CHECK(ariel::Algorithms::negativeCycle(g) == "0");
        graph = {{1}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 1);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0->0");
        CHECK(ariel::Algorithms::isBipartite(g) == "0");
        CHECK(ariel::Algorithms::negativeCycle(g) == "0");
        graph = {{-1}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 1);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "-1");
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0->0");
        CHECK(ariel::Algorithms::isBipartite(g) == "0");
        CHECK(ariel::Algorithms::negativeCycle(g) == "0->0");
    }

    TEST_CASE("Empty Graph") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0}, 
        {0, 0, 0}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 0);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
        CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1, 2}");
        CHECK(ariel::Algorithms::negativeCycle(g) == "0");
    }

    TEST_CASE("Self-loops") {
        ariel::Graph g;
        vector<vector<int>> graph = {
        {2, 0, 0},
        {0, -3, 0}, 
        {0, 0, 1}};
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isConnected(g) == 0);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0->0");
        CHECK(ariel::Algorithms::isBipartite(g) == "0");
        CHECK(ariel::Algorithms::negativeCycle(g) == "1->1");
    }

