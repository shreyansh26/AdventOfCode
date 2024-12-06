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
        if(check_validity(pairs, row)) {
            count += row[row.size()/2];
        }
    }
    fin.close();

    cout << count << endl;
}
