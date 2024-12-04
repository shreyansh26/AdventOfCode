#include <bits/stdc++.h>

using namespace std;

bool check_bounds(vector<vector<char>> &grid, int i, int j, int m, int n, char ch) {
    return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == ch;
}

int find_count(vector<vector<char>> &grid, int i, int j, int m, int n) {
    int count = 0;
    for(int di=-1; di<=1; di++) {
        for(int dj=-1; dj<=1; dj++) {
            if(check_bounds(grid, i + di, j + dj, m, n, 'M') and check_bounds(grid, i + 2*di, j + 2*dj, m, n, 'A') and check_bounds(grid, i + 3*di, j + 3*dj, m, n, 'S')) {
                count += 1;
            }
        }
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
