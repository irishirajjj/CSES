#include <bits/stdc++.h>
using namespace std;

void increasingArray(int n, vector<int>& nums) {
    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(nums[i+1] < nums[i]) {
            ans += nums[i] - nums[i+1];
            nums[i+1] = nums[i];
        }
    }

    cout << ans;
}

void increasingArrayWithoutModification(int n, vector<int>& nums) {
    long long ans = 0;
    int curr = 0;
    for(int i = 0; i < n - 1; i++) {
        if( i == 0) curr = nums[0];
        if(nums[i+1] < curr) {
            ans += curr - nums[i+1];
        }
        else curr = nums[i+1];
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    increasingArrayWithoutModification(n, nums);
    // increasingArray(n, nums);

    return 0;
}