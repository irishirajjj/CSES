#include <bits/stdc++.h>
using namespace std;

vector<string> coinPiles(int n, vector<pair<int,int>>& piles) {
    int sum = 0, difference = 0;
    vector<string> result; 
    for( int i = 0; i < n; i++) {
        int pile1 = piles[i].first;
        int pile2 = piles[i].second;
        sum = pile1 + pile2;
        difference = pile1 > pile2 ? pile1 - pile2 : pile2 - pile1;
        if(sum % 3 == 0 && difference <= sum / 3) result.push_back("YES");
        else result.push_back("NO");
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> piles;
    for(int i = 0; i < n; i++) {
        int pile1, pile2;
        cin >> pile1 >> pile2;
        piles.push_back({pile1, pile2});
    }
    
    vector<string> result = coinPiles(n, piles);

    for(int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}