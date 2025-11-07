#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;

int primMST(int V, vector<vector<pii>> &adj) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[0] = 0;
    pq.push({0, 0});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return totalWeight;
}

int main() {
    int V, E;
    cout << "=============================\n";
    cout << "   Prim's Algorithm Demo\n";
    cout << "=============================\n\n";

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pii>> adj(V);

    cout << "\nEnter " << E << " edges (from to weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    cout << "\nCalculating Minimum Spanning Tree...\n\n";
    int mstWeight = primMST(V, adj);

    cout << "----------------------------------------\n";
    cout << " Total Weight of Minimum Spanning Tree: " << mstWeight << "\n";
    cout << "----------------------------------------\n";

    return 0;
}
