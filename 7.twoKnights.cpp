#include <bits/stdc++.h>
using namespace std;

void twoKnights(int n) {
    for(int i = 1; i <= n; i++) {
        if(i == 1) cout << 0 << endl;
        else if(i == 2) cout << 6 << endl;
        else if(i == 3) cout << 28 << endl;
        else {
            long long edgeLength = i;
            long long totalCombinations = (edgeLength * edgeLength  * (edgeLength * edgeLength - 1)) / 2;
            long long invalidCombinations = (edgeLength - 2) * (2 * 2 + 2 * 3 + (edgeLength - 4) * 4) + (4 * 1 + (edgeLength - 4) * 2);
            // long long invalidCombinations = (4 * 2) + (8 * 3) + ((4 * (edgeLength - 3)) * 4) + ((edgeLength - 4) * 4) * 6 + ((edgeLength - 2) * (edgeLength - 2)) * 8;
            long long validCombinations = totalCombinations - invalidCombinations;
            cout << validCombinations << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    twoKnights(n);

    return 0;
}