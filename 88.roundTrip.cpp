#include <bits/stdc++.h>

using namespace std;

void cycleDetectionDFS(const vector<vector<int>>& adj, int cities) {
    vector<int>parent(cities + 1, -1);
    vector<bool>visited(cities + 1, false);
    for(int i = 1; i <= cities; i++) {
        if(!visited[i]) {
            stack<int>st;
            st.push(i);
            visited[i] = true;
            while(!st.empty()) {
                int curr = st.top();
                st.pop();
                for(auto child : adj[curr]) {
                    if(!visited[child]) {
                        st.push(child);
                        visited[child] = true;
                        parent[child] = curr;
                    }
                    else if (child != parent[curr]) { // back edge → cycle
                        
                        vector<int> loop;
                        int x = curr;
                        loop.push_back(child); 
                        while (x != child && x != -1) {
                            loop.push_back(x);
                            x = parent[x];
                        }
                        loop.push_back(child); 
                        cout << loop.size() << endl;
                        for (int city : loop) cout << city << " ";
                        return; 
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cities, roads;
    cin >> cities >> roads;
    vector<vector<int>> adj(cities + 1);
    for(int i = 0; i < roads; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cycleDetectionDFS(adj, cities);

    // Your code here

    return 0;
}