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

vector<long long> process(vector<long long> &v) {
    int sz = v.size();
    vector<long long> ans;

    for(int i = 0; i < sz; i++) {
        long long num = v[i];
        int digits = count_digits(num);
        if(num == 0) {
            ans.push_back(1);
        }
        else if(digits % 2 == 0) {
            int mid = digits / 2;

            long long num1 = num / (long long)pow(10, mid);
            long long num2 = num % (long long)pow(10, mid);
            ans.push_back(num1);
            ans.push_back(num2);
        }
        else {
            ans.push_back(num * 2024);
        }
    }
    return ans;
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

        for(int i=0; i<25; i++) {
            v = process(v);
        }

        cout << v.size() << endl;
    }
    return 0;
}