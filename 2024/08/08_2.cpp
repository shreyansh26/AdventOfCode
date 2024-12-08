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

            if(bounds_check(x1, y1, m, n)) {
                antinodes.insert({x1, y1});
            }
            if(bounds_check(x2, y2, m, n)) {
                antinodes.insert({x2, y2});
            }
            
            while(bounds_check(x2 + diff_x, y2 + diff_y, m, n)) {
                x2 += diff_x;
                y2 += diff_y;
                antinodes.insert({x2, y2});
            }

            while(bounds_check(x1 - diff_x, y1 - diff_y, m, n)) {
                x1 -= diff_x;
                y1 -= diff_y;
                antinodes.insert({x1, y1});
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