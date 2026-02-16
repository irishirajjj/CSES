#include <bits/stdc++.h>

using namespace std;

void naiveSolution(vector<vector<int>>& grid, int n) {

    //TIME COMPLEXITY: 
    // Elements = n^2
    // for each = n^2 log n
    // total = n^4 log n 

    //SPACE COMPLEXITY
    // sets = 2n
    // each set = n
    // total = n^2

    //naive Solution:
    vector<set<int>> cols(n, set<int>());
    //  vector<set<int>> cols(n, set<int>());
    vector<set<int>> rows(n, set<int>());


    for (int i = 0; i < n; i++) {
        int j = i + 1, k = 1;
        while (j < n) {

            // For each column, maintain a set of previosuly added elements. 
            if(rows[i].find(k) == rows[i].end() && cols[j].find(k) == cols[j].end()) {
                grid[i][j] = k;
                // cols[i].insert(k);
                cols[j].insert(k);
                rows[i].insert(k);
                rows[j].insert(k);
                j++;
                k = 1;
            }
            k++;
        }
        //now populate the other half of the diagonal:

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                grid[i][j] = grid[j][i];
            }
        }
    }
}

void xorSolution(vector<vector<int>>& grid, int n) {

    for(int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] =
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    xorSolution(grid, n);
    // naiveSolution(grid, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
};