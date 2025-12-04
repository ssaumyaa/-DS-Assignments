#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (int x : adj[node])
        if (!vis[x])
            dfs(x, adj, vis);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }
    }

    cout << components;
    return 0;
}
