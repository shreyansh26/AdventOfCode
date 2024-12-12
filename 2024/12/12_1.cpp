#include <bits/stdc++.h>

using namespace std;

bool perimeter_check(vector<vector<char>> &grid, int i, int j, int m, int n, char curr) {
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != curr) {
        return true;
    }
    return false;
}

int perimeter_factor(vector<vector<char>> &grid, int i, int j, int m, int n, char curr) {
    int perimeter = 0;
    if(perimeter_check(grid, i + 1, j, m, n, curr)) {
        perimeter += 1;
    }
    if(perimeter_check(grid, i - 1, j, m, n, curr)) {
        perimeter += 1;
    }
    if(perimeter_check(grid, i, j - 1, m, n, curr)) {
        perimeter += 1;
    }
    if(perimeter_check(grid, i, j + 1, m, n, curr)) {
        perimeter += 1;
    }

    return perimeter;
}

void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, vector<vector<bool>> &visited, char curr, int &perimeter, int &area) {
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        return;
    }

    if(grid[i][j] != curr) {
        return;
    }

    visited[i][j] = true;

    perimeter += perimeter_factor(grid, i, j, m, n, curr);
    area += 1;

    dfs(grid, i + 1, j, m, n, visited, curr, perimeter, area);
    dfs(grid, i - 1, j, m, n, visited, curr, perimeter, area);
    dfs(grid, i, j + 1, m, n, visited, curr, perimeter, area);
    dfs(grid, i, j - 1, m, n, visited, curr, perimeter, area);

    return;
}


int main() {
    ifstream fin("input1.txt");
    string line;

    vector<vector<char>> grid;

    while(getline(fin, line)) {
        vector<char> row;
        for(size_t i = 0; i < line.size(); i++) {
            row.push_back(line[i]);
        }
        grid.push_back(row);
    }

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    long long ans = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                int perimeter = 0;
                int area = 0;
                dfs(grid, i, j, m, n, visited, grid[i][j], perimeter, area);
                ans += (long long)perimeter * area;
            }
        }
    }

    cout << ans << endl;
}