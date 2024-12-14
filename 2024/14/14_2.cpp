#include <bits/stdc++.h>

using namespace std;

struct Robot {
    long long x, y;
    long long vx, vy;
};

bool check(vector<Robot> &robots) {
    vector<vector<char>> court(103, vector<char>(101, ' '));

    map<pair<long long, long long>, int> mp;
    for(auto robot: robots) {
        mp[{robot.y, robot.x}]++;
    }
    for(auto it: mp) {
        court[it.first.first][it.first.second] = '0' + it.second;
    }

    for(int i=0; i<103; i++) {
        for(int j=0; j<101-10; j++) {
            bool flag = true;
            for(int k=0; k<10; k++) {
                if(court[i][j+k] == ' ') {
                    flag = false;
                    break;
                }
            } 
            if(flag) {
                return true;
            }
        }
    }
    return false;
}

void plot(vector<Robot> &robots) {
    vector<vector<char>> court(103, vector<char>(101, ' '));

    map<pair<long long, long long>, int> mp;
    for(auto robot: robots) {
        mp[{robot.y, robot.x}]++;
    }
    for(auto it: mp) {
        court[it.first.first][it.first.second] = '0' + it.second;
    }
    for(int i=0; i<103; i++) {
        for(int j=0; j<101; j++) {
            cout << court[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream fin("input1.txt");
    string line;
    
    vector<Robot> robots;
    
    while(getline(fin, line)) {
        Robot robot;
        sscanf(line.c_str(), "p=%lld,%lld v=%lld,%lld", &robot.x, &robot.y, &robot.vx, &robot.vy);
        
        robots.push_back(robot);
    }
    fin.close();

    int R = 103;
    int C = 101;

    for(int i=0; i<10000; i++) {
        for(auto &robot: robots) {
            robot.x = (robot.x + robot.vx + C) % C;
            robot.y = (robot.y + robot.vy + R) % R;
        }

        bool long_in_row = check(robots);
        if(long_in_row) {
            cout << i + 1 << endl;
            plot(robots);
            break;
        }
    }
}