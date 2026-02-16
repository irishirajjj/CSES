#include <bits/stdc++.h>

using namespace std;

int MODULO = 1000000007;

long long diceCombinationsRecursive(int n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return 1;
    long long ans = 0;
    for(int i = n-1; i >= n -6; i--) {
        ans = (ans + diceCombinationsRecursive(i) % MODULO) % MODULO;
    }
    return ans % MODULO;
}
long long diceCombinationTopDown(int n, vector<long long>& sol) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(sol[n] != -1)return sol[n];
    long long ans = 0;
    for(int i = n-1; i >= n -6; i--) {
        long long temp = 0;
        temp = diceCombinationTopDown(i,sol);
        ans = (ans + temp) % MODULO;
    }
    sol[n] = ans;
    return ans;
}
long long diceCombinationBottomUp(int n) {
    vector<long long> memo(n+1, 0);
    memo[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j ++){
            if(i - j >=0){
                memo[i] = (memo[i]+ memo[i-j])% MODULO;
            }
        }
    }
    return memo[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> sol(n+1, -1);
    long long ans = diceCombinationBottomUp(n);
    // long long ans = diceCombinationTopDown(n, sol);
    // long long ans = diceCombinationsRecursive(n);
    cout << ans << endl;

    return 0;
}