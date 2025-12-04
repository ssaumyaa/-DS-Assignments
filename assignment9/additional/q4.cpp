#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& grid, int m, int n) {
    if (r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0') return;

    grid[r][c] = '0';

    dfs(r+1, c, grid, m, n);
    dfs(r-1, c, grid, m, n);
    dfs(r, c+1, grid, m, n);
    dfs(r, c-1, grid, m, n);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(i, j, grid, m, n);
            }
        }
    }

    cout << islands;
    return 0;
}
