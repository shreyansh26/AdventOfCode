#include <bits/stdc++.h>

using namespace std;

struct Robot {
    long long x, y;
    long long vx, vy;
};

void plot(vector<Robot> &robots) {
    vector<vector<char>> court(103, vector<char>(101, ' '));

    map<pair<long long, long long>, int> mp;
    for(auto robot: robots) {
        mp[{robot.y, robot.x}]++;
    }
    for(auto it: mp) {
        court[it.first.first][it.first.second] = '0' + it.second;
        // cout << it.first.first << " " << it.first.second << " " << it.second << endl;
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

    // plot(robots);

    for(int i=0; i<100; i++) {
        for(auto &robot: robots) {
            robot.x = (robot.x + robot.vx + C) % C;
            robot.y = (robot.y + robot.vy + R) % R;
        }

        // cout << i + 1 << endl;
        // plot(robots);
    }

    long long quad1 = 0;
    long long quad2 = 0;
    long long quad3 = 0;
    long long quad4 = 0;

    for(auto robot: robots) {
        if(robot.x < C/2 and robot.y < R/2) {
            quad1++;
        }
        else if(robot.x < C/2 and robot.y > R/2) {
            quad2++;
        }
        else if(robot.x > C/2 and robot.y < R/2) {
            quad3++;
        }
        else if(robot.x > C/2 and robot.y > R/2) {
            quad4++;
        }
    }
    cout << quad1 << " " << quad2 << " " << quad3 << " " << quad4 << endl;
    cout << quad1 * quad2 * quad3 * quad4 << endl;
}