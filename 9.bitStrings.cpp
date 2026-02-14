#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;
int recursivePower(int a, int n) {
    if(n == 0)return 1;
    if(n == 1)return a % MOD;
    long long half = recursivePower(a, n/2) % MOD;
    long long result = (half * half) % MOD;

    if(n & 1) result = (result * a) % MOD;
    return result;
}
void bitStringsRecurive(int n) {
    int ans = recursivePower(2, n);
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bitStringsRecurive(n);

    return 0;
}