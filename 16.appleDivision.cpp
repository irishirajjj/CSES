#include <bits/stdc++.h>
using namespace std;
int appleDivision(int n, vector<int>& apples) {
    int total = 1 << n;
    long long ans = INT_MAX;
    long long totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += apples[i];
    for(int i = 0; i < total; i++) {
        long long currAns = 0;
        int j = 1;
        int x = 0;
        while (x < n) {
            if(i & j) currAns += apples[x];
            j = j << 1;
            x++;
        }
        ans = min(max(2 * currAns - totalSum, totalSum - 2 * currAns), ans);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> apples(n, 0);
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        apples[i] = temp;
    }
    int result = appleDivision(n, apples);
    cout << result << endl;
    return 0;
}