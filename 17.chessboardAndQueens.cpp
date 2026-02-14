#include <bits/stdc++.h>
using namespace std;

int countQueenPlacements(vector<string>& chessBoard, int row) {
    //If we have reached the last row, return the number of places where we can place the queen in the last row
    int result = 0;
    if(row == 7) {
        for(int i = 0; i < 8; i++) if(chessBoard[7][i]=='.')result++;
        return result;
    }
    // iterate the current row.
    // If any position is avaiable, place the queen at that positon.
    // block all the positions respective to it on subsequent rows.
    // call this function to return the no. of ways this condition will work out.
    // try this for all the avaialbe positions in the current row.

    for(int i = 0; i < 8; i++) {
        // iterate the current row.
        // If any position is avaiable, place the queen at that positon.
        if(chessBoard[row][i] == '.') {
            //block all respective positions in subsequent rows.
            for(int j = row + 1, k = i - 1; j < 8 && k >=0 ; j++, k--){ // left dia
                if(chessBoard[j][k] == '.') chessBoard[j][k] = 'a' + row;
            }
            for(int j = row + 1, k = i; j < 8 && k >=0 ; j++){ // down
                if(chessBoard[j][k] == '.') chessBoard[j][k] = 'a' + row;
            }
            for(int j = row + 1, k = i + 1; j < 8 && k < 8 ; j++, k++){ // right dia
                if(chessBoard[j][k] == '.') chessBoard[j][k] = 'a' + row;
            }
            result += countQueenPlacements(chessBoard, row+1);
            //Reset the values
            for(int j = row + 1, k = i - 1; j < 8 && k >=0 ; j++, k--){ // left dia
                if(chessBoard[j][k] == 'a' + row) chessBoard[j][k] = '.';
            }
            for(int j = row + 1, k = i; j < 8 && k >=0 ; j++){ // down
                if(chessBoard[j][k] == 'a' + row) chessBoard[j][k] = '.';
            }
            for(int j = row + 1, k = i + 1; j < 8 && k < 8 ; j++, k++){ // right dia
                if(chessBoard[j][k] == 'a' + row) chessBoard[j][k] = '.';
            }
        }
    }
    return result;
}

bool col[8], dia1[15], dia2[15];
int countQueenPlacementsEfficient(vector<string>& chessBoard, int row) {
    if(row == 8) return 1;
    int count = 0;
    for(int i = 0; i < 8; i ++) {
        if(chessBoard[row][i] == '*') continue;
        if (col[i] || dia1[row + i] || dia2[row + 7 - i]) continue;

        col[i] = dia1[row + i] = dia2[row + 7 - i] = true;
        count += countQueenPlacementsEfficient(chessBoard, row + 1);
        col[i] = dia1[row + i] = dia2[row + 7 - i] = false;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> chessBoard(8);
    for(int i = 0; i < 8; i++) {
        cin >> chessBoard[i];
    }
    int row = 0;
    int ans = countQueenPlacementsEfficient(chessBoard, row);
    // int ans = countQueenPlacements(chessBoard, row);
    cout << ans << endl;

    return 0;
}