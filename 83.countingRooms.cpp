#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string>& building, int i, int j) {
    int n = building.size();
    int m = building[0].length();
    if(j >= m || i >= n || i < 0 || j < 0)return;
    if(building[i][j] == '.'){
        building[i][j] = '*';
        dfs(building, i + 1, j);
        dfs(building, i, j + 1);
        dfs(building, i - 1, j);
        dfs(building, i, j - 1);
    }
}

void dfsEnhanced(vector<string>& building, int i, int j) {
    int n = building.size();
    int m = building[0].length();
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    stack<pair<int,int>>st;
    st.push({i,j});
    while(!st.empty()){
        auto [y, x] = st.top();
        st.pop();
        building[y][x] = '*';
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 and nx <m && ny >=0 && ny < n) {
                if(building[ny][nx]=='.'){
                    st.push({ny, nx});
                }
            }
        }
    }
}

void bfsEnhanced(vector<string>& building, int i, int j) {
    int n = building.size();
    int m = building[0].length();
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int,int>>q;
    q.push({i,j});
    building[i][j] = '*';
    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();
        // building[y][x] = '*';
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 and nx <m && ny >=0 && ny < n) {
                if(building[ny][nx]=='.'){
                    building[ny][nx] = '*';
                    q.push({ny, nx});
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> building(n);
    for(int i = 0; i < n; i ++) {
        cin >> building[i];
    }
    int count  = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(building[i][j] == '.'){
                count++;
                bfsEnhanced(building, i, j);
                // dfsEnhanced(building, i, j);
                // dfs(building, i, j);
            }
        }
    }
    cout << count << endl;

    return 0;
}