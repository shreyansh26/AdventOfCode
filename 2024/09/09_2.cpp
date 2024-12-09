#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("input1.txt");
    string s;
    fin >> s;

    vector<int> v;
    vector<vector<int>> files;
    vector<vector<int>> spaces;

    int sz = 0;
    for(int i=0; i<(int)s.size(); i++) {
        if(i % 2 == 0) {
            files.push_back({(int)v.size(), sz, s[i]-'0'});
            for(int _=0; _<s[i]-'0'; _++)
                v.push_back(sz);
            sz++;
        }
        else {
            spaces.push_back({(int)v.size(), s[i]-'0'});
            for(int _=0; _<s[i]-'0'; _++) {
                v.push_back(-1);
            }
        }
    }

    for(int i=files.size()-1; i>=0; i--) {
        for(int k=0; k<(int)spaces.size(); k++) {
            int sz_files = files[i][2];
            if(sz_files <= spaces[k][1] and files[i][0] > spaces[k][0]) {
                for(int j=0; j<sz_files; j++) {
                    v[spaces[k][0] + j] = files[i][1];
                    v[files[i][0] + j] = -1;
                }
                spaces[k][0] += sz_files;
                spaces[k][1] -= sz_files;
                break;
            }
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