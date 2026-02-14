#include <bits/stdc++.h>
using namespace std;
string palindromeReorder (string& s) {
    int n = s.length();
    vector<int> frequencyArray(26, 0);
    for(int i = 0; i < n; i++) {
        frequencyArray[s[i] - 'A']++;
    }
    string result = "";
    result.reserve(n);
    int oddCount = 0;
    int oddIndex = -1;
    for(int i = 0; i < 26; i++) {
        if (frequencyArray[i] & 1) {
            oddCount++;
            oddIndex = i;
        }
        if (oddCount > 1)return "NO SOLUTION";
        // string curr;
        //result += (frequencyArray[i]/2, 'A' + i); dont do this.
        result.append(frequencyArray[i]/2, 'A' + i);

    }
    string reversed = result;
    reverse(reversed.begin(), reversed.end());
    if(oddCount) result += 'A' + oddIndex;
    result += reversed;

    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string result = palindromeReorder(s);
    cout << result << endl;
    return 0;
}