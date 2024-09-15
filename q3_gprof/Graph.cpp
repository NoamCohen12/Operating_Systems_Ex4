#include "Graph.hpp"


Graph::Graph(int V, int E) : V(V), E(E) {
    vec_list.resize(V);
    in_degree.resize(V, 0);
    out_degree.resize(V, 0);
}

void Graph::addEdge(int u, int v) {
    vec_list[u - 1].push_back(v - 1);
    out_degree[u - 1]++;
    in_degree[v - 1]++;
    cout << "added edge from " << u << " to " << v << endl;
}

void Graph::removeEdge(int u, int v) {
    u = u - 1;
    v = v - 1;
    vec_list[u].remove(v);
    out_degree[u]--;
    in_degree[v]--;
    cout << "removed edge from " << u + 1 << " to " << v + 1 << endl;
}

void Graph::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i + 1 << " -> ";
        for (auto it : vec_list[i]) {
            cout << it + 1 << " ";
        }
        cout << endl;
    }
}

bool Graph::isConnected() {
    vector<bool> visited(V, false);
    queue<int> q;

    // Find a vertex with a non-zero degree
    int start = -1;
    for (int i = 0; i < V; ++i) {
        if (!vec_list[i].empty()) {
            start = i;
            break;
        }
    }

    // If no edges in the graph, it's trivially connected
    if (start == -1) {
        return true;
    }

    // BFS to check connectivity
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : vec_list[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Check if all vertices with non-zero degree are visited
    for (int i = 0; i < V; ++i) {
        if (!vec_list[i].empty() && !visited[i]) {
            return false;
        }
    }

    return true;
}

bool Graph::isEulerianCircuit() {
    // Check if the graph is connected
    if (!isConnected()) {
        return false;
    }
    // Check the in-degree and out-degree conditions
    for (int i = 0; i < V; ++i) {
        if (in_degree[i] != out_degree[i]) {
            return false;
        }
    }
    return true;
}


/**
 * Find if there is an Euler Circuit in the graph, if so, return true and print the path
 * @param g Graph object
 * @param V Number of vertices
 * @param E Number of edges
 * @return true if there is an Euler Circuit, false otherwise
 */
vector<int> find_Euler_Circuit(Graph &g, int V, int E) {
    vector<int> euler_circuit;

    if (!g.isEulerianCircuit()) {
        cout << "There is no Euler circuit in the graph" << endl;
        return euler_circuit;
    }

    cout << "There is an Euler circuit in the graph" << endl;

    // Find a starting vertex
    int start = 0;
    for (int i = 0; i < V; ++i) {
        if (!g.vec_list[i].empty()) {
            start = i;
            break;
        }
    }

    // Use stack to store the current path in Eulerian circuit
    stack<int> current_path;
    current_path.push(start);

    while (!current_path.empty()) {
        int u = current_path.top();
        if (!g.vec_list[u].empty()) {
            int v = g.vec_list[u].back();
            g.removeEdge(u + 1, v + 1);
            current_path.push(v);
        } else {
            euler_circuit.push_back(u);
            current_path.pop();
        }
    }

    return euler_circuit;
}

void print_Euler_Circuit(const vector<int>& euler_circuit) {
    if (euler_circuit.empty()) {
        return;
    }

    cout << "The Euler circuit is: ";
    for (auto it = euler_circuit.rbegin(); it != euler_circuit.rend(); ++it) {
        cout << *it + 1 << " ";
    }
    cout << endl;
}
