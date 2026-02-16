#include <bits/stdc++.h>

using namespace std;

void fastMessageRoute(const vector<vector<int>>& adj, int comp) {
    int start = 1, end = comp;
    vector<bool> visited(comp + 1, false);
    vector<int> parent(comp + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int currComp = q.front();
        q.pop();
        for(int c : adj[currComp]) {
            if(!visited[c]){
                q.push(c);
                visited[c] = true;
                parent[c] = currComp;
                if(c == end) {//Now, find the path
                    break;
                }
            }
        }
    }

    //Let's build path now: 
    vector<int>path;
    path.push_back(end);
    while(end != 1){
        end = parent[end];
        path.push_back(end);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto computer : path) cout << computer << " ";
    return;

    cout << "IMPOSSIBLE";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int comp, conn;
    cin >> comp >> conn;
    vector<vector<int>> adj(comp+1);
    for(int i = 0; i < conn; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fastMessageRoute(adj, comp);

    return 0;
}