#include <bits/stdc++.h>

using namespace std;

bool check_validity(set<pair<int, int>> &s, vector<int> &v) {
    for(size_t i = 0; i < v.size(); i++) {
        for(size_t j = i + 1; j < v.size(); j++) {
            if(s.find({v[j], v[i]}) != s.end()) {
                return false;
            }
        }
    }
    return true;
}

void fix(set<pair<int, int>> &s, vector<int> &v) {
    int best_pos = -1;
    for(size_t i = 1; i < v.size(); i++) {
        best_pos = i;
        for(int j = i - 1; j >= 0; j--) {
            if(s.find({v[i], v[j]}) != s.end()) {
                best_pos = j;
            }
        }
        int temp = v[i];
        v.erase(v.begin() + i);
        v.insert(v.begin() + best_pos, temp);
    } 
}

int main() {
    ifstream fin("input1.txt");
    string line;

    int count = 0;
    
    set<pair<int,int>> pairs;
    
    while(getline(fin, line) and !line.empty()) {
        stringstream ss(line);
        string num1, num2;
        getline(ss, num1, '|');
        getline(ss, num2);
        pairs.insert({stoi(num1), stoi(num2)});
    }
    
    while(getline(fin, line)) {
        vector<int> row;
        stringstream ss(line);
        string num;
        while(getline(ss, num, ',')) {
            row.push_back(stoi(num));
        }
        if(not check_validity(pairs, row)) {
            fix(pairs, row);
            count += row[row.size()/2];
        }
    }
    fin.close();

    cout << count << endl;
}
