#include <bits/stdc++.h>
using namespace std;

void repetitionsTwoPointer(string& s) {
    int i = 0, j = 0;
    int maxLength = 0;
    while(j < s.length()) {
        if(s[i]==s[j]) maxLength = max(maxLength, j - i + 1);
        else i = j;
        j++;
    }
    cout << maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    repetitionsTwoPointer(s);

    return 0;
}