#include <bits/stdc++.h>

using namespace std;

int naiveSolution(vector<int>& nums, int n) {
    //Time: O(n), Space: O(n)
    unordered_map<int, int> mp;
    mp.reserve(n);
    for(int num : nums) mp[num]++;
    return mp.size();
}
int setSolution(vector<int>& nums, int n) {
    //Time: O(n), Space: O(n)
    unordered_set<int>s;
    s.reserve(n);
    for(int& num : nums) s.insert(num);
    return s.size();
}
int sortAndCheck(vector<int>& nums, int n) {
    //Time: O(n), Space O(1), but auxiliary space of sorting. 
    sort(nums.begin(), nums.end());
    if(n==0) return 0;
    int count = 1;
    for(int i = 0; i < n-1; i++) {
        if(nums[i] != nums[i+1])count++;
    }
    return count;
}
int oneLiner(vector<int>&nums, int n) {
    return unordered_set(nums.begin(), nums.end()).size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    int ans = oneLiner(nums, n);
    // int ans = sortAndCheck(nums, n);
    // int ans = setSolution(nums, n);
    // int ans = naiveSolution(nums, n);

    cout << ans;

    return 0;
}