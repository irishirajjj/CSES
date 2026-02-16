#include <bits/stdc++.h>

using namespace std;

void bfs(vector<string>& building, int i, int n, int j, int m, string& path) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dd[4] = {'D', 'U', 'L', 'R'};
    vector<int> parent(n * m, -1);
    queue<int>q;
    q.push(i * m + j);
    while(!q.empty()) {
        int curr = q.front();
        int x = curr / m;
        int y = curr % m;
        q.pop();
        // if(building[x][y] == '*')building[x][y]='.';
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >=0 && nx < n && ny >=0 && ny < m) {
                if(building[nx][ny] =='.') {
                    q.push(nx * m + ny);
                    building[nx][ny] = '*';
                    parent[nx * m + ny] = x * m + y;
                }
                if(building[nx][ny] =='B') {
                    parent[nx * m + ny] = x * m + y;
                    int end = nx * m + ny;
                    int start = i * m + j;
                    string reversePath = "";
                    while(end != start) {
                        int currParent = parent[end];
                        int endx = end / m; 
                        int endy = end % m;
                        int currPx = currParent / m;
                        int currPy = currParent %m;
                        if(endy - currPy == 1)reversePath += "R";
                        else if(endy - currPy == -1)reversePath += "L";
                        else if(endx - currPx == 1)reversePath += "D";
                        else if(endx - currPx == -1)reversePath += "U";
                        end = currParent;
                    }
                    reverse(reversePath.begin(), reversePath.end());
                    path = reversePath;
                    return;
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
    for(int i = 0; i < n; i++) {
        cin >> building[i];
    }
    string path ="";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(building[i][j]=='A'){
                bfs(building, i, n, j, m, path);
            }
        }
    }
    if(path.length()){
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }
    else cout << "NO" << endl;

    return 0;
}