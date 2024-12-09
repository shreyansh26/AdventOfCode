#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("input1.txt");
    string s;
    fin >> s;

    vector<int> v;
    vector<int> spaces;

    int sz = 0;
    for(int i=0; i<(int)s.size(); i++) {
        if(i % 2 == 0) {
            for(int _=0; _<s[i]-'0'; _++)
                v.push_back(sz);
            sz++;
        }
        else {
            for(int _=0; _<s[i]-'0'; _++) {
                spaces.push_back(v.size());
                v.push_back(-1);
            }
        }
    }

    int k = 0;

    for(int i=v.size()-1; i>=0; i--) {
        if(k < (int)spaces.size() and i > spaces[k] and v[i] != -1) {
            v[spaces[k]] = v[i];
            v[i] = -1;
            k++;
        }
    }

    long long ans = 0;

    for(int i=0; i<(int)v.size(); i++) {
        if(v[i] != -1) {
            ans += (long long)i * v[i];
        }
    }

    cout << ans << endl;
    return 0;
}