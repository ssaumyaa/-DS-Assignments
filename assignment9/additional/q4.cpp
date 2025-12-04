#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& g, int n, int m) {
    if (x<0 || y<0 || x>=n || y>=m || g[x][y]=='0') return;
    g[x][y] = '0';

    dfs(x+1,y,g,n,m);
    dfs(x-1,y,g,n,m);
    dfs(x,y+1,g,n,m);
    dfs(x,y-1,g,n,m);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i, j, grid, n, m);
            }
        }
    }

    cout << count;
    return 0;
}
