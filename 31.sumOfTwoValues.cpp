#include <bits/stdc++.h>

using namespace std;

void naiveTwoSum(const vector<int>& nums, int x) {
    int n = nums.size();
    pair<int, int> p = {-1, -1};
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == x){
                p.first = i + 1;
                p.second = j + 1;
                break;
            }
        }
    }
    if(p.first == -1) cout << "IMPOSSIBLE" << endl;
    else cout << p.first << " " << p.second << endl;
}
void twoSumOptimized(const vector<int>& nums, int x) {
    int n = nums.size();
    vector<pair<int,int>> numsWithIndex;
    for(int i = 0; i < n; i++) {
        numsWithIndex.push_back({nums[i], i + 1});
    }
    sort(numsWithIndex.begin(), numsWithIndex.end());
    pair<int, int> ans = {-1, -1};
    int i = 0, j = n - 1;
    while(i < j) {
        if(numsWithIndex[i].first + numsWithIndex[j].first == x) {
            ans.first = numsWithIndex[i].second;
            ans.second = numsWithIndex[j].second;
            break;
        }
        else if(numsWithIndex[i].first + numsWithIndex[j].first < x) i++;
        else j --;
    }
    if(ans.first == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans.first << " " << ans.second << endl;
}
void twoSumHashMap(const vector<int>& nums, int x) {
    int n = nums.size();
    unordered_map<int,int> mp;
    mp.reserve(n);
    mp.max_load_factor(0.7);
    pair<int,int> ans = {-1, -1};
    for(int i = 0; i < n; i++){
        if(mp.find(x-nums[i])!=mp.end()){
            ans.first = mp[x-nums[i]];
            ans.second = i + 1;
            break;
        }
        else mp[nums[i]] = i + 1;
    };
    if(ans.first == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans.first << " " << ans.second << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; 
    cin >> n >> x;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    twoSumHashMap(nums, x);
    // twoSumOptimized(nums, x);
    // naiveTwoSum(nums, x);


    return 0;
}