#include <bits/stdc++.h>

using namespace std;

map<string, int> dir_map = {
    {"up", 0},
    {"right", 1}, 
    {"down", 2},
    {"left", 3}
};

void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, string dir) {
    set<pair<int, int>> past_states;
    map<string, vector<int>> dir_path = {
        {"up", {-1, 0}}, 
        {"right", {0, 1}},
        {"down", {1, 0}},
        {"left", {0, -1}}
    };

    while(1) {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;

        if(grid[i][j] == '#') {
            if(dir == "up") {
                dir = "right";
                i++; // move back to the previous position
            }
            else if(dir == "right") {
                dir = "down";
                j--; // move back to the previous position
            }
            else if(dir == "down") {
                dir = "left";
                i--; // move back to the previous position
            }
            else if(dir == "left") {
                dir = "up";
                j++; // move back to the previous position
            }
        }
        else {
            past_states.insert({i, j});
            grid[i][j] = 'X';
            i += dir_path[dir][0];
            j += dir_path[dir][1];
        }
    }
}

bool dfs2(vector<vector<char>> &grid, int i, int j, int m, int n, string dir) {
    map<pair<pair<int, int>, int>, int> past_states;
    map<string, vector<int>> dir_path = {
        {"up", {-1, 0}}, 
        {"right", {0, 1}},
        {"down", {1, 0}},
        {"left", {0, -1}}
    };

    while(1) {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if(grid[i][j] == '#') {
            if(dir == "up") {
                dir = "right";
                i++; // move back to the previous position
            }
            else if(dir == "right") {
                dir = "down";
                j--; // move back to the previous position
            }
            else if(dir == "down") {
                dir = "left";
                i--; // move back to the previous position
            }
            else if(dir == "left") {
                dir = "up";
                j++; // move back to the previous position
            }
        }
        else {
            if(past_states.find({{i, j}, dir_map[dir]}) != past_states.end()) {
                return true;
            }
            else {
                past_states[{{i, j}, dir_map[dir]}] = 1;
            }

            i += dir_path[dir][0];
            j += dir_path[dir][1];
        }
    }
    return false;
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

    int iniX = -1;
    int iniY = -1;

    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '^') {
                iniX = i;
                iniY = j;
                break;
            }
        }
    }
    
    dfs(grid, iniX, iniY, m, n, "up");

    int count = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'X') {
                grid[i][j] = '#';
                if(dfs2(grid, iniX, iniY, m, n, "up")) {
                    count++;
                }
                grid[i][j] = 'X';
            }
        }
    }

    cout << count << endl;
}
