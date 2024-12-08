#include <bits/stdc++.h>

using namespace std;

bool bounds_check(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void calculate_antinode(vector<pair<int, int>> &antennas, set<pair<int, int>> &antinodes, int m, int n) {
    for (size_t i = 0; i < antennas.size(); i++) {
        for (size_t j = i + 1; j < antennas.size(); j++) {
            int x1 = antennas[i].first, y1 = antennas[i].second;
            int x2 = antennas[j].first, y2 = antennas[j].second;
            
            int diff_x = x2 - x1;
            int diff_y = y2 - y1;
            int new_x2 = x2 + diff_x;
            int new_y2 = y2 + diff_y;

            int new_x1 = x1 - diff_x;
            int new_y1 = y1 - diff_y;
            
            if(bounds_check(new_x1, new_y1, m, n)) {
                antinodes.insert({new_x1, new_y1});
            }
            if(bounds_check(new_x2, new_y2, m, n)) {
                antinodes.insert({new_x2, new_y2});
            }
        }
    }
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
    fin.close();

    int m = grid.size();
    int n = grid[0].size();

    map<char, vector<pair<int, int>>> antenna_map;
    set<pair<int, int>> antinodes;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] != '.') {
                antenna_map[grid[i][j]].push_back({i, j});
            }
        }
    }

    for(auto &antenna : antenna_map) {
        calculate_antinode(antenna.second, antinodes, m, n);
    }

    cout << antinodes.size() << endl;
}