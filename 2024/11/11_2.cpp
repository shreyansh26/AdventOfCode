#include <bits/stdc++.h>

using namespace std;

int count_digits(long long n) {
    int cnt = 0;
    while(n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

void process(unordered_map<long long, long long> &mp) {
    unordered_map<long long, long long> new_mp;

    for(auto it: mp) {
        long long num = it.first;
        long long count = it.second;
        int digits = count_digits(num);

        if(num == 0) {
            new_mp[1] += count;
        }
        else if(digits % 2 == 0) {
            int mid = digits / 2;

            long long num1 = num / (long long)pow(10, mid);
            long long num2 = num % (long long)pow(10, mid);
            
            new_mp[num1] += count;
            new_mp[num2] += count;
        }
        else {
            new_mp[num * 2024] += count;
        }
    }

    mp = new_mp;
}

int main() {
    ifstream file("input1.txt");
    string line;

    while(getline(file, line)) {
        vector<long long> v;
        stringstream ss(line);
        long long num;
        while(ss >> num) {
            v.push_back(num);
        }

        unordered_map<long long, long long> mp;
        for(auto num: v) {
            mp[num]++;
        }

        for(int i=0; i<75; i++) {
            process(mp);
        }

        long long tot = 0;
        for(auto it: mp) {  
            tot += it.second;
        }
        cout << tot << endl;
    }
    return 0;
}