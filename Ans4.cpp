#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<vector<bool>> transitiveClosure;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>(V, 0));
        transitiveClosure.resize(V, vector<bool>(V, false));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
    }

    void DFSUtil(int src, int dest) {
        transitiveClosure[src][dest] = true;

        for (int i = 0; i < V; ++i) {
            if (adj[dest][i] && !transitiveClosure[src][i]) {
                DFSUtil(src, i);
            }
        }
    }

    void computeTransitiveClosure() {
        for (int i = 0; i < V; ++i) {
            DFSUtil(i, i); // Include self loops
        }
    }

    void printTransitiveClosure() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << transitiveClosure[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    graph.computeTransitiveClosure();

    cout << "Transitive Closure Matrix:" << endl;
    graph.printTransitiveClosure();

    return 0;
}
