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

bool can_make_valid(vector<long long>& nums, const function<bool(vector<long long>&)>& isValid) {
    if(isValid(nums)) 
        return true;
    
    // Try removing one number at a time
    for(size_t i=0; i<nums.size(); i++) {
        int temp = nums[i];
        nums.erase(nums.begin() + i);
        
        if(isValid(nums)) {
            nums.insert(nums.begin() + i, temp); 
            return true;
        }
        
        nums.insert(nums.begin() + i, temp);
    }
    
    return false;
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


        cnt += can_make_valid(nums, is_valid);
    }
    fin.close();

    cout << cnt << endl;

}