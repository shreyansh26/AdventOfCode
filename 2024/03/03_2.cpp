#include <bits/stdc++.h>

using namespace std;

pair<long long, bool> find_sum(string line, bool enabled) {
    regex mul_regex = regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    regex do_regex = regex(R"(do\(\))");
    regex dont_regex = regex(R"(don't\(\))");
    smatch match;
    long long sum = 0;
    
    size_t pos = 0;
    while(pos < line.length()) {
        string remaining = line.substr(pos);

        if(regex_search(remaining, match, do_regex)) {
            if(match.position() == 0) {
                enabled = true;
                pos += match.length();
                continue;
            }
        }

        if(regex_search(remaining, match, dont_regex)) {
            if(match.position() == 0) {
                enabled = false;
                pos += match.length();
                continue;
            }
        }
        
        // Check for mul instructions
        if(regex_search(remaining, match, mul_regex)) {
            if(match.position() == 0) {
                if(enabled) {
                    sum += ((long long)stoi(match[1])) * stoi(match[2]);
                }
                pos += match.length();
                continue;
            }
        }
        pos++;
    }

    return {sum, enabled};
}

int main() {
    ifstream fin("input1.txt");
    string line;
    long long tot_sum = 0;
    bool enabled = true;
    string comb_line = "";

    while(getline(fin, line)) {
        auto ans = find_sum(line, enabled);
        tot_sum += ans.first;
        enabled = ans.second;
    }
    fin.close();

    cout << tot_sum << endl;
}
