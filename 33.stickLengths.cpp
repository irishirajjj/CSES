#include <bits/stdc++.h>

using namespace std;

void stickLengthsOneIteration (vector<int>& sticks) {
    int n = sticks.size();
    long long ans = 0;
    if(n == 0) {cout << ans << endl; return;}
    
    sort(sticks.begin(), sticks.end());
    int x = n / 2;
    int stickLength = sticks[x];
    for(int i = 0; i < n; i++) {
        ans += abs(sticks[i] - stickLength);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sticks(n,0);
    for(int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    stickLengthsOneIteration(sticks);

    // Your code here

    return 0;
}