#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

void parallelDFS(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    #pragma omp parallel for
    for (int i = 0; i < graph[node].size(); ++i) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            #pragma omp critical
            if (!visited[neighbor])  // Double-check in critical section
                parallelDFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices);
    cout << "Enter edges (from to):\n";
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int startNode;
    cout << "Enter starting node for DFS: ";
    cin >> startNode;

    vector<bool> visited(vertices, false);
    cout << "DFS Traversal: ";
    parallelDFS(startNode, graph, visited);
    cout << endl;
}
