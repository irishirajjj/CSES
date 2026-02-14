#include <bits/stdc++.h>
using namespace std;

void missingNumber(int n, vector<int>& v) {
    vector<int> nums (n+1, 1);
    for(int i=0; i < n-1; i++){
        nums[v[i]]=0;
    }
    int ans = -1;
    int i = 1;
    while(!nums[i])i++;
    cout << i;
}

void missingNumberUsingSet( int n, vector<int> & v) {
    unordered_set<int> s;
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for(int i = 0; i < v.size(); i++) {
        s.erase(v[i]);
    }
    int ans = *s.begin();
    cout << ans;
}

void missingNumberUsingXOR( int n, vector<int>& v) {
    int xor1 = 0; 
    for( int i = 1; i <= n; i++) {xor1 ^= i;}
    for( int i = 0; i < v.size(); i++) {xor1 ^= v[i];}
    cout << xor1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>v(n-1,0);
    for(int i = 0; i < n - 1; i++) {
        int curr;
        cin >> curr;
        v[i] = curr;
    }
    missingNumberUsingXOR(n, v);  //Time: O(n) 2 pass, Space: O(1)
    // missingNumberUsingSet(n, v); //Time: O(n) 2pass, Space O(n)
    // missingNumber(n, v);// Time: O(n) two pass, Space O(n)

    return 0;
}