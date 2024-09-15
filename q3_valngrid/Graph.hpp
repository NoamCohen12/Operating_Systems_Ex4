#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
   public:
    std::vector<std::list<int>> vec_list;
    int V, E;
    std::vector<int> in_degree, out_degree;
    Graph(int V, int E);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void printGraph();
    
    bool isConnected();
    bool isEulerianCircuit();
};
vector<int> find_Euler_Circuit(Graph& g, int V, int E);
void print_Euler_Circuit(const vector<int>& euler_circuit);

#endif  // GRAPH_HPP
