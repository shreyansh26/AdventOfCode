#include <bits/stdc++.h>

using namespace std;

char get_neighbor(vector<vector<char>> &grid, int i, int j, int m, int n) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return '-';
    }
    return grid[i][j];
}

void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, vector<vector<bool>> &visited, char curr, int &perimeter, int &sides, int &area) {
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        return;
    }

    if(grid[i][j] != curr) {
        return;
    }

    visited[i][j] = true;

    area += 1;

    char n_up = get_neighbor(grid, i - 1, j, m, n);
    char n_down = get_neighbor(grid, i + 1, j, m, n);
    char n_left = get_neighbor(grid, i, j - 1, m, n);
    char n_right = get_neighbor(grid, i, j + 1, m, n);

    if(n_up != curr)
        perimeter += 1;
    if(n_down != curr)
        perimeter += 1;
    if(n_left != curr)
        perimeter += 1;
    if(n_right != curr)
        perimeter += 1;
    

    if(curr != n_left and curr != n_up) 
        sides += 1;
    if(curr != n_up and curr != n_right)
        sides += 1;
    if(curr != n_right and curr != n_down)
        sides += 1;
    if(curr != n_down and curr != n_left)
        sides += 1;

    if((get_neighbor(grid, i-1, j-1, m, n) != curr) and (curr == n_up) and (curr == n_left))
        sides += 1;
    if((get_neighbor(grid, i-1, j+1, m, n) != curr) and (curr == n_up) and (curr == n_right))
        sides += 1;
    if((get_neighbor(grid, i+1, j+1, m, n) != curr) and (curr == n_down) and (curr == n_right))
        sides += 1;
    if((get_neighbor(grid, i+1, j-1, m, n) != curr) and (curr == n_down) and (curr == n_left))
        sides += 1;

    dfs(grid, i + 1, j, m, n, visited, curr, perimeter, sides, area);
    dfs(grid, i - 1, j, m, n, visited, curr, perimeter, sides, area);
    dfs(grid, i, j + 1, m, n, visited, curr, perimeter, sides, area);
    dfs(grid, i, j - 1, m, n, visited, curr, perimeter, sides, area);

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
    long long ans1 = 0, ans2 = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                int sides = 0;
                int perimeter = 0;
                int area = 0;
                dfs(grid, i, j, m, n, visited, grid[i][j], perimeter, sides, area);
                ans1 += (long long)perimeter * area;
                ans2 += (long long)sides * area;
            }
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
}