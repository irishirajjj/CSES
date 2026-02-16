#include <bits/stdc++.h>

using namespace std;

int ferrisWheel(int n, int x, vector<int>& weights) {
    sort(weights.begin(), weights.end());
    int gondolas = 0;
    int i = 0, j = n - 1;
    while(i < j) {
        if(weights[i] + weights[j] <= x) {
            gondolas++;
            i++;
            j--;
        }
        else {
            gondolas++;
            j--;
        }
    }
    if(i == j)gondolas++;
    return gondolas;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    int gondolas = ferrisWheel(n, x, weights);

    cout << gondolas << endl;

    return 0;
}