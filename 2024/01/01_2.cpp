#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> l1;
    unordered_map<long long, int> l2;

    ifstream fin("input1.txt");
    string line;
    while(getline(fin, line)) {
        stringstream ss(line);
        long long n1, n2;
        ss >> n1 >> n2;
        l1.push_back(n1);
        l2[n2]++;
    }
    fin.close();

    long long ans = 0;
    for(int i = 0; i < l1.size(); i++) {
        ans += l1[i] * l2[l1[i]];
    }

    cout<<ans<<endl;
}
