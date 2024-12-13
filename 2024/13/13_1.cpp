#include <bits/stdc++.h>

using namespace std;

struct Button {
    int x, y;
};

struct Game {
    Button a, b;
    int prize_x, prize_y;
};

long long get_min_steps(Game game) {
    long long ans = LLONG_MAX;

    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            long long x = (long long)i * game.a.x + (long long)j * game.b.x;
            long long y = (long long)i * game.a.y + (long long)j * game.b.y;

            if(x == game.prize_x && y == game.prize_y) {
                ans = min(ans, 3LL * i + j);
            }
        }
    }
    return ans;
}

int main() {
    ifstream fin("input1.txt");
    string line;
    
    vector<Game> games;
    long long ans = 0;
    
    while(getline(fin, line)) {
        Game game;
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &game.a.x, &game.a.y);
        
        getline(fin, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &game.b.x, &game.b.y);
        
        getline(fin, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &game.prize_x, &game.prize_y);
        
        games.push_back(game);
        
        getline(fin, line);

        long long min_steps = get_min_steps(game);
        if(min_steps == LLONG_MAX) {
            continue;
        }
        else {
            ans += min_steps;
        }
    }
    fin.close();

    cout << ans << endl;

    return 0;
}