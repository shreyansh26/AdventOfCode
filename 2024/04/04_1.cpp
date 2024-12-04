#include <bits/stdc++.h>

using namespace std;

bool check_bounds(vector<vector<char>> &grid, int i, int j, int m, int n, char ch) {
    return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == ch;
}

int find_count(vector<vector<char>> &grid, int i, int j, int m, int n) {
    int count = 0;
    // check right
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i, j + 1, m, n, 'M') and check_bounds(grid, i, j + 2, m, n, 'A') and check_bounds(grid, i, j + 3, m, n, 'S')) {
        count += 1;
    }

    // check left
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i, j - 1, m, n, 'M') and check_bounds(grid, i, j - 2, m, n, 'A') and check_bounds(grid, i, j - 3, m, n, 'S')) {
        count += 1;
    }

    // check down
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i + 1, j, m, n, 'M') and check_bounds(grid, i + 2, j, m, n, 'A') and check_bounds(grid, i + 3, j, m, n, 'S')) {
        count += 1;
    }

    // check up
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i - 1, j, m, n, 'M') and check_bounds(grid, i - 2, j, m, n, 'A') and check_bounds(grid, i - 3, j, m, n, 'S')) {
        count += 1;
    }

    // check diagonal down right
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i + 1, j + 1, m, n, 'M') and check_bounds(grid, i + 2, j + 2, m, n, 'A') and check_bounds(grid, i + 3, j + 3, m, n, 'S')) {
        count += 1;
    }

    // check diagonal up right
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i - 1, j + 1, m, n, 'M') and check_bounds(grid, i - 2, j + 2, m, n, 'A') and check_bounds(grid, i - 3, j + 3, m, n, 'S')) {
        count += 1;
    }

    // check diagonal down left
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i + 1, j - 1, m, n, 'M') and check_bounds(grid, i + 2, j - 2, m, n, 'A') and check_bounds(grid, i + 3, j - 3, m, n, 'S')) {
        count += 1;
    }

    // check diagonal up left
    if(check_bounds(grid, i, j, m, n, 'X') and check_bounds(grid, i - 1, j - 1, m, n, 'M') and check_bounds(grid, i - 2, j - 2, m, n, 'A') and check_bounds(grid, i - 3, j - 3, m, n, 'S')) {
        count += 1;
    }

    return count;
}

int main() {
    ifstream fin("input1.txt");
    string line;
    vector<vector<char>> grid;

    while(getline(fin, line)) {
        grid.push_back(vector<char>(line.begin(), line.end()));
    }

    int tot_count = 0;
    int m = grid.size();
    int n = grid[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 'X') {
                tot_count += find_count(grid, i, j, m, n);
            }
        }
    }

    cout << tot_count << endl;
}
