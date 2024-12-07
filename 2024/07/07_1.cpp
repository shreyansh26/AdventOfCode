#include <bits/stdc++.h>

using namespace std;

int main() { 
    ifstream fin("input1.txt");
    string line;

    long long sum = 0;

    while(getline(fin, line)) {
        stringstream ss(line);
        string t;
        getline(ss, t, ':');

        vector<long long> nums;
        long long num;
        while(ss >> num) {
            nums.push_back(num);
        }

        long long target = stoll(t);

        int n = nums.size();

        vector<vector<long long>> store(n, vector<long long>((1 << n), -1LL));
        
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                store[i][0] = nums[i];
            }
            else {
                for(int j=0; j < (1 << i); j+=2) {
                    if(store[i-1][j/2] != -1) {
                        store[i][j] = store[i-1][j/2] + nums[i];
                        store[i][j+1] = store[i-1][j/2] * nums[i];
                    }
                }
            }
        }

        for(int i=0; i < (1 << n); i++) {
            if(store[n-1][i] == target) {
                sum += target;
                break;
            }
        }
    }
    fin.close();

    cout << sum << endl;
}