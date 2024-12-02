#include <bits/stdc++.h>

using namespace std;

bool is_valid(const vector<long long> &nums) {
    if(nums.size() <= 1) 
        return true;
    
    bool increasing = nums[1] > nums[0];
    
    for(size_t i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i-1];
        if((increasing and diff <= 0) || (!increasing and diff >= 0) or abs(diff) < 1 or abs(diff) > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("input1.txt");
    string line;
    int cnt = 0;

    while(getline(fin, line)) {
        stringstream ss(line);
        vector<long long> nums;
        long long num;
        while(ss >> num) {
            nums.push_back(num);
        }

        cnt += is_valid(nums);
    }
    fin.close();

    cout << cnt << endl;

}