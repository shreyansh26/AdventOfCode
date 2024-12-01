#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> l1, l2;

    ifstream fin("input1.txt");
    string line;
    while(getline(fin, line)) {
        stringstream ss(line);
        long long n1, n2;
        ss >> n1 >> n2;
        l1.push_back(n1);
        l2.push_back(n2);
    }
    fin.close();

    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    long long ans = 0;
    for(size_t i = 0; i < l1.size(); i++) {
        ans += abs(l1[i] - l2[i]);
    }

    cout<<ans<<endl;
}
