#include <bits/stdc++.h>
using namespace std;

void beautifulPermutation(int n) {
    if (n == 1) cout<< 1;
    else if( n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        vector<int> beautifulPermutations;
        for(int i = 2; i <=n ; i+=2) {
            beautifulPermutations.push_back(i);
        }
        for(int i = 1; i <=n ; i+=2) {
            beautifulPermutations.push_back(i);
        }
        for(int i = 0; i<beautifulPermutations.size(); i++) {
            cout << beautifulPermutations[i] << " ";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    beautifulPermutation(n);

    return 0;
}