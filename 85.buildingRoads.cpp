#include <bits/stdc++.h>

using namespace std;

void buildRoads(const vector<vector<int>>& roads, int c) {
    vector<bool> visited (c + 1, false);
    vector<int> leadCities;
    for(int i = 1; i <= c; i++) {
        if(!visited[i]) {
            leadCities.push_back(i);
            //Now we will have to run bfs or dfs from city i 
            queue<int>q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int currCity = q.front();
                q.pop();
                for(int city : roads[currCity]) {//adjoining cities of i
                    if(!visited[city]){
                        q.push(city);
                        visited[city] = true;
                    }
                }
            }
        }
    }
    int roadsToBuild = leadCities.size() - 1;
    cout << roadsToBuild << endl;
    for(int i = 0; i < roadsToBuild; i++) {
        cout << leadCities[i] << " " << leadCities[i + 1] << endl;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, r;
    cin >> c >> r;
    vector<vector<int>> roads(c + 1);
    for(int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    buildRoads(roads, c);

    return 0;
}