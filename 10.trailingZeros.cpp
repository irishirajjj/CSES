#include <bits/stdc++.h>
using namespace std;

int trailingZerosNaive(int n) {
    long long factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    int result = 0;
    while(factorial % 10 == 0) {
        result++;
        factorial /= 10;
    }
    return result;
}
int trailingZeros(int n) {
    int result = 0;
    int multipleOfFive = 5;
    while (n >= multipleOfFive) {
        result += n / multipleOfFive;
        multipleOfFive *= 5;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int res = trailingZeros(n);
    // int res = trailingZerosNaive(n); //Time O(n), Space O(1)
    cout << res;

    return 0;
}