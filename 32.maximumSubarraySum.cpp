#include <bits/stdc++.h>

using namespace std;

void prefixSumSolution(const vector<int>& nums) {
    int n = nums.size();
    long long least = 0, sum = 0;
    long long ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        ans = max(ans, sum - least);
        least = min(sum, least);
    }
    cout << ans << endl;
}
void naiveSolution(const vector<int>& nums) {
    int n = nums.size();
    long long ans = LLONG_MIN, curr = 0;
    for(int i = 0; i < n; i++) {
        curr = 0; 
        for(int j = i; j < n; j++) {
            curr += nums[j];
            ans = max(curr, ans);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    naiveSolution(nums);
    // prefixSumSolution(nums);

    return 0;
}