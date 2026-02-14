#include <bits/stdc++.h>
using namespace std;

void numberSpiralMathsSolution(int n, vector<pair<int,int>>& coordinates) {
    for(int i = 0; i < n; i++) {
        long long y = coordinates[i].first;
        long long x = coordinates[i].second;
        long long edge = max(x, y);
        long long edgeRepresentativeNumber = edge * edge;
        long long edgeRepresentativeXCoordinate, edgeRepresentativeYCoordinate;
        long deviation = 0;
        if(edge & 1) {
            edgeRepresentativeYCoordinate = 1;
            edgeRepresentativeXCoordinate = edge;
            deviation = y - 1 + edge - x;
        }
        else {
            edgeRepresentativeYCoordinate = edge;
            edgeRepresentativeXCoordinate = 1;
            deviation = edge - y + x - 1;
        }
        cout << edgeRepresentativeNumber - deviation << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<pair<int,int>> coordinates;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        coordinates.push_back({y,x});
    }
    numberSpiralMathsSolution(n, coordinates);
    return 0;
}