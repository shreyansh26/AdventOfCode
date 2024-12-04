#include <bits/stdc++.h>

using namespace std;

bool check_bounds(vector<vector<char>> &grid, int i, int j, int m, int n, char ch) {
    return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == ch;
}

int find_count(vector<vector<char>> &grid, int i, int j, int m, int n) {
    int count = 0;
    if(not check_bounds(grid, i, j, m, n, 'A')) {
        return 0;
    }

    if(grid[i + 1][j + 1] == 'M' and grid[i - 1][j - 1] == 'S') {
        if(grid[i + 1][j - 1] == 'S' and grid[i - 1][j + 1] == 'M') {
            count += 1;
        }
        else if(grid[i + 1][j - 1] == 'M' and grid[i - 1][j + 1] == 'S') {
            count += 1;
        }
    }

    if(grid[i - 1][j - 1] == 'M' and grid[i + 1][j + 1] == 'S') {
        if(grid[i + 1][j - 1] == 'S' and grid[i - 1][j + 1] == 'M') {
            count += 1;
        }
        else if(grid[i + 1][j - 1] == 'M' and grid[i - 1][j + 1] == 'S') {
            count += 1;
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

    for(int i=1; i<m-1; i++) {
        for(int j=1; j<n-1; j++) {
            if(grid[i][j] == 'A') {
                tot_count += find_count(grid, i, j, m, n);
            }
        }
    }

    cout << tot_count << endl;
}
