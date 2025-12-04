#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, E;
    cin >> N >> K >> E;

    vector<vector<pair<int,int>>> adj(N+1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;

    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    pq.push({0, K});

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int nxt = edge.first, w = edge.second;
            if (dist[node] + w < dist[nxt]) {
                dist[nxt] = dist[node] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
    return 0;
}
