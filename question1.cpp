
// Author: Nolan
// Student ID: 1113543
// Date of Submission: 2024/12/12
#include <iostream>
#include <vector>
using namespace std;

// Function to create and return an adjacency list for an undirected graph
vector<vector<int>> create_adjacency_list(int V, const vector<pair<int, int>>& edges) {
    // Initialize an empty adjacency list with V empty vectors
    vector<vector<int>> adjacency_list(V);

    for (const auto& edge : edges) {
        int u = edge.first;  // First vertex of the edge
        int v = edge.second; // Second vertex of the edge

        adjacency_list[u].push_back(v);  // Add v to u's adjacency list
        adjacency_list[v].push_back(u);  // Add u to v's adjacency list (undirected graph)
    }

    return adjacency_list;
}

int main() {
    // Prompt user for input
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;  // Number of vertices

    cout << "Enter the number of edges: ";
    cin >> E;  // Number of edges

    vector<pair<int, int>> edges;
    cout << "Enter each edge as a pair of space-separated integers (u v):" << endl;

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;  // Read each edge
        edges.emplace_back(u, v);
    }

    // Call the function to create the adjacency list
    vector<vector<int>> adjacency_list = create_adjacency_list(V, edges);

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjacency_list.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : adjacency_list[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
