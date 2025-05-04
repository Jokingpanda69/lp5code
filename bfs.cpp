#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>
using namespace std;

void parallelBFS(int startNode, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        #pragma omp parallel for
        for (int i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i];
            #pragma omp critical
            {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
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
    cout << "Enter starting node for BFS: ";
    cin >> startNode;

    cout << "BFS Traversal: ";
    parallelBFS(startNode, graph);
    cout << endl;
}