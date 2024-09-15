#include <unistd.h>  // For getopt

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Graph.hpp"

void generateRandomGraph(Graph &g, int V, int E, int from_user_seed = 0) {
    srand(from_user_seed);
    for (int i = 0; i < E; i++) {
        int u = rand() % V + 1;
        int v = rand() % V + 1;
        g.addEdge(u, v);
    }
}

int main(int argc, char **argv) {
    if (argc < 7) {
        std::cerr << "Usage: " << argv[0] << " -e <value> -v <value> -s <value>\n";
        exit(EXIT_FAILURE);
    }
    int re_val_e = 0;
    int re_val_v = 0;
    int re_val_seed = time(0);  // Default seed with current time

    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                re_val_v = std::stoi(optarg);
                break;
            case 'e':
                re_val_e = std::stoi(optarg);
                break;
            case 's':  // Use 's' for seed
                re_val_seed = std::stoi(optarg);
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -e <value> -v <value> -s <value>\n";
                exit(EXIT_FAILURE);
        }
    }

    if (re_val_v < 0 || re_val_e < 0 || re_val_seed < 0) {
        std::cerr << "Invalid input\n";
        exit(EXIT_FAILURE);
    }

    srand(re_val_seed);  // Seed the random number generator

    int V = re_val_v;
    int E = re_val_e;
    Graph g(V, E);
    generateRandomGraph(g, V, E, re_val_seed);
    g.printGraph();
    vector<int> euler_circuit = find_Euler_Circuit(g, V, E);  // Assuming this function is defined elsewhere
    print_Euler_Circuit(euler_circuit);

    std::cout << "--------------------------------\n";

    Graph g3(2, 2);  // 2 vertices, 2 edges
    g3.addEdge(1, 2);
    g3.addEdge(2, 1);
    g3.printGraph();
    vector<int> euler_circuit2 = find_Euler_Circuit(g3, 2, 2);
    print_Euler_Circuit(euler_circuit2);

    std::cout << "--------------------------------\n";
    Graph g4(4, 4);  // 5 vertices, 4 edges
    g4.addEdge(1, 2);
    g4.addEdge(2, 3);
    g4.addEdge(3, 4);
    g4.addEdge(4, 1);
    // Vertex 4 and 5 are isolated, making the graph disconnected
    g4.printGraph();
    vector<int> euler_circuit3 = find_Euler_Circuit(g4, 4, 4);  // This should trigger the isConnected check
    print_Euler_Circuit(euler_circuit3);

    std::cout << "--------------------------------\n";

    Graph g5(6, 7);  // 6 vertices, 9 edges

    // Adding edges that form an Eulerian circuit
    g5.addEdge(1, 2);
    g5.addEdge(6, 1);
    g5.addEdge(2, 3);
    g5.addEdge(3, 6);
    g5.addEdge(3, 4);
    g5.addEdge(4, 5);
    g5.addEdge(5, 3);

    g5.printGraph();

    vector<int> euler_circuit5 = find_Euler_Circuit(g5, 6, 7);
    print_Euler_Circuit(euler_circuit5);

    std::cout << "--------------------------------\n";

    Graph empty(2, 0);  // 6 vertices, 9 edges

    empty.printGraph();

    vector<int> euler_circuit6 = find_Euler_Circuit(empty, 2, 0);
    print_Euler_Circuit(euler_circuit6);

    std::cout << "--------------------------------\n";
    Graph g8(2, 1);  // 6 vertices, 9 edges
    g8.addEdge(1, 2);

    g8.printGraph();

    vector<int> euler_circuit8 = find_Euler_Circuit(g8, 2, 1);
    print_Euler_Circuit(euler_circuit8);

    std::cout << "--------------------------------\n";
    return 0;
}