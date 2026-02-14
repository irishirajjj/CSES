#include <bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int totalMoves = 0;

    //First move n-1 plates to the reserve tower
    totalMoves += towerOfHanoi(n-1);

    //Then move the largest plat to the target tower
    totalMoves += 1;

    //Then move the rest n-1 plates from the reserve tower to the target tower
    totalMoves += towerOfHanoi(n-1);

    return totalMoves;
}

void printAlltheHanoiMoves(int n, int currentTower, int reserveTower, int targetTower) {
    if (n == 0) return;

    //First move n-1 plates to the reserve tower
    printAlltheHanoiMoves(n-1, currentTower, targetTower, reserveTower);

    //Then move the largest plate to the target tower
    cout << currentTower << " " << targetTower << endl;

    //Then move the rest n-1 plates from the reserve tower to the target tower
    printAlltheHanoiMoves(n-1, reserveTower, currentTower, targetTower);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long totalMoves = 1;
    totalMoves = (totalMoves << n) - 1;
    // int totalMoves = towerOfHanoi(n);
    cout << totalMoves << endl;
    printAlltheHanoiMoves(n, 1, 2, 3);

    return 0;
}