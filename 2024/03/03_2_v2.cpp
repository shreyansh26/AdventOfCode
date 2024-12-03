#include <bits/stdc++.h>

using namespace std;

string preprocess(string line) {
    line += "do()";
    regex to_replace = regex(R"(don't\(\)(.*?)do\(\))");
    line = regex_replace(line, to_replace, "");
    return line;
}

long long find_sum(string line) {
    regex mul_regex = regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch match;
    long long sum = 0;

    while(regex_search(line, match, mul_regex)) {
        sum += stoi(match[1]) * stoi(match[2]);
        line = match.suffix();
    }

    return sum;
}

int main() {
    ifstream fin("input1.txt");
    string line;
    long long tot_sum = 0;
    string comb_line = "";

    while(getline(fin, line)) {
        comb_line += line;
    }
    fin.close();

    comb_line = preprocess(comb_line);
    tot_sum = find_sum(comb_line);

    cout << tot_sum << endl;
}
