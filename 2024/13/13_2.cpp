#include <bits/stdc++.h>

using namespace std;

struct Button {
    int x, y;
};

struct Game {
    Button a, b;
    long long prize_x, prize_y;
};

long long gcd_func(long long a, long long b) {
    while(b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long get_min_steps(Game game) {
    long long A = game.a.x;
    long long B = game.b.x;
    long long C = game.prize_x;
    long long D = game.prize_y;

    // Compute determinant
    long long det = A * game.b.y - game.a.y * B;

    // Either no solution or infinitely many solutions
    if(det == 0){
        // Check if the system has infinitely many solutions
        if(A * D != game.a.y * C){
            return LLONG_MAX; // No solution
        }
        // Find a particular solution
        // Let's iterate over possible a to find a valid b
        long long min_cost = LLONG_MAX;
        // To avoid large iterations, solve for a in terms of b or vice versa
        // a = (C - B * b) / A
        // Must satisfy a >=0 and integer
        // Similarly, D = game.a.y * a + game.b.y * b
        // Substitute a:
        // D = game.a.y * (C - B * b) / A + game.b.y * b
        // Multiply all by A to avoid fractions:
        // D * A = game.a.y * (C - B * b) + game.b.y * b * A
        // D * A = game.a.y * C - game.a.y * B * b + game.b.y * A * b
        // b * (game.b.y * A - game.a.y * B) = D * A - game.a.y * C
        // If game.b.y * A == game.a.y * B, we've already handled det==0
        // So, it's safe to iterate a
        // However, to keep it efficient, limit a to a reasonable range
        long long max_a = C / A;
        for(long long a = 0; a <= max_a; a++) {
            if((C - A * a) % B != 0) continue;
            long long b = (C - A * a) / B;
            if(b < 0) continue;
            // Check y equation
            if(game.a.y * a + game.b.y * b == D){
                long long cost = 3 * a + b;
                if(cost < min_cost){
                    min_cost = cost;
                }
            }
        }
        return min_cost;
    }
    else{
        // Unique solution
        // Compute a and b
        // a = (C * game.b.y - D * B) / det
        // b = (A * D - game.a.y * C) / det
        // They must be integers and non-negative
        if((C * game.b.y - D * B) % det != 0 || (A * D - game.a.y * C) % det != 0){
            return LLONG_MAX; // No integer solution
        }
        long long a = (C * game.b.y - D * B) / det;
        long long b = (A * D - game.a.y * C) / det;
        if(a < 0 || b < 0){
            return LLONG_MAX; // Negative presses not allowed
        }
        return 3 * a + b;
    }
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
        sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &game.prize_x, &game.prize_y);

        game.prize_x += 10000000000000;
        game.prize_y += 10000000000000;
        
        games.push_back(game);

        getline(fin, line);

        // cout << game.a.x << " " << game.a.y << " " << game.b.x << " " << game.b.y << " " << game.prize_x << " " << game.prize_y << endl;

        long long min_steps = get_min_steps(game);
        if(min_steps == LLONG_MAX) {
            continue;
        }
        else {
            ans += min_steps;
        }
        // cout << min_steps << endl;
    }
    fin.close();

    cout << ans << endl;

    return 0;
}