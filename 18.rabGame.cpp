#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> raabGameSequences(int n, int a, int b) {
    vector<int> playerAMoves;
    vector<int> playerBMoves;
    int wins = a + b;
    int draws = n - wins;
    for (int i = 1; i <= draws; i++) {
        playerAMoves.push_back(i);
        playerBMoves.push_back(i);
    }
    for (int i = 0; i < b; i++) {
        playerAMoves.push_back(i + draws + 1);
        playerBMoves.push_back(i + a + draws + 1);
    }
    
    for (int i = 0; i < a; i++) {
        playerAMoves.push_back(i + draws + b + 1);
        playerBMoves.push_back(i + draws + 1);
    }
    return {playerAMoves, playerBMoves};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<vector<int>> games(t, vector<int>(3));
    for(int i = 0; i < t; i++) {
        cin >> games[i][0] >> games[i][1] >> games[i][2];
    }
    for(int i = 0; i < t; i++) {
        int n = games[i][0], a = games[i][1], b = games[i][2];
        int wins = a + b;
        int draws = n - wins;
        if( wins > n || (a != 0 && b == 0) || (a == 0 && b != 0)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            vector<vector<int>> ans = raabGameSequences(n, a, b);
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < n; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}