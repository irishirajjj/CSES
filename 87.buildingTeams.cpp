#include <bits/stdc++.h>

using namespace std;

void divideFriends(vector<vector<int>>& adj, int pupils, vector<int>& ans) {
    for(int i = 1; i <= pupils; i ++) {
        if(ans[i]== -1){
            queue<pair<int,int>>q;
            q.push({i, 1});
            ans[i] = 1;
            int findTeam[3] = {-1, 2, 1}; // instead of this
            // USE  NEW TEAM = 3 - TEAP
            // TO FLIP BETWEEN 1 AND 2. 
            while(!q.empty()) {
                auto [curr, team] = q.front();
                q.pop();
                for(auto p : adj[curr]){
                    if(ans[p] == team){
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    }
                    else if(ans[p] == -1) {
                        q.push({p,findTeam[team]});
                        ans[p] = findTeam[team];
                    }
                }
            }
        }
    }
    for(int i = 1; i <= pupils; i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int pupils, friendships;
    cin >> pupils >> friendships;
    vector<vector<int>> adj(pupils + 1);
    for(int i = 0; i < friendships; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans(pupils+1, -1);
    divideFriends(adj, pupils, ans);

    return 0;
}