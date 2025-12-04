#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int cost = cur[0], x = cur[1], y = cur[2];

        if (x == n-1 && y == m-1) break;

        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx>=0 && ny>=0 && nx<n && ny<m) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    cout << dist[n-1][m-1];
    return 0;
}
