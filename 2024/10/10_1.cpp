#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int curr, int &count, vector<vector<bool>> &visited) {
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        return;
    }

    if(grid[i][j] != curr) {
        return;
    }

    if(grid[i][j] == 9) {
        visited[i][j] = true;
        count += 1;
        return;
    }

    visited[i][j] = true;
    dfs(grid, i + 1, j, m, n, curr + 1, count, visited);
    dfs(grid, i - 1, j, m, n, curr + 1, count, visited);
    dfs(grid, i, j + 1, m, n, curr + 1, count, visited);
    dfs(grid, i, j - 1, m, n, curr + 1, count, visited);
}

int main() {
    ifstream fin("input1.txt");
    string line;

    vector<vector<int>> grid;

    while(getline(fin, line)) {
        vector<int> row;
        for(size_t i = 0; i < line.size(); i++) {
            row.push_back(line[i] - '0');
        }
        grid.push_back(row);
    }

    int m = grid.size();
    int n = grid[0].size();

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int count = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 0) {
                visited.assign(m, vector<bool>(n, false));
                dfs(grid, i, j, m, n, 0, count, visited);
            }
        }
    }
    cout << count << endl;
}